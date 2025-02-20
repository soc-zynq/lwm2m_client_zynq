#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <lwm2m_server_zynq.hpp>

namespace lw2m_server {

Lwm2mServerZynq::Lwm2mServerZynq() { lwm2m_context = lwm2m_init(nullptr); }

Lwm2mServerZynq::~Lwm2mServerZynq() {
    stop();
    if (lwm2m_context) {
        lwm2m_close(lwm2m_context);
    }
}

int Lwm2mServerZynq::start() {
    if (create_server() != 0) {
        return -1;
    }

    return pthread_create(&server_thread, nullptr, server_thread_func, this);
}

void Lwm2mServerZynq::stop() {
    close_server();
    pthread_join(server_thread, nullptr);
}

void* Lwm2mServerZynq::server_thread_func(void* arg) {
    auto* server = static_cast<Lwm2mServerZynq*>(arg);
    while (server->server_fd >= 0) {
        server->handle_connection();
    }
    return nullptr;
}

int Lwm2mServerZynq::create_server() {
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0) {
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(5683);  // Standard CoAP port

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        close(server_fd);
        server_fd = -1;
        return -1;
    }

    return 0;
}

void Lwm2mServerZynq::close_server() {
    if (server_fd >= 0) {
        close(server_fd);
        server_fd = -1;
    }
}

int Lwm2mServerZynq::handle_connection() {
    uint8_t buffer[1024];
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    ssize_t n = recvfrom(server_fd, buffer, sizeof(buffer), 0,
                         (struct sockaddr*)&client_addr, &client_len);

    if (n > 0) {
        // Process the received data through LwM2M stack
        lwm2m_handle_packet(lwm2m_context, buffer, n, nullptr);
    }

    return n;
}

}  // namespace lw2m_server
#include <signal.h>

#include <iostream>
#include <lwm2m_server_zynq.hpp>

static bool running = true;

void signal_handler(int signo) {
    if (signo == SIGINT) {
        running = false;
    }
}

int main() {
    signal(SIGINT, signal_handler);

    std::cout << "Starting LwM2M server..." << std::endl;

    lw2m_server::Lwm2mServerZynq server;

    if (server.start() != 0) {
        std::cerr << "Failed to start server" << std::endl;
        return 1;
    }

    std::cout << "Server started. Press Ctrl+C to exit." << std::endl;

    while (running) {
        sleep(1);
    }

    std::cout << "Stopping server..." << std::endl;
    server.stop();

    return 0;
}

#ifndef LWM2M_SERVER_ZYNQ_H
#define LWM2M_SERVER_ZYNQ_H

#include <liblwm2m.h>
#include <pthread.h>

#include <vector>

namespace lw2m_server {

class Lwm2mServerZynq {
   public:
    Lwm2mServerZynq();
    ~Lwm2mServerZynq();

    int start();
    void stop();

   private:
    lwm2m_context_t* lwm2m_context = nullptr;
    lwm2m_object_t** objArray = nullptr;
    uint16_t objCount = 0;
    int server_fd = -1;
    pthread_t server_thread;

    static void* server_thread_func(void* arg);
    int create_server();
    void close_server();
    int handle_connection();
};

}  // namespace lw2m_server

#endif  // LWM2M_SERVER_ZYNQ_H
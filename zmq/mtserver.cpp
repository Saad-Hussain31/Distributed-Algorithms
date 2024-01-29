#include <pthread.h>
#include <unistd.h>
#include <cassert>
#include <string>
#include <iostream>
#include <thread>
#include <any>
#include <zmq.hpp>

std::any worker_routine(void* arg) {
    zmq::context_t* ctx = (zmq::context_t*) arg;
    zmq::socket_t socket(*ctx, ZMQ_REP);
    socket.connect("inproc://workers");

    while(true) {
        zmq::message_t request;
        socket.recv(&request);
        std::cout << "Received request: [" << (char*) request.data() << "]" << std::endl;
        sleep(1);

        std::string reply_data = "World";
        zmq::message_t reply(reply_data.size());
        std::copy(reply_data.begin(), reply_data.end(), static_cast<char*>(reply.data()));
        socket.send(reply);
    }
    return nullptr;
}

int main() {
    zmq::context_t ctx(1);
    zmq::socket_t clients(ctx, ZMQ_ROUTER);
    clients.bind("tcp://localhost:5555");

    zmq::socket_t workers(ctx, ZMQ_DEALER);
    workers.bind("inproc://workers");

    
    std::vector<std::thread> worker_threads;
    for (int thread_nbr = 0; thread_nbr != 5; ++thread_nbr) {
        worker_threads.emplace_back(worker_routine, &ctx);
    }

    std::cout << "Main: Workers created." << std::endl;

    for (auto& thread : worker_threads) {
        thread.join();
    }


    //  Connect work threads to client threads via a queue
    zmq::proxy (static_cast<void*>(clients),
                static_cast<void*>(workers),
                nullptr);
    

    return 0;

}
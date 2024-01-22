#include "zhelpers.hpp"
#include <chrono>

int main(int argc, char* argv[]) {
    zmq::context_t ctx(1);

    zmq::socket_t receiver(ctx, ZMQ_PULL);
    receiver.connect("tcp://localhost:5558");

    zmq::socket_t controller(ctx, ZMQ_PUB);
    receiver.connect("tcp://localhost:5559");

    s_recv(receiver);

    // Start our clock now
    auto tstart = std::chrono::high_resolution_clock::now();

    // Process 10 confirmations
    for (int task_nbr = 0; task_nbr < 10; ++task_nbr) {
        s_recv(receiver);

        std::cout << (task_nbr % 10 == 0 ? ":" : ".");
    }

    // Calculate and report duration of batch
    auto tend = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart);

    std::cout << "\nTotal elapsed time: " << duration.count() << " msec\n" << std::endl;

    s_send(controller, std::string("KILL"));

    sleep(1);
    return 0;
}
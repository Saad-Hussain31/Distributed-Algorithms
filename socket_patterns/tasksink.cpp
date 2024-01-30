/*
  Adds pub-sub flow to send kill signal to workers and calculate task processing time
RUN:
./tasksink 5558 5559&
./tasksink 5561 5562&
./tasksink 5564 5565&
*/

#include "zhelpers.hpp"
#include <chrono>

int main(int argc, char* argv[]) {

    if (argc != 3){
        std::cerr << "Usage: " << argv[0] << " <receiver_port> <controller_port>\n";
        return 1;
    }

    int receiver_port = std::stoi(argv[1]);
    int controller_port = std::stoi(argv[2]);
    zmq::context_t ctx(1);

    zmq::socket_t receiver(ctx, ZMQ_PULL);
    receiver.bind("tcp://*:" + std::to_string(receiver_port));

    zmq::socket_t controller(ctx, ZMQ_PUB);
    receiver.bind("tcp://*:" + std::to_string(controller_port));

    s_recv(receiver);

    auto tstart = std::chrono::high_resolution_clock::now();

    // Process 100 confirmations
    for (int task_nbr = 0; task_nbr < 100; ++task_nbr) {
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
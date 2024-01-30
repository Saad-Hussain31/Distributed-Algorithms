/*
 This program continuously receives workload tasks from the 'receiver' socket,
 processes each task by sleeping for a duration specified in the workload, and forwards the tasks to the 'worker' socket.
 RUN:
  ./taskwork 5557 5558 5559&
  ./taskwork 5560 5561 5562&
  ./taskwork 5563 5564 5565&
*/

#include "zhelpers.hpp"
#include <string>

int main (int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <receiver_port> <sender_port> <controller_port>\n";
        return 1;
    }

    int receive_port = std::stoi(argv[1]);
    int sender_port = std::stoi(argv[2]);
    int controller_port = std::stoi(argv[3]);

    zmq::context_t ctx(1);

    //takes(pulls) tasks from sink socket 
    zmq::socket_t receiver(ctx, ZMQ_PULL);
    receiver.connect("tcp://localhost:" + std::to_string(receive_port));

    //worker(sender) process 
    zmq::socket_t worker(ctx, ZMQ_PUSH);
    worker.connect("tcp://localhost:" + std::to_string(sender_port));

    zmq::socket_t controller(ctx, ZMQ_SUB);
    controller.connect("tcp://localhost:" + std::to_string(controller_port));
    controller.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    std::vector<zmq::pollitem_t> items  = { 
        {receiver, 0 , ZMQ_POLLIN, 0},
        {controller, 0, ZMQ_POLLIN, 0}
    };

    while(1) {
        zmq::message_t msg;
        zmq::poll(items.data(), items.size() , -1);

        if(items[0].revents & ZMQ_POLLIN) { //Inside the loop, it checks if there are any events (ZMQ_POLLIN) on the socket using the revents field.
            receiver.recv(&msg);

            int workload;
            std::string data(static_cast<char*>(msg.data()), msg.size());
            std::istringstream iss(data);
            iss >> workload;

            s_sleep(workload);

            msg.rebuild();
            worker.send(msg);

            std::cout << "." << std::endl;
        }
        if (items[1].revents & ZMQ_POLLIN) {
        	std::cout << std::endl;
            break; //when there is activity on the controller socket, exit the loop                    
        }
    }
    return 0;
}
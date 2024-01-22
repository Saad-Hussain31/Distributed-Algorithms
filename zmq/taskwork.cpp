#include "zhelpers.hpp"
#include <string>

int main (int argc, char *argv[]) {
    zmq::context_t ctx(1);

    //worker process
    zmq::socket_t worker(ctx, ZMQ_PUSH);
    worker.connect("tcp://localhost:5558");

    //takes(pulls) tasks from sink socket 
    zmq::socket_t receiver(ctx, ZMQ_PULL);
    receiver.connect("tcp://localhost:5557");

    zmq::socket_t controller(ctx, ZMQ_SUB);
    controller.connect("tcp://localhost:5559");
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

            std::cout << "." << std::flush;
        }
        if (items[1].revents & ZMQ_POLLIN) {
        	std::cout << std::endl;
            break; //when there is activity on the controller socket, exit the loop                    
        }
    }
    return 0;
}
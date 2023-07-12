#include "zhelpers.hpp"


int main (int argc, char *argv[])
{
    //  Prepare our context and sockets
    zmq::context_t context(1);
    zmq::socket_t frontend (context, ZMQ_ROUTER);
    zmq::socket_t backend (context, ZMQ_DEALER);

    frontend.bind("tcp://*:5559");
    backend.bind("tcp://*:5560");

    //  Initialize poll set
    zmq::pollitem_t items [] = {
        { frontend, 0, ZMQ_POLLIN, 0 }, //item 1 to be polled
        { backend, 0, ZMQ_POLLIN, 0 } //item 2 to be polled
    };
    
    
    //  Switch messages between sockets
    while (1) {
        zmq::message_t message;
        int more;               //  Multipart detection(0 or 1)

        zmq::poll(&items [0], 2, -1);
        
        if (items [0].revents & ZMQ_POLLIN) { //If the frontend socket has an incoming message 
            while (1) {
                //  Process all parts of the message
                frontend.recv(message, zmq::recv_flags::none);
                size_t more_size = sizeof (more);
                more = frontend.get(zmq::sockopt::rcvmore); 
                backend.send(message, more? zmq::send_flags::sndmore : zmq::send_flags::none);
                
                if (!more)
                    break;      
            }
        }
        if (items [1].revents & ZMQ_POLLIN) {
            while (1) {
                //  Process all parts of the message
                backend.recv(&message);
                size_t more_size = sizeof (more);
                more = backend.get(zmq::sockopt::rcvmore); 
                frontend.send(message, more? zmq::send_flags::sndmore : zmq::send_flags::none);

                if (!more)
                    break;      
            }
        }
    }
    
    
    return 0;
}
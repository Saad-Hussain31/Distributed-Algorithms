#include "zhelpers.hpp"
#include <iostream>
using namespace zmq;

int main() {
    
    zmq::context_t context(1);

    //where the weather server is
    zmq::socket_t frontend(context, ZMQ_SUB);
    frontend.connect("tcp://127.0.0.1:5556");


    //public endpoints for subs
    zmq::socket_t backend(context, ZMQ_PUB);
    backend.bind("tcp://127.0.0.1:8100");

    //subscribe all
    frontend.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    

    //fan out msgs to relevant subs
    while(1) {
        while(1) {
            zmq::message_t message;
            int more;
            size_t more_size = sizeof(more);

            //process multipart msgs
            frontend.recv(&message);
            frontend.getsockopt(ZMQ_RCVMORE, &more, &more_size);
            backend.send(message, more? ZMQ_SNDMORE : 0);
            if(!more) break;
        }
    }

    return 0;

}

//TODO: Write a server and connect the frontend socket to it. 
// Make the server publish something and forward that 'something' to clients using the backend socket.

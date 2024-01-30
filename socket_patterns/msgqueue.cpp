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
    
  

    zmq::proxy(static_cast<void*>(frontend),
                static_cast<void*>(backend),
                nullptr);
    
    return 0;
}
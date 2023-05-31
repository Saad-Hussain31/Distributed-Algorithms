cmake_minimum_required(VERSION 3.20)
project(DistributedAlgos)

set(CMAKE_CXX_STANDARD 17)
find_package(cppzmq REQUIRED)



add_executable(ExcludeOnTimeout Chapter2/ExcludeOnTimeout.cpp)
target_link_libraries(ExcludeOnTimeout -pthread)


add_executable(rrclient zmq/rrclient.cpp)
target_link_libraries(rrclient cppzmq)




add_executable(rrworker zmq/rrworker.cpp)
target_link_libraries(rrworker cppzmq)


add_executable(rrbroker zmq/rrbroker.cpp)
target_link_libraries(rrbroker cppzmq)

add_executable(zmq_proxy zmq/zmq_proxy.cpp)
target_link_libraries(zmq_proxy cppzmq)

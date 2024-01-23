cmake_minimum_required(VERSION 3.18)
project(DistributedAlgos)

set(CMAKE_CXX_STANDARD 17)
find_package(cppzmq REQUIRED)



# add_executable(ExcludeOnTimeout Chapter2/ExcludeOnTimeout.cpp)
# target_link_libraries(ExcludeOnTimeout -pthread)


add_executable(rrclient zmq/rrclient.cpp)
target_link_libraries(rrclient cppzmq)


add_executable(rrworker zmq/rrworker.cpp)
target_link_libraries(rrworker cppzmq)


add_executable(rrbroker zmq/rrbroker.cpp)
target_link_libraries(rrbroker cppzmq)

add_executable(msgqueue zmq/msgqueue.cpp)
target_link_libraries(msgqueue cppzmq)


add_executable(wuproxy zmq/wuproxy.cpp)
target_link_libraries(wuproxy cppzmq)

add_executable(taskwork zmq/taskwork.cpp)
target_link_libraries(taskwork cppzmq)

add_executable(tasksink zmq/tasksink.cpp)
target_link_libraries(tasksink cppzmq)

add_executable(interrupt zmq/interrupt.cpp)
target_link_libraries(interrupt cppzmq)

# add_executable(identity zmq/identity.cpp)
# target_link_libraries(identity cppzmq)

# add_executable(bind zmq/bind.cpp)
# target_link_libraries(bind cppzmq)




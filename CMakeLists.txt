cmake_minimum_required(VERSION 3.18)
project(DistributedAlgos)

set(CMAKE_CXX_STANDARD 17)
find_package(cppzmq REQUIRED)



# add_executable(ExcludeOnTimeout Chapter2/ExcludeOnTimeout.cpp)
# target_link_libraries(ExcludeOnTimeout -pthread)


add_executable(rrclient socket_patterns/rrclient.cpp)
target_link_libraries(rrclient cppzmq)


add_executable(rrworker socket_patterns/rrworker.cpp)
target_link_libraries(rrworker cppzmq)


add_executable(rrbroker socket_patterns/rrbroker.cpp)
target_link_libraries(rrbroker cppzmq)

add_executable(msgqueue socket_patterns/msgqueue.cpp)
target_link_libraries(msgqueue cppzmq)


add_executable(wuproxy socket_patterns/wuproxy.cpp)
target_link_libraries(wuproxy cppzmq)

add_executable(taskwork socket_patterns/taskwork.cpp)
target_link_libraries(taskwork cppzmq)

add_executable(tasksink socket_patterns/tasksink.cpp)
target_link_libraries(tasksink cppzmq)

add_executable(interrupt socket_patterns/interrupt.cpp)
target_link_libraries(interrupt cppzmq)

add_executable(mtrelay socket_patterns/mtrelay.cpp)
target_link_libraries(mtrelay cppzmq)

add_executable(mtserver socket_patterns/mtserver.cpp)
target_link_libraries(mtserver cppzmq)

# add_executable(identity zmq/identity.cpp)
# target_link_libraries(identity cppzmq)

# add_executable(bind zmq/bind.cpp)
# target_link_libraries(bind cppzmq)




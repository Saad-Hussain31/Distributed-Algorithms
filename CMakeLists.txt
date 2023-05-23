cmake_minimum_required(VERSION 3.20)
project(DistributedAlgos)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExcludeOnTimeout Chapter2/ExcludeOnTimeout.cpp)
target_link_libraries(ExcludeOnTimeout -pthread)

cmake_minimum_required(VERSION 3.12)
project("zmq_patterns" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(cppzmq)

add_subdirectory(zmq_hello_world)
add_subdirectory(weather_update)

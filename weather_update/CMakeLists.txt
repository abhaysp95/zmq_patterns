add_executable(zmq_wus wuserver.cpp)
add_executable(zmq_wuc wuclient.cpp)
target_link_libraries(zmq_wus PRIVATE cppzmq)
target_link_libraries(zmq_wuc PRIVATE cppzmq)


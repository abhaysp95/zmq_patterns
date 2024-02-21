add_executable(zmq_hws server.cpp)
add_executable(zmq_hwc client.cpp)
target_link_libraries(zmq_hws PRIVATE cppzmq)
target_link_libraries(zmq_hwc PRIVATE cppzmq)

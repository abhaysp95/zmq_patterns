#include <iostream>
#include <sstream>
#include <zmq.h>
#include <zmq.hpp>

#define LIMIT 100

int main(int argc, char **argv) {
	std::cout << "Collecting updates from server: \n";

	zmq::context_t ctx(1);
	zmq::socket_t subscriber(ctx, zmq::socket_type::sub);
	subscriber.connect("tcp://localhost:6565");

	// subscribe to a zip code

	std::string filter = argc > 1 ? argv[1] : "6969 ";
	subscriber.setsockopt(ZMQ_SUBSCRIBE, filter);

	long temp = 0;
	for (size_t i = 0; i < LIMIT; i++) {
		zmq::message_t msg;
		zmq::recv_result_t res = subscriber.recv(msg, zmq::recv_flags::none);

		int z, t, h;
		std::istringstream istream(static_cast<char*>(msg.data()));
		istream >> z >> t >> h;

		temp += t;
	}

	std::cout << "Average temperature for zipcode " << filter << " was " << (int)(temp / LIMIT) << "F" << std::endl;

	return 0;
}

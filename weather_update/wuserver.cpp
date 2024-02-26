#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <zmq.hpp>

int get_within(int x) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(x);

	return dist(rng);
}

int main(void) {
	zmq::context_t ctx(1);
	zmq::socket_t publisher(ctx, zmq::socket_type::pub);
	publisher.bind("tcp://*:6565");
	publisher.bind("ipc://weather.ipc");

	while (true) {
		int zipcode = get_within(100000),
			temperature = get_within(215) - 80,
			relhumidity = get_within(50) + 10;

		std::ostringstream ostream;
		ostream << std::setfill('0') << std::setw(5) << zipcode << " " << temperature << " " << relhumidity;
		std::string weather = ostream.str();
		zmq::message_t msg(weather.begin(), weather.end());
		publisher.send(msg, zmq::send_flags::none);
	}

	return 0;
}

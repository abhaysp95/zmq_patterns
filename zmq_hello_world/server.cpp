#include <zmq.h>
#include <zmq.hpp>
#include <iostream>

using namespace std;

int main(void) {
	int major, minor, patch;
	zmq_version(&major, &minor, &patch);
	cout << "ZMQ version: " << major << "." << minor << "." << patch << '\n';

	zmq::context_t ctx(2);
	zmq::socket_t socket (ctx, zmq::socket_type::rep);
	socket.bind("tcp://*:5555");

	while (true) {
		zmq::message_t request;

		zmq::recv_result_t res = socket.recv(request, zmq::recv_flags::none);
		string rec_str(static_cast<char*>(request.data()), request.size());
		cout << rec_str << " " << res.value() << '\n';

		sleep(1);  // emulate doing some work

		zmq::message_t reply(5);
		memcpy(reply.data(), "World", 5);
		socket.send(reply, zmq::send_flags::none);
	}

	return 0;
}

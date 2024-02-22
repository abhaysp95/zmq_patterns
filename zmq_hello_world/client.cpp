#include <cstring>
#include<zmq.hpp>
#include<iostream>

using namespace std;

int main(void) {
	zmq::context_t ctx(1);
	zmq::socket_t socket(ctx, zmq::socket_type::req);

	cout << "connecting to server..." << endl;
	socket.connect("tcp://localhost:5555");

	// send 10 requests, waiting for reply each time
	for (size_t req_nbr = 0; req_nbr < 10; req_nbr++) {
		zmq::message_t req(5);
		memcpy(req.data(), "Hello", 5);
		cout << "sending Hello " << req_nbr << "..." << endl;
		socket.send(req, zmq::send_flags::none);

		// get reply
		zmq::message_t rep;
		zmq::recv_result_t res = socket.recv(rep, zmq::recv_flags::none);

		// use res.value() or rep.size() to determine message size
		string recv_msg(static_cast<char*>(rep.data()), res.value());

		cout << "recieved " << recv_msg << " " << req_nbr << endl;
	}

	return 0;
}

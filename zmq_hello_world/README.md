# Hello World

The server & client created using ZMQ show classic REQ-REP (request-reply) pattern.

## How to run

Once you build the project using cmake in root dir:

```sh
$ cd zmq_hello_world
$ make zmq_hws  # to build the server
$ make zmq_hwc # to build the client
```

You can open two different terminal emulator (panes) and run `./zmq_hws` in one, and `./zmq_hwc` in another terminal.

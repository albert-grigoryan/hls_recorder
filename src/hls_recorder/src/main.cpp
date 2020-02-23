#include "multiplexer.hpp"

#include <served/served.hpp>

int main(int argc, char const* argv[]) {
	// Create a multiplexer for handling requests
	hls_recorder::multiplexer m;

	// Create the server and run with 10 handler threads.
	served::net::server server("0.0.0.0", "80", m);
	server.run(10);

	return (EXIT_SUCCESS);
}

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;
namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

int remote_control_alphabot(const char* host, const char* command)
{
	try
	{
		//// Check command line arguments.
		//if (argc != 4 && argc != 5)
		//{
		//    std::cerr <<
		//        "Usage: http-client-sync <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
		//        "Example:\n" <<
		//        "    http-client-sync www.example.com 80 /\n" <<
		//        "    http-client-sync www.example.com 80 / 1.0\n";
		//    return EXIT_FAILURE;
		//}
		//auto const host = argv[1];
		//auto const port = argv[2];
		//auto const target = argv[3];
		//int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;
//        auto const host = "192.168.0.7";
		auto const port = "8000";
		auto const target = command;
		int version = 11;

		// The io_context is required for all I/O
		net::io_context ioc;

		// These objects perform our I/O
		tcp::resolver resolver(ioc);
		beast::tcp_stream stream(ioc);

		// Look up the domain name
		auto const results = resolver.resolve(host, port);

		// Make the connection on the IP address we get from a lookup
		stream.connect(results);

		//// Set up an HTTP GET request message
		//http::request<http::string_body> req{ http::verb::get, target, version };
		//req.set(http::field::host, host);
		//req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		// Set up an HTTP GET request message
		http::request<http::string_body> req{ http::verb::post, target, version };
		req.set(http::field::host, host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		req.set(http::field::authorization, "Basic d2ViaW9waTpyYXNwYmVycnk=");

		// Send the HTTP request to the remote host
		http::write(stream, req);

		// This buffer is used for reading and must be persisted
		beast::flat_buffer buffer;

		// Declare a container to hold the response
		http::response<http::dynamic_body> res;

		// Receive the HTTP response
		http::read(stream, buffer, res);
		string res_str = boost::beast::buffers_to_string(res.body().data());
		// Write the message to standard out


		res_str = res_str.substr(2, 6);
		cout << "Temperature: " << res_str << endl;

				// Gracefully close the socket
		beast::error_code ec;
		stream.socket().shutdown(tcp::socket::shutdown_both, ec);

		// not_connected happens sometimes
		// so don't bother reporting it.
		//
		if (ec && ec != beast::errc::not_connected)
			throw beast::system_error{ ec };

		// If we get here then the connection is closed gracefully
	}
	catch (exception const& e)
	{
		cerr << "Error: " << e.what() << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

// Performs an HTTP GET and prints the response
int main(int argc, char** argv)
{
	srand((unsigned int)time(0));
	const char* ip = "192.168.0.97";
	int cnt = 0;
	cout << ip << ": Connect!" << endl;
	// REST APIS
	remote_control_alphabot(ip, "macros/temperature");
	return 0;
}

#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::tcp;

int main()
{
	boost::asio::io_service io_service;
	tcp::socket socket(io_service);

	boost::system::error_code error;
	auto endpoint =	tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 31400);

	socket.connect(endpoint, error);
	if (error) {
		std::cout << "connect ½ÇÆÐ : " << error.message() << std::endl;
	}
	else {
		std::cout << "connected" << std::endl;
	}
	return 0;
}
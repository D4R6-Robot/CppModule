#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::tcp;

class Client
{
public:
	boost::asio::io_service& io_service;

	Client(boost::asio::io_service& io_service)
		:io_service(io_service)
	{
	}

	void connect()
	{
		tcp::socket socket_(io_service);

		auto endpoint = tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 31400);
		socket_.async_connect(
			endpoint,
			boost::bind(&Client::on_connect,
				this, 
				boost::asio::placeholders::error));
	}

	void on_connect(const boost::system::error_code& error)
	{
		if (error)
		{
			std::cout << "connect failed : " << error.message()
				<< std::endl;
		}
		else
		{
			std::cout << "connected" << std::endl;
		}
	}
};

int main()
{
	boost::asio::io_service io_service;
	Client client(io_service);
	client.connect();
	io_service.run();
}
#include "HelloImpl.hpp"

#include <iostream>
#include <string>


#define CONSOLE(coutExpr)		std::cout << coutExpr << std::endl


HelloImpl::HelloImpl()
{
	CONSOLE("HelloImpl CONSTRUCTOR");
}

HelloImpl::~HelloImpl()
{
	CONSOLE("HelloImpl DESTRUCTOR");
}

char* HelloImpl::sendMsg(const char* message)
{
	CONSOLE("Client says: " << message);

	std::string result;
	for(std::size_t i = 0; i < 3; ++i)
	{
		result.append(message);
		result.append(" ");
	}

	CONSOLE("Response: " << result);

	return CORBA::string_dup(result.c_str());
}


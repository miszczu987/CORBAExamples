#include <ServerRequestInterceptor.hpp>

#include <Logger.hpp>


ServerRequestInterceptor::ServerRequestInterceptor()
{
	CONSOLE("ServerRequestInterceptor CONSTRUCTOR");
}

ServerRequestInterceptor::~ServerRequestInterceptor()
{
	CONSOLE("ServerRequestInterceptor DESTRUCTOR");
}

void ServerRequestInterceptor::receive_request_service_contexts(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptor::receive_request_service_contexts: operation=" << operation.in());
}

void ServerRequestInterceptor::receive_request(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptor::receive_request: operation=" << operation.in());
}

void ServerRequestInterceptor::send_reply(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptor::send_reply: operation=" << operation.in());
}

void ServerRequestInterceptor::send_exception(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptor::send_exception: operation=" << operation.in());
}

void ServerRequestInterceptor::send_other(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptor::send_other: operation=" << operation.in());
}

char* ServerRequestInterceptor::name()
{
	CONSOLE("ServerRequestInterceptor::name");
	return CORBA::string_dup("ServerRequestInterceptor");
}

void ServerRequestInterceptor::destroy()
{
	CONSOLE("ServerRequestInterceptor::destroy");
}


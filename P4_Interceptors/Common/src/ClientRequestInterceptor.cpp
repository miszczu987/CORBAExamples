#include <ClientRequestInterceptor.hpp>

#include <Logger.hpp>


ClientRequestInterceptor::ClientRequestInterceptor()
{
	CONSOLE("ClientRequestInterceptor CONSTRUCTOR");
}

ClientRequestInterceptor::~ClientRequestInterceptor()
{
	CONSOLE("ClientRequestInterceptor DESTRUCTOR");
}

void ClientRequestInterceptor::send_request(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptor::send_request: operation=" << operation.in());
}

void ClientRequestInterceptor::send_poll(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptor::send_poll: operation=" << operation.in());
}

void ClientRequestInterceptor::receive_reply(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptor::receive_reply: operation=" << operation.in());
}

void ClientRequestInterceptor::receive_exception(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptor::receive_exception: operation=" << operation.in());
}

void ClientRequestInterceptor::receive_other(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptor::receive_other: operation=" << operation.in());
}

char* ClientRequestInterceptor::name()
{
	CONSOLE("ClientRequestInterceptor::name");
	return CORBA::string_dup("ClientRequestInterceptor");
}

void ClientRequestInterceptor::destroy()
{
	CONSOLE("ClientRequestInterceptor::destroy");
}


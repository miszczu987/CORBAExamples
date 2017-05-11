#include <ClientRequestInterceptorImpl.hpp>

#include <Logger.hpp>


ClientRequestInterceptorImpl::ClientRequestInterceptorImpl()
{
	CONSOLE("ClientRequestInterceptorImpl CONSTRUCTOR");
}

ClientRequestInterceptorImpl::~ClientRequestInterceptorImpl()
{
	CONSOLE("ClientRequestInterceptorImpl DESTRUCTOR");
}

void ClientRequestInterceptorImpl::send_request(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptorImpl::send_request: operation=" << operation.in());
}

void ClientRequestInterceptorImpl::send_poll(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptorImpl::send_poll: operation=" << operation.in());
}

void ClientRequestInterceptorImpl::receive_reply(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptorImpl::receive_reply: operation=" << operation.in());
}

void ClientRequestInterceptorImpl::receive_exception(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptorImpl::receive_exception: operation=" << operation.in());
}

void ClientRequestInterceptorImpl::receive_other(PortableInterceptor::ClientRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ClientRequestInterceptorImpl::receive_other: operation=" << operation.in());
}

char* ClientRequestInterceptorImpl::name()
{
	CONSOLE("ClientRequestInterceptorImpl::name");
	return CORBA::string_dup("ClientRequestInterceptorImpl");
}

void ClientRequestInterceptorImpl::destroy()
{
	CONSOLE("ClientRequestInterceptorImpl::destroy");
}


#include <ServerRequestInterceptorImpl.hpp>

#include <Logger.hpp>


ServerRequestInterceptorImpl::ServerRequestInterceptorImpl()
{
	CONSOLE("ServerRequestInterceptorImpl CONSTRUCTOR");
}

ServerRequestInterceptorImpl::~ServerRequestInterceptorImpl()
{
	CONSOLE("ServerRequestInterceptorImpl DESTRUCTOR");
}

void ServerRequestInterceptorImpl::receive_request_service_contexts(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptorImpl::receive_request_service_contexts: operation=" << operation.in());
}

void ServerRequestInterceptorImpl::receive_request(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptorImpl::receive_request: operation=" << operation.in());
}

void ServerRequestInterceptorImpl::send_reply(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptorImpl::send_reply: operation=" << operation.in());
}

void ServerRequestInterceptorImpl::send_exception(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptorImpl::send_exception: operation=" << operation.in());
}

void ServerRequestInterceptorImpl::send_other(PortableInterceptor::ServerRequestInfo_ptr ri)
{
	CORBA::String_var operation = ri->operation();
	CONSOLE("ServerRequestInterceptorImpl::send_other: operation=" << operation.in());
}

char* ServerRequestInterceptorImpl::name()
{
	CONSOLE("ServerRequestInterceptorImpl::name");
	return CORBA::string_dup("ServerRequestInterceptorImpl");
}

void ServerRequestInterceptorImpl::destroy()
{
	CONSOLE("ServerRequestInterceptorImpl::destroy");
}


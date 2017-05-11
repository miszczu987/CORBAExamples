#pragma once


#include <tao/PI_Server/PI_Server.h>


struct ServerRequestInterceptorImpl:
	PortableInterceptor::ServerRequestInterceptor
{
	ServerRequestInterceptorImpl();
	virtual ~ServerRequestInterceptorImpl();

	virtual void receive_request_service_contexts(PortableInterceptor::ServerRequestInfo_ptr ri);
	virtual void receive_request(PortableInterceptor::ServerRequestInfo_ptr ri);
	virtual void send_reply(PortableInterceptor::ServerRequestInfo_ptr ri);
	virtual void send_exception(PortableInterceptor::ServerRequestInfo_ptr ri);
	virtual void send_other(PortableInterceptor::ServerRequestInfo_ptr ri);

	virtual char* name();
	virtual void destroy();

};


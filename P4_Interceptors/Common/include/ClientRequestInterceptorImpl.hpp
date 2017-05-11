#pragma once


#include <tao/PI/PI.h>


struct ClientRequestInterceptorImpl:
	PortableInterceptor::ClientRequestInterceptor
{
	ClientRequestInterceptorImpl();
	virtual ~ClientRequestInterceptorImpl();

	virtual void send_request(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void send_poll(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void receive_reply(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void receive_exception(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void receive_other(PortableInterceptor::ClientRequestInfo_ptr ri);

	virtual char* name();
	virtual void destroy();

};


#pragma once


#include <tao/PI/PI.h>


struct ClientRequestInterceptor:
	PortableInterceptor::ClientRequestInterceptor
{
	ClientRequestInterceptor();
	virtual ~ClientRequestInterceptor();

	virtual void send_request(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void send_poll(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void receive_reply(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void receive_exception(PortableInterceptor::ClientRequestInfo_ptr ri);
	virtual void receive_other(PortableInterceptor::ClientRequestInfo_ptr ri);

	virtual char* name();
	virtual void destroy();

};


#pragma once


#include <CORBAHello_skel.h>


class EchoImpl:
	public POA_CORBAHello::Echo,
	public PortableServer::RefCountServantBase
{
public:
	EchoImpl();
	virtual ~EchoImpl();

	virtual char* sendMsg(const char* message);
	virtual void fillPersonDataSeq(::CORBA::ULong size, ::CORBAHello::PersonDataSeq_out dataSeq);

};


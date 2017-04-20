#pragma once


#include <CORBAHello_skel.h>


class HelloImpl:
	public POA_CORBAHello::Echo,
	public PortableServer::RefCountServantBase
{
public:
	HelloImpl();
	virtual ~HelloImpl();

	virtual char* sendMsg(const char* message);
	virtual void fillPersonDataSeq(::CORBA::ULong size, ::CORBAHello::PersonDataSeq_out dataSeq);

};


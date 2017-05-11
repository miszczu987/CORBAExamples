#include <EchoImpl.hpp>

#include <Logger.hpp>

#include <iostream>
#include <sstream>
#include <string>


EchoImpl::EchoImpl()
{
	CONSOLE("EchoImpl CONSTRUCTOR");
}

EchoImpl::~EchoImpl()
{
	CONSOLE("EchoImpl DESTRUCTOR");
}

char* EchoImpl::sendMsg(const char* message)
{
	CONSOLE("Client says: " << message);

	const std::string response = "Hello from Server!";
	CONSOLE("Response: " << response);

	return CORBA::string_dup(response.c_str());
}

void EchoImpl::fillPersonDataSeq(::CORBA::ULong size, ::CORBAHello::PersonDataSeq_out dataSeq)
{
	CONSOLE("Filling data for " << size << " persons");

	CORBAHello::PersonDataSeq_var personSeq = new CORBAHello::PersonDataSeq();
	personSeq->length(size);

	for(CORBA::ULong i = 0; i < size; ++i)
	{
		std::ostringstream name;
		name << "Person_" << i;

		(*personSeq)[i].id = i;
		(*personSeq)[i].name = name.str().c_str();
	}

	dataSeq = personSeq._retn();

	CONSOLE("Filled data for " << size << " persons");
}


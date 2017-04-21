#include <EchoImpl.hpp>

#include <iostream>
#include <sstream>
#include <string>


#define CONSOLE(coutExpr)		std::cout << coutExpr << std::endl


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

	std::string result;
	for(std::size_t i = 0; i < 3; ++i)
	{
		result.append(message);
		result.append(" ");
	}

	CONSOLE("Response: " << result);

	return CORBA::string_dup(result.c_str());
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


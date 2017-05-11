#include <ClientCalls.hpp>

#include <Constants.hpp>
#include <Logger.hpp>


void performClientCalls(CORBAHello::Echo_ptr server)
{
	CORBA::String_var message = constants::HELLO_FROM_CLIENT.c_str();
	CONSOLE("Send message to Server: " << message.in());

	CORBA::String_var response = server->sendMsg(message.in());
	CONSOLE("Response from Server: " << response.in());


	CORBAHello::PersonDataSeq_var personData;

	CONSOLE("Request filling data for " << constants::PERSON_AMOUNT << " persons");
	server->fillPersonDataSeq(constants::PERSON_AMOUNT, personData.out());

	CONSOLE("Got data for " << personData->length() << " persons:");
	for(CORBA::ULong i = 0; i < personData->length(); ++i)
	{
		CONSOLE("  -> id=" << (*personData)[i].id << ", name=" << (*personData)[i].name.in());
	}
}


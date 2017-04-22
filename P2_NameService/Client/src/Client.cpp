#include <tao/corba.h>
#include <orbsvcs/CosNamingC.h>

#include <CORBAHello.h>
#include <Constants.hpp>
#include <Logger.hpp>

#include <iostream>
#include <string>


CORBA::ORB_var theORB;


int main(int argc, char* argv[])
{
	try
	{
		CONSOLE("Initialize ORB");
		theORB = CORBA::ORB_init(argc, argv);

		CONSOLE("Obtain NameService");
		CORBA::Object_var nameServiceRef = theORB->resolve_initial_references("NameService");
		CosNaming::NamingContext_var nameService = CosNaming::NamingContext::_narrow(nameServiceRef.in());

		CONSOLE("Obtain Server reference from NameService");
		CosNaming::Name name;
		name.length(1);
		name[0].id = constants::ECHO_SERVER.c_str();
		name[0].kind = "";

		CORBA::Object_var serverRef = nameService->resolve(name);
		CORBAHello::Echo_var server = CORBAHello::Echo::_narrow(serverRef.in());


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


		CONSOLE("Shutdown ORB");
		theORB->shutdown(false);

		CONSOLE("Destroy ORB");
		theORB->destroy();
	}
	catch(const CORBA::Exception& e)
	{
		CONSOLE("CORBA::Exception: " << e);
	}

	return 0;
}


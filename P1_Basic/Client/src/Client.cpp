#include <tao/corba.h>

#include <CORBAHello.h>

#include <iostream>
#include <string>


#define CONSOLE(coutExpr)		std::cout << coutExpr << std::endl


CORBA::ORB_var theORB;


int main(int argc, char* argv[])
{
	try
	{
		CONSOLE("Initialize ORB");
		theORB = CORBA::ORB_init(argc, argv);

		std::string serverIOR;
		std::cout << "Enter Server IOR: ";
		std::cin >> serverIOR;

		CONSOLE("Obtain Server");
		CORBA::Object_var serverRef = theORB->string_to_object(serverIOR.c_str());
		CORBAHello::Echo_var server = CORBAHello::Echo::_narrow(serverRef.in());

		CONSOLE("Send message to Server");
		CORBA::String_var echoString = server->sendMsg("Hello from Client!");

		CONSOLE("Response from Server: " << echoString.in());


		CONSOLE("Requesting filling data for 5 persons");
		CORBAHello::PersonDataSeq_var personData;
		server->fillPersonDataSeq(5, personData.out());

		CONSOLE("Got data for " << personData->length() << " persons:");
		for(CORBA::ULong i = 0; i < personData->length(); ++i)
		{
			CONSOLE("  id=" << (*personData)[i].id << ", name=" << (*personData)[i].name.in());
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


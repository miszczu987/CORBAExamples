#include <tao/corba.h>

#include <CORBAHello.h>

#include <ClientCalls.hpp>
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

		std::string serverIOR;
		std::cout << "Enter Server IOR: ";
		std::cin >> serverIOR;

		CONSOLE("Obtain Server reference");
		CORBA::Object_var serverRef = theORB->string_to_object(serverIOR.c_str());
		CORBAHello::Echo_var server = CORBAHello::Echo::_narrow(serverRef.in());


		//Perform remote calls...
		performClientCalls(server.in());


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


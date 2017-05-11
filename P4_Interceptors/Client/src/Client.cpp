#include <tao/corba.h>
#include <orbsvcs/CosNamingC.h>

#include <CORBAHello.h>

#include <ClientCalls.hpp>
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


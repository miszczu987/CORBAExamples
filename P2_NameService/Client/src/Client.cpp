#include <tao/corba.h>
#include <orbsvcs/CosNamingC.h>

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

		CONSOLE("Obtain NameService");
		CORBA::Object_var nameServiceRef = theORB->resolve_initial_references("NameService");
		CosNaming::NamingContext_var nameService = CosNaming::NamingContext::_narrow(nameServiceRef.in());

		CONSOLE("Resolve servant reference from NameService");
		CosNaming::Name name;
		name.length(1);
		name[0].id = "HELLO_SERVER";
		name[0].kind = "";

		CORBA::Object_var serverRef = nameService->resolve(name);
		CORBAHello::Echo_var server = CORBAHello::Echo::_narrow(serverRef.in());

		CONSOLE("Send message to Server");
		CORBA::String_var echoString = server->sendMsg("Hello from Client!");

		CONSOLE("Response from Server: " << echoString.in());

		CONSOLE("Destroy ORB");
		theORB->destroy();
	}
	catch(const CORBA::Exception& e)
	{
		CONSOLE("CORBA::Exception: " << e);
	}

	return 0;
}


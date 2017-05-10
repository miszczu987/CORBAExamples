#include <tao/corba.h>
#include <tao/PortableServer/PortableServer.h>
#include <orbsvcs/CosNamingC.h>

#include "EchoLocator.hpp"
#include <Constants.hpp>
#include <Logger.hpp>

#include <exception>
#include <iostream>
#include <string>

#include <boost/thread.hpp>


CORBA::ORB_var theORB;


void orbRun()
{
	theORB->run();
}


int main(int argc, char* argv[])
{
	try
	{
		CONSOLE("Initialize ORB");
		theORB = CORBA::ORB_init(argc, argv);

		CONSOLE("Obtain RootPOA");
		CORBA::Object_var rootPOARef = theORB->resolve_initial_references("RootPOA");
		PortableServer::POA_var rootPOA = PortableServer::POA::_narrow(rootPOARef.in());

		CONSOLE("Obtain POAManager");
		PortableServer::POAManager_var poaManager = rootPOA->the_POAManager();

		CONSOLE("Obtain NameService");
		CORBA::Object_var nameServiceRef = theORB->resolve_initial_references("NameService");
		CosNaming::NamingContext_var nameService = CosNaming::NamingContext::_narrow(nameServiceRef.in());

		CONSOLE("Create new POA");
		CORBA::PolicyList policies;
		policies.length(2);
		policies[0] = rootPOA->create_servant_retention_policy(PortableServer::NON_RETAIN);
		policies[1] = rootPOA->create_request_processing_policy(PortableServer::USE_SERVANT_MANAGER);

		PortableServer::POA_var newPOA = rootPOA->create_POA("ServantManager_POA", poaManager, policies);

		CONSOLE("Create locator reference");
		PortableServer::ObjectId_var locatorId = PortableServer::string_to_ObjectId("Echo locator");
		CORBA::Object_var locatorRef = newPOA->create_reference_with_id(locatorId.in(), "IDL:CORBAHello/Echo:1.0");

		CONSOLE("Bind locator reference to NameService");
		CosNaming::Name name;
		name.length(1);
		name[0].id = constants::ECHO_SERVER.c_str();
		name[0].kind = "";

		nameService->rebind(name, locatorRef.in());

		CONSOLE("Set servant manager in new POA");
		PortableServer::ServantManager_var echoLocator = new EchoLocator();
		newPOA->set_servant_manager(echoLocator.in());

		CONSOLE("Activate POAManager");
		poaManager->activate();


		CONSOLE("Start ORB thread");
		boost::thread orbThread(orbRun);

		CONSOLE("Server READY. Press ENTER to exit");
		std::cin.get();

		CONSOLE("Shutting down...");

		CONSOLE("Unbind servant reference from NameService");
		nameService->unbind(name);

		sleep(1);

		CONSOLE("Shutdown ORB");
		theORB->shutdown(false);

		CONSOLE("Join ORB thread");
		orbThread.join();

		CONSOLE("Destroy ORB");
		theORB->destroy();
	}
	catch(const CORBA::Exception& e)
	{
		CONSOLE("CORBA::Exception: " << e);
	}
	catch(const std::exception& e)
	{
		CONSOLE("std::exception: " << e.what());
	}

	return 0;
}


#include <tao/corba.h>
#include <tao/PortableServer/PortableServer.h>
#include <orbsvcs/CosNamingC.h>

#include <EchoImpl.hpp>
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

		CONSOLE("Construct servant");
		EchoImpl* echoImpl = new EchoImpl();

		CONSOLE("A ---> Servant REFCOUNT=" << echoImpl->_refcount_value());

		CONSOLE("Activate servant in POA");
		PortableServer::ObjectId_var echoImplId = rootPOA->activate_object(echoImpl);

		CONSOLE("B ---> Servant REFCOUNT=" << echoImpl->_refcount_value());

		CONSOLE("Remove servant reference");
		echoImpl->_remove_ref();

		CONSOLE("C ---> Servant REFCOUNT=" << echoImpl->_refcount_value());

		CONSOLE("Bind servant reference to NameService");
		CosNaming::Name name;
		name.length(1);
		name[0].id = constants::ECHO_SERVER.c_str();
		name[0].kind = "";

		CORBA::Object_var echoRef = rootPOA->servant_to_reference(echoImpl);
		nameService->rebind(name, echoRef.in());

		CONSOLE("Activate POAManager");
		poaManager->activate();


		CONSOLE("Start ORB thread");
		boost::thread orbThread(orbRun);

		CONSOLE("Server READY. Press ENTER to exit");
		std::cin.get();


		CONSOLE("Shutting down...");

		CONSOLE("Unbind servant reference from NameService");
		nameService->unbind(name);

		CONSOLE("Deactivate servant in POA");
		rootPOA->deactivate_object(echoImplId);

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


#include <tao/corba.h>
#include <tao/PortableServer/PortableServer.h>
#include <orbsvcs/CosNamingC.h>

#include <HelloImpl.hpp>

#include <exception>
#include <iostream>
#include <string>

#include <boost/thread.hpp>


#define CONSOLE(coutExpr)		std::cout << coutExpr << std::endl


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
		HelloImpl* helloImpl = new HelloImpl();

		CONSOLE("A ---> Servant REFCOUNT=" << helloImpl->_refcount_value());

		CONSOLE("Activate servant in POA");
		PortableServer::ObjectId_var helloImplId = rootPOA->activate_object(helloImpl);

		CONSOLE("B ---> Servant REFCOUNT=" << helloImpl->_refcount_value());

		{
			CONSOLE("Remove servant reference");
			PortableServer::ServantBase_var _cleanup = helloImpl;
		}

		CONSOLE("C ---> Servant REFCOUNT=" << helloImpl->_refcount_value());

		CONSOLE("Bind servant reference to NameService");
		CosNaming::Name name;
		name.length(1);
		name[0].id = "HELLO_SERVER";
		name[0].kind = "";

		CORBA::Object_var helloImplRef = rootPOA->servant_to_reference(helloImpl);
		nameService->rebind(name, helloImplRef.in());

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
		rootPOA->deactivate_object(helloImplId);

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


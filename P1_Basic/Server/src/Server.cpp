#include <tao/corba.h>
#include <tao/PortableServer/PortableServer.h>

#include <EchoImpl.hpp>
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

		CONSOLE("Construct servant");
		EchoImpl* echoImpl = new EchoImpl();

		CONSOLE("A ---> Servant REFCOUNT=" << echoImpl->_refcount_value());

		CONSOLE("Activate servant in POA");
		PortableServer::ObjectId_var echoImplId = rootPOA->activate_object(echoImpl);

		CONSOLE("B ---> Servant REFCOUNT=" << echoImpl->_refcount_value());

		CONSOLE("Remove servant reference");
		echoImpl->_remove_ref();

		CONSOLE("C ---> Servant REFCOUNT=" << echoImpl->_refcount_value());

		CONSOLE("Activate POAManager");
		poaManager->activate();

		CORBA::Object_var echoRef = rootPOA->servant_to_reference(echoImpl);
		CORBA::String_var echoIOR = theORB->object_to_string(echoRef.in());
		CONSOLE("Servant IOR: " << echoIOR.in());


		CONSOLE("Start ORB thread");
		boost::thread orbThread(orbRun);

		CONSOLE("Server READY. Press ENTER to exit");
		std::cin.get();

		CONSOLE("Shutting down...");


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


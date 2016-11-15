#include <tao/corba.h>
#include <tao/PortableServer/PortableServer.h>

#include "corba/HelloImpl.hpp"

#include <iostream>
#include <string>

#include <csignal>

#include <boost/thread.hpp>


#define CONSOLE(coutExpr)		std::cout << coutExpr << std::endl


CORBA::ORB_var theORB;

bool RUN = true;


void orbRun()
{
	theORB->run();
}

void signalHandler(int)
{
	RUN = false;
}


int main(int argc, char* argv[])
{
	std::signal(SIGINT, signalHandler);

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
		HelloImpl* helloImpl = new HelloImpl();

		CONSOLE("Activate servant in POA");
		PortableServer::ObjectId_var helloImplId = rootPOA->activate_object(helloImpl);

		{
			PortableServer::ServantBase_var _cleanup = helloImpl;
		}

		CONSOLE("Activate POAManager");
		poaManager->activate();

		CORBA::Object_var helloImplRef = rootPOA->servant_to_reference(helloImpl);
		CORBA::String_var helloImplIOR = theORB->object_to_string(helloImplRef);
		CONSOLE("Servant IOR: " << helloImplIOR.in());


		CONSOLE("Server READY");
		boost::thread orbThread(orbRun);
		while(RUN)
		{
			sleep(1);
		}


		CONSOLE("Deactivate servant in POA");
		rootPOA->deactivate_object(helloImplId);

		sleep(1);

		CONSOLE("Shutdown ORB");
		theORB->shutdown(false);

		orbThread.join();

		CONSOLE("Destroy ORB");
		theORB->destroy();
	}
	catch(const CORBA::Exception& e)
	{
		CONSOLE("CORBA::Exception: " << e);
	}

	return 0;
}


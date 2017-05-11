#include <ORBInitializer.hpp>

#include <ServerRequestInterceptor.hpp>
#include <ClientRequestInterceptor.hpp>
#include <Logger.hpp>


ORBInitializer::ORBInitializer()
{
	CONSOLE("ORBInitializer CONSTRUCTOR");
}

ORBInitializer::~ORBInitializer()
{
	CONSOLE("ORBInitializer DESTRUCTOR");
}

void ORBInitializer::pre_init(PortableInterceptor::ORBInitInfo_ptr info)
{
	CONSOLE("ORBInitializer::pre_init");
	PortableInterceptor::ServerRequestInterceptor_var serverInter = new ServerRequestInterceptor();
	info->add_server_request_interceptor(serverInter.in());

	PortableInterceptor::ClientRequestInterceptor_var clientInter = new ClientRequestInterceptor();
	info->add_client_request_interceptor(clientInter.in());
}

void ORBInitializer::post_init(PortableInterceptor::ORBInitInfo_ptr info)
{
	CONSOLE("ORBInitializer::post_init");
}


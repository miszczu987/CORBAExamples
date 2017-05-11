#include <ORBInitializerImpl.hpp>

#include <ServerRequestInterceptorImpl.hpp>
#include <ClientRequestInterceptorImpl.hpp>
#include <Logger.hpp>


ORBInitializerImpl::ORBInitializerImpl()
{
	CONSOLE("ORBInitializerImpl CONSTRUCTOR");
}

ORBInitializerImpl::~ORBInitializerImpl()
{
	CONSOLE("ORBInitializerImpl DESTRUCTOR");
}

void ORBInitializerImpl::pre_init(PortableInterceptor::ORBInitInfo_ptr info)
{
	CONSOLE("ORBInitializerImpl::pre_init");
	PortableInterceptor::ServerRequestInterceptor_var serverInter = new ServerRequestInterceptorImpl();
	info->add_server_request_interceptor(serverInter.in());

	PortableInterceptor::ClientRequestInterceptor_var clientInter = new ClientRequestInterceptorImpl();
	info->add_client_request_interceptor(clientInter.in());
}

void ORBInitializerImpl::post_init(PortableInterceptor::ORBInitInfo_ptr info)
{
	CONSOLE("ORBInitializerImpl::post_init");
}


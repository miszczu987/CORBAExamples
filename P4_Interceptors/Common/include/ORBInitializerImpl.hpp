#pragma once


#include <tao/PI/PI.h>


struct ORBInitializerImpl:
	public PortableInterceptor::ORBInitializer
{
	ORBInitializerImpl();
	virtual ~ORBInitializerImpl();

	virtual void pre_init(PortableInterceptor::ORBInitInfo_ptr info);
	virtual void post_init(PortableInterceptor::ORBInitInfo_ptr info);

};


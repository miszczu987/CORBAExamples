#pragma once


#include <tao/PI/PI.h>


struct ORBInitializer:
	public PortableInterceptor::ORBInitializer
{
	ORBInitializer();
	virtual ~ORBInitializer();

	virtual void pre_init(PortableInterceptor::ORBInitInfo_ptr info);
	virtual void post_init(PortableInterceptor::ORBInitInfo_ptr info);

};


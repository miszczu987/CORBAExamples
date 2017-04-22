set(CORBA_ROOT "/opt/TAO")

set(CORBA_BIN "${CORBA_ROOT}/bin")
set(CORBA_INCLUDE "${CORBA_ROOT}/include")
set(CORBA_LIB "${CORBA_ROOT}/lib")

set(CORBA_LINK "${CORBA_LIB}/libTAO.so"
               "${CORBA_LIB}/libTAO_Valuetype.so"
               "${CORBA_LIB}/libTAO_PortableServer.so"
               "${CORBA_LIB}/libTAO_IORTable.so"
               "${CORBA_LIB}/libTAO_AnyTypeCode.so"
               "${CORBA_LIB}/libTAO_CosEvent.so"
               "${CORBA_LIB}/libTAO_CosNaming.so"
               "${CORBA_LIB}/libTAO_PI.so"
               "${CORBA_LIB}/libTAO_PI_Server.so"
               "${CORBA_LIB}/libTAO_CodecFactory.so"
               "${CORBA_LIB}/libACE.so")

set(CIDL "${CORBA_BIN}/tao_idl")


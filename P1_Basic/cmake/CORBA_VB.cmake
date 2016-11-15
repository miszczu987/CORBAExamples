set(CORBA_ROOT "/opt/visibroker-8.5.3_hf01-x86_64")

add_definitions(-DTHREAD -DPTHREADS -DBITS64)

set(CORBA_BIN "${CORBA_ROOT}/bin")
set(CORBA_INCLUDE "${CORBA_ROOT}/include")
set(CORBA_LIB "${CORBA_ROOT}/lib")

set(CORBA_LINK "${CORBA_LIB}/libcosnm64_r.so"
               "${CORBA_LIB}/liborb64_r.so"
               "${CORBA_LIB}/liblmgr64.so"
               "${CORBA_LIB}/libvdlog64_r.so"
               "${CORBA_LIB}/libvport64_r.so")

set(CIDL "${CORBA_BIN}/idl2cpp")


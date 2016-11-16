set(IDL_DIR "${PROJECT_SOURCE_DIR}/idl")
set(IDL_OUT_DIR "${PROJECT_BINARY_DIR}/idl")
file(MAKE_DIRECTORY ${IDL_OUT_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/CORBA_IDL_${CORBA_PROVIDER}.cmake)

set(IDL_OUT_SUFFIXES ".h"
                     ".cpp"
                     "_skel.h"
                     "_skel.cpp")

file(GLOB IDL_FILES ${IDL_DIR}/*.idl)

foreach(idlFullPath ${IDL_FILES})
    get_filename_component(idlName ${idlFullPath} NAME)
    string(REPLACE ".idl" "" idlName ${idlName})
    foreach(idlOutSuffix ${IDL_OUT_SUFFIXES})
        list(APPEND IDL_OUTPUTS "${IDL_OUT_DIR}/${idlName}${idlOutSuffix}")
    endforeach(idlOutSuffix)
endforeach(idlFullPath)

add_custom_command(OUTPUT ${IDL_OUTPUTS}
                   COMMAND ${CIDL} ${IDLFLAGS} ${IDL_FILES}
                   DEPENDS ${IDL_FILES})


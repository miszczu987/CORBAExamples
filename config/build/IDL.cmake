set(IDL_DIR "${PROJECT_SOURCE_DIR}/idl")
set(IDL_OUT_DIR "${PROJECT_BINARY_DIR}/idl")
file(MAKE_DIRECTORY ${IDL_OUT_DIR})


set(PROXY_H_SUFFIX ".h")
set(PROXY_INL_SUFFIX ".inl")
set(PROXY_SUFFIX ".cpp")

set(SKELETON_H_SUFFIX "_skel.h")
set(SKELETON_SUFFIX "_skel.cpp")

set(IDLFLAGS "-I${IDL_DIR}"
             "-o" "${IDL_OUT_DIR}"
             "-hc" "${PROXY_H_SUFFIX}"
             "-ci" "${PROXY_INL_SUFFIX}"
             "-cs" "${PROXY_SUFFIX}"
             "-hs" "${SKELETON_H_SUFFIX}"
             "-ss" "${SKELETON_SUFFIX}")


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


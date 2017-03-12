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


set(CLIENT_EXT "\"\"")
set(SERVER_EXT "_skel")

set(SUFFIX_HDR "h")
set(SUFFIX_CPP "cpp")

set(IDLFLAGS "-I${IDL_DIR}"
             "-root_dir" "${IDL_OUT_DIR}"
             "-client_ext" "${CLIENT_EXT}"
             "-server_ext" "${SERVER_EXT}"
             "-hdr_suffix" "${SUFFIX_HDR}"
             "-src_suffix" "${SUFFIX_CPP}"
             "-no_tie")


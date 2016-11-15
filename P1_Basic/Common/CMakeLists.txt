cmake_minimum_required(VERSION 3.1)

project(Common)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE OFF)

set(BUILD_SHARED_LIBS OFF)

#set(CMAKE_CXX_STANDARD 11)


include(${PROJECT_SOURCE_DIR}/../config/cmake/CORBA.cmake)
include(${PROJECT_SOURCE_DIR}/../config/cmake/idl/CORBA_IDL.cmake)


include_directories(${IDL_OUT_DIR} ${CORBA_INCLUDE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_library(${PROJECT_NAME} ${IDL_OUTPUTS})

target_include_directories(${PROJECT_NAME} PUBLIC "${IDL_OUT_DIR}")


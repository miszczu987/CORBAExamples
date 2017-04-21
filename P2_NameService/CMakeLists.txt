cmake_minimum_required(VERSION 3.1)

project(CORBA_P2_NameService)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE OFF)

#set(CMAKE_CXX_STANDARD 11)


add_subdirectory(${PROJECT_SOURCE_DIR}/../Common ${PROJECT_BINARY_DIR}/Common)
add_subdirectory(Server)
add_subdirectory(Client)


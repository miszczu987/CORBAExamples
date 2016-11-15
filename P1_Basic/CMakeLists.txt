cmake_minimum_required(VERSION 3.1)

project(CORBA_P1_Basic)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE OFF)


add_subdirectory(Common)
add_subdirectory(Server)
add_subdirectory(Client)


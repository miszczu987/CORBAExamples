cmake_minimum_required(VERSION 3.1)

project(Client)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE OFF)

#set(CMAKE_CXX_STANDARD 11)


include(../config/cmake/CORBA.cmake)


add_subdirectory("../Common" "${PROJECT_BINARY_DIR}/Common")

include_directories(${CORBA_INCLUDE})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
                      Common
                      ${CORBA_LINK})


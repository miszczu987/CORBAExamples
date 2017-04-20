cmake_minimum_required(VERSION 3.1)

project(Client)


include(${PROJECT_SOURCE_DIR}/../../Common/cmake/CORBA.cmake)
include(${PROJECT_SOURCE_DIR}/../../Common/cmake/outputs.cmake)


include_directories(${CORBA_INCLUDE})

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
                      Common
                      ${CORBA_LINK})


cmake_minimum_required(VERSION 3.0.0)
project(PAS VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++2a -fexec-charset=UTF-8")

include_directories(include)
aux_source_directory(src SRC)
add_executable(PAS ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.11)
project(R-Type VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(Engine)
add_subdirectory(Server)
add_subdirectory(Client)
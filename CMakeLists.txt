cmake_minimum_required(VERSION 3.23)
project(HW1)

set(CMAKE_CXX_STANDARD 23)

add_executable(HW1 header.hpp input.cpp encryption.cpp decryption.cpp)

cmake_minimum_required(VERSION 3.8)
project(RpnTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utils/ErrorableValue.h)
add_executable(RpnTree ${SOURCE_FILES})
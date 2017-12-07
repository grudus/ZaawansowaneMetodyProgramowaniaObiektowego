cmake_minimum_required(VERSION 3.8)
project(LiveCodeLab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CiCanCopy.cpp CiCanCopy.h)
add_executable(LiveCodeLab ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.8)
project(ZaawansowaneMetodyProgramowaniaObiektowego)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RzadkiWektor.h RzadkiWektor.cpp UserInterface.h UserInterface.cpp)
add_executable(ZaawansowaneMetodyProgramowaniaObiektowego ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.16)
project(LHW)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio)



add_executable(LHW main.cpp menu.cpp menu.h )


target_link_libraries(LHW sfml-graphics sfml-audio)
cmake_minimum_required(VERSION 3.5)
project(mutex)
set(CMAKE_CXX_FLAGS "-pthread")
add_executable(${PROJECT_NAME} main.cpp)
cmake_minimum_required(VERSION 3.16)
project(atomic)
add_executable(${PROJECT_NAME} atomic.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -pthread)
target_link_options(${PROJECT_NAME} PRIVATE -pthread)
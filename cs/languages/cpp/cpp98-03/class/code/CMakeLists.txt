cmake_minimum_required(VERSION 3.16)
project(class)
add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/encapsulation.cpp 
    src/extern_c.c
    src/person.cpp
    )

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/inc
)
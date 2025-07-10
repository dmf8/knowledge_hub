option(CMAKE_MODULE "whether to use .cmake file in sub dirs")

cmake_minimum_required(VERSION 3.5)
project(mlsa)

if(CMAKE_MODULE)
    message("test")
else()
    add_executable(
        ${PROJECT_NAME} 
        main.cpp sub1/test_class1.cpp sub1/sub2/test_class2.cpp
    )
    target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/sub1/include
    )
endif()
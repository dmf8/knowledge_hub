option(CMAKE_MODULE "whether to use .cmake file in sub dirs")

cmake_minimum_required(VERSION 3.5)
project(mlsa)

if(CMAKE_MODULE)
    set(SRCS "")
    set(INCS "")
    list(APPEND SRCS "main.cpp")
    include(${CMAKE_CURRENT_LIST_DIR}/sub1/sub1.cmake)
    add_executable(
        ${PROJECT_NAME} 
        ${SRCS}
    )
    target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${INCS}
    )
else()
    add_executable(
        ${PROJECT_NAME} 
        main.cpp sub1/src/test_class1.cpp sub1/sub2/src/test_class2.cpp
    )
    target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/sub1/include
        ${CMAKE_CURRENT_SOURCE_DIR}/sub1/sub2/include
    )
endif()
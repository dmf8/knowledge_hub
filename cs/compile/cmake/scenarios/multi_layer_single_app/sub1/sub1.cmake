list(APPEND SRCS "${CMAKE_CURRENT_LIST_DIR}/src/test_class1.cpp")
list(APPEND INCS "${CMAKE_CURRENT_LIST_DIR}/include")
include(${CMAKE_CURRENT_LIST_DIR}/sub2/sub2.cmake)

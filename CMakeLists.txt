cmake_minimum_required(VERSION 3.9)
project(osc VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

include(CTest)
enable_testing()

add_executable(osc 
    main.cpp 
    send.cpp 
    receive.cpp
    transport.cpp
)
target_include_directories(osc PRIVATE include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.20)
project(demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 소스/헤더
set(SRC
        src/main.cpp
        src/custom_vector.cpp
        src/custom_queue.cpp
)
set(HDR
        src/custom_vector.h
        src/custom_queue.h
)

add_executable(demo ${SRC} ${HDR})
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 디버그 전용 경고/심볼
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options(demo PRIVATE -Wall -Wextra -Wpedantic -O0 -g)
    endif()
endif()
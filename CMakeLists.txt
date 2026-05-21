cmake_minimum_required(VERSION 3.10)
project(Add2Num VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(add2num src/main.cpp src/MyBigNumber.cpp)
target_include_directories(add2num PRIVATE src)

add_executable(test_add2num tests/test_my_big_number.cpp src/MyBigNumber.cpp)
target_include_directories(test_add2num PRIVATE src)

cmake_minimum_required(VERSION 3.23)
project(leeetcode_learn_cards)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/gtest)
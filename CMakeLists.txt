cmake_minimum_required(VERSION 3.10)
project(xenocheat)

add_library(xenocheat SHARED main.cpp)
target_link_libraries(xenocheat log)

cmake_minimum_required(VERSION 3.10.2)
project("xenocheat")

add_library(xenocheat SHARED main.cpp)

find_library(log-lib log)
find_library(android-lib android)
find_library(gles-lib GLESv2)
find_library(EGL-lib EGL)

target_link_libraries(
    xenocheat
    ${log-lib}
    ${android-lib}
    ${gles-lib}
    ${EGL-lib}
)

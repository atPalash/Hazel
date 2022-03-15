cmake_minimum_required(VERSION 3.5)

project(HazelApi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(HZ_PLATFORM_WINDOWS HZ_BUILD_DLL)

add_library(HazelApi SHARED src/HazelApi/core.h src/HazelApi/application.h src/HazelApi/entryPoint.h src/HazelApi/application.cpp src/hazel.h)

target_include_directories(HazelApi PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/HazelApi")

#target_compile_definitions(HazelApi PUBLIC HAZEL_API_VERSION=4)

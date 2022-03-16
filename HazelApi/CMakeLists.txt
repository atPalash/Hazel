cmake_minimum_required(VERSION 3.5)

project(HazelApi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(HZ_PLATFORM_WINDOWS HZ_BUILD_DLL)

add_library(${PROJECT_NAME} SHARED src/HazelApi/core.h src/HazelApi/application.h src/HazelApi/entryPoint.h src/HazelApi/log.h src/HazelApi/application.cpp src/HazelApi/log.cpp src/hazel.h)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/HazelApi" "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include")

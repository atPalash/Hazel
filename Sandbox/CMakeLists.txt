cmake_minimum_required(VERSION 3.5)

project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../HazelApi/src)

add_compile_definitions(HZ_PLATFORM_WINDOWS)

add_executable(Sandbox src/sandboxApp.cpp)


target_link_libraries(Sandbox PRIVATE HazelApi)

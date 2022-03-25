cmake_minimum_required(VERSION 3.5)

project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(HZ_PLATFORM_WINDOWS)

add_executable(${PROJECT_NAME} src/sandboxApp.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC HazelApi)

target_link_directories(${PROJECT_NAME} PRIVATE HazelApi)

target_link_libraries(${PROJECT_NAME} PRIVATE HazelApi)

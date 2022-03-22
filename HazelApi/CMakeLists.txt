cmake_minimum_required(VERSION 3.5)

project(HazelApi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(HZ_PLATFORM_WINDOWS HZ_BUILD_DLL)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src" "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include")


## Need to check if we need to include spdlog here
#target_link_directories(${PROJECT_NAME} PUBLIC spdlog/src)

#target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)

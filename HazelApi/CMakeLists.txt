cmake_minimum_required(VERSION 3.5)

project(HazelApi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(HZ_PLATFORM_WINDOWS HZ_BUILD_DLL)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/GLFW)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    message("opengl found")
    message("include dir: ${OPENGL_INCLUDE_DIR}")
    message("link libraries: ${OPENGL_gl_LIBRARY}")
else (OPENGL_FOUND)
    message("opengl not found")
endif()

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})
target_precompile_headers(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/hzpch.h")
target_include_directories(${PROJECT_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include"
)

target_link_directories(${PROJECT_NAME} PRIVATE vendor/GLFW/src)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw ${OPENGL_gl_LIBRARY})

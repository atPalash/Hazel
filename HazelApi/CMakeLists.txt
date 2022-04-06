cmake_minimum_required(VERSION 3.0.0)
project(HazelApi VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(HZ_PLATFORM_WINDOWS HZ_BUILD_DLL)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

add_library(HazelApi SHARED ${HEADERS} ${SOURCES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy
     $<TARGET_FILE:${PROJECT_NAME}>
     ../Sandbox/libHazelApi.dll
  COMMENT "Copying to output directory")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
include(CPack)

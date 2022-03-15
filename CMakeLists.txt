cmake_minimum_required(VERSION 3.5)

# top-level project
project(Hazel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############################################################################
# Hazel development environment helper
#
# Allows combining multiple project Hazel repositories into single development
# environment.

###############################################################################
# Check for projects in the given subdirectories
#
# The found projects are added to all_projects variable.
set(all_projects "")
function(find_projects)
    foreach(subdir IN LISTS ARGN)
        set(full_subdir "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}")
        if(IS_DIRECTORY "${full_subdir}")
            list(APPEND all_projects "${subdir}")
        endif()
    endforeach()

    set(all_projects ${all_projects} PARENT_SCOPE)
endfunction()

# Find supported projects from subdirectories
find_projects(
    "Sandbox"
    "HazelApi"
)

# add all found subdirectories
foreach(subdir ${all_projects})
    message(STATUS "Hazel development environment - Adding subdir: ${subdir}")
    add_subdirectory(${subdir})
endforeach()

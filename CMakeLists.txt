cmake_minimum_required (VERSION 3.6.2)

set(SOLUTION_NAME TamerDB) # this is the unique place where solution name is set
project(${SOLUTION_NAME})


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${HALLEY_PATH}/cmake/")


SET(PROJECT_VERSION_MAJOR "0")
SET(PROJECT_VERSION_MINOR "1")
SET(PROJECT_VERSION_PATCH "0")
message("Project ${PROJECT_NAME} version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
SET(${PROJECT_NAME}_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Specific system configurations
# UNIX and LINUX (any compiler)
if (UNIX)
    message("Unix system detected")
    include(cmake/unix.cmake)
endif(UNIX)

# WINDOWS (Microsoft Visual C compiler)
if(WIN32 AND MSVC)
    message("CMake Microsoft Visual Studio Compilation")
    include(cmake/windows-msvc.cmake)
endif(WIN32 AND MSVC)

# WINDOWS (MinGW, g++, c++ compilers)
if(WIN32 AND NOT(MSVC))
    message("MinGW, g++, c++ compilers")
    include(cmake/windows-mingw.cmake)
endif(WIN32 AND NOT(MSVC))

# cmake includes
include(cmake/OpenGL.cmake)
include(cmake/Qt.cmake)
include(cmake/Boost.cmake)
include(cmake/Project.cmake)

set(GLOBAL_PROJECT_NAME ${PROJECT_NAME})

add_subdirectory(source)

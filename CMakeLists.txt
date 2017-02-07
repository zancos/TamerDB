set(SOLUTION_NAME TamerDB)
project(${SOLUTION_NAME})
cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)

#set QT general options
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # always look for includes in the build folder

############################## Setup output directories
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single directory for all libraries")
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single directory for all executables")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/installation)
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

# ********* pruebas
# include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
# ********* pruebas

if (UNIX)
    message("Unix system detected")
elseif(WIN32 AND MSVC)
    message("CMake Microsoft Visual Studio Compilation")
    #enable multicore compilation
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TamerDB)
else(WIN32 AND MSVC)
    message("CMake g++ compilation")
endif(UNIX)

##############################  Include projects
#executables
set(GLOBAL_PROJECT_NAME ${PROJECT_NAME})

add_subdirectory(source)

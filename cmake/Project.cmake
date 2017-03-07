include(cmake/PrecompilerHeader.cmake)

add_definitions(-DUNICODE)

# C++11 support
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler-specific flags


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single directory for all libraries")
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single directory for all executables")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/installation)
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})



set(CMAKE_INCLUDE_CURRENT_DIR ON) # always look for includes in the build folder

# Setup output directories
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single directory for all libraries")
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single directory for all executables")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/installation)
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

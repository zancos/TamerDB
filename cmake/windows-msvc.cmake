set(CMAKE_PREFIX_PATH C:/Workspace/libs/Eigen-3.2.4; C:/Workspace/libs/Qt-5.7/msvc2013_64; C:/Workspace/libs/glm-0.9.8.3/glm/cmake; C:/Workspace/libs/boost_1_63_0-msvc12)

#enable multicore compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

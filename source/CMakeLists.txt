project(TamerDB)
add_definitions(-DUNICODE)

if (UNIX)
    set(CMAKE_PREFIX_PATH /opt/Qt/5.7/gcc_64)
    # set(CMAKE_PREFIX_PATH /opt/Eigen-3.2.4; /opt/Qt/5.7/gcc_64)
elseif(WIN32 AND MSVC)
    set(CMAKE_PREFIX_PATH C:/Workspace/libs/Eigen-3.2.4; C:/Workspace/libs/Qt-5.7/msvc2013_64; C:/Workspace/libs/glm-0.9.8.3/glm/cmake)
else(WIN32 AND MSVC)
    set(CMAKE_PREFIX_PATH C:/Workspace/libs/Eigen-3.2.4; C:/Workspace/libs/Qt-5.7/mingw53_32; C:/Workspace/libs/glm-0.9.8.3/glm/cmake)
endif(UNIX)

find_package(OpenGL REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Sql REQUIRED)
# find_package(GLM REQUIRED)

# Currently does not works for UNIX option
# find_package(Eigen REQUIRED CONFIG)

file(GLOB HDRS_FILES *.h)
file(GLOB HDRS_IMPL_FILES *.hpp)
file(GLOB SRCS_FILES *.cpp)
file(GLOB UI_FILES *.ui)
file(GLOB CD_FILES *.cd)
file(GLOB RSCS *.qsc)

QT5_ADD_RESOURCES(RSC_SRCS ${RSCS})
QT5_WRAP_UI(UI_HDRS ${UI_FILES})

SOURCE_GROUP("UI Files" FILES ${UI_FILES})
SOURCE_GROUP("Generated Files" FILES ${UI_HDRS} ${RSC_SRCS})
SOURCE_GROUP("Header Impl Files" FILES ${HDRS_IMPL_FILES})
SOURCE_GROUP("Class Diagrams" FILES ${CD_FILES})

ADD_EXECUTABLE(${PROJECT_NAME} ${HDRS_FILES} ${SRCS_FILES} ${HDRS_IMPL_FILES} ${UI_HDRS} ${RSC_SRCS} ${CD_FILES})

SET(ALL_HDR "")
LIST(APPEND ALL_HDR "${HDRS_FILES}")
LIST(APPEND ALL_HDR "${HDRS_IMPL_FILES}")

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${ALL_HDR}")
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "${GLOBAL_PROJECT_NAME}")

TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL Qt5::Sql ${OPENGL_LIBRARIES})

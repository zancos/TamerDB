set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost COMPONENTS locale REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

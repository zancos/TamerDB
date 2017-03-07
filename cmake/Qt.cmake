set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Sql REQUIRED)

foreach(plugin ${Qt5Network_PLUGINS})
  message(${plugin})
  #get_target_property(_loc ${plugin} LOCATION)
  #message("Plugin ${plugin} is at location ${_loc}")
endforeach()

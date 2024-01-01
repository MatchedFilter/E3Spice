cmake_minimum_required(VERSION 3.16)

project(E3SpiceApp)

add_subdirectory(E3WidgetsLib)
add_subdirectory(E3SpiceLib)
add_subdirectory(E3Spice)

install(TARGETS E3Spice DESTINATION ${CMAKE_SOURCE_DIR}/bin/)
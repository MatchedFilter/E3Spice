cmake_minimum_required(VERSION 3.16)

project (E3SpiceLib)

file(GLOB_RECURSE E3SPICE_LIB_SRCS src/*.cpp)
file(GLOB_RECURSE E3SPICE_LIB_SRC_HDRS src/*.h)
file(GLOB_RECURSE E3SPICE_LIB_HDRS include/*.h)

add_library(${PROJECT_NAME}
    ${E3SPICE_LIB_SRCS}
    ${E3SPICE_LIB_SRC_HDRS}
    ${E3SPICE_LIB_HDRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC E3WidgetsLib)

target_include_directories(${PROJECT_NAME} PUBLIC include)

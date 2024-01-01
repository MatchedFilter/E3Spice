cmake_minimum_required(VERSION 3.16)

project (E3Spice)

file(GLOB_RECURSE E3SPICE_LIB_SRCS src/*.cpp)
file(GLOB_RECURSE E3SPICE_LIB_SRC_HDRS src/*.h)

add_executable(${PROJECT_NAME}
    ${E3SPICE_LIB_SRCS}
    ${E3SPICE_LIB_SRC_HDRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC E3SpiceLib)

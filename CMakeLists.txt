cmake_minimum_required(VERSION 3.1)
project(gfs C CXX)

file(GLOB SOURCES "src/*.cpp")

# GLFW
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/libs/glfw)
add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_DIR}/include)

# GLAD
set(GLAD_DIR ${CMAKE_SOURCE_DIR}/libs/glad)
file(GLOB GLAD_SOURCES libs/glad/src/gl.c)
include_directories(${GLAD_DIR}/include)

add_executable(${PROJECT_NAME} ${SOURCES} ${GLAD_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

cmake_minimum_required(VERSION 3.5)
project(GameFromScratch)

# Add all source files
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

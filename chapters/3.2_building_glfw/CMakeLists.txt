cmake_minimum_required(VERSION 3.15...3.30)

project(
  LearnOpenGl
  VERSION 1.0
  LANGUAGES CXX)

# add_library(MyLibExample simple_lib.cpp simple_lib.hpp)

add_executable(example src/simple_example.cpp src/glad/glad.c)

# Include self at src
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/src/)
# For GLAD/KHR
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_link_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/../../build_exports/usr/local/lib/)
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/../../build_exports/usr/local/include/)
# target_compile_options(example PRIVATE )
target_link_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)

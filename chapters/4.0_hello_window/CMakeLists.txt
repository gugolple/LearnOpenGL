cmake_minimum_required(VERSION 3.15...3.30)

project(
  LearnOpenGl
  VERSION 1.0
  LANGUAGES C CXX)

add_library(libglad STATIC src/glad/glad.c)
target_include_directories(libglad PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_include_directories(libglad PRIVATE ${CMAKE_SOURCE_DIR}/src/glad/)

add_executable(example src/simple_example.cpp)
target_link_libraries(example libglad)

# Include self at src
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/src/)
# For GLAD/KHR
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/include/)

# Local GLFW
target_link_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/../../build_exports/usr/local/lib/)
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/../../build_exports/usr/local/include/)

# Compile options
target_compile_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)
target_link_libraries(example -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)
target_link_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)

cmake_minimum_required(VERSION 3.15...3.30)

project(
  LearnOpenGl
  VERSION 1.0
  LANGUAGES C CXX)

# Compile independently the GLAD library
add_library(libglad STATIC src/glad/glad.c)
# There is no need to propagate the GLAD includes to the rest of the project
target_include_directories(libglad PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_include_directories(libglad PUBLIC ${CMAKE_SOURCE_DIR}/src/glad/)

# Main executable, if it is not in a library the source should be listed below
add_executable(example
	src/simple_example.cpp
	src/shader_program.cpp
	src/shader_unit.cpp
	src/drawable.cpp
)

# Add GLAD to tge naub executable
target_link_libraries(example libglad)

# Set the C++ version of the main executable for compilation
set_property(TARGET example PROPERTY CXX_STANDARD 20)

# Include self at src
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/src/)

# For GLAD/KHR headers
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/include/)

# Local GLFW build linking
target_link_directories(example PRIVATE
	${CMAKE_SOURCE_DIR}/../../build_exports/usr/local/lib/)
target_include_directories(example PRIVATE
	${CMAKE_SOURCE_DIR}/../../build_exports/usr/local/include/)

# Compile options, demanded by OpenGL in linux systems
target_compile_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	-lglfw3)
target_link_libraries(example -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)
target_link_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	-lglfw3)

# Copy shaders to final folder
# This only works on "cmake" calls
file(GLOB example_SHADERS "${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.glsl")
file(COPY ${example_SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

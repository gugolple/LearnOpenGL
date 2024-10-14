cmake_minimum_required(VERSION 3.15...3.30)

project(
	LearnOpenGl
	VERSION 1.0
	LANGUAGES C CXX)

set(CMAKE_CXX_CLANG_TIDY
	clang-tidy;
	-format-style='mozilla';
	-header-filter=${CMAKE_CURRENT_SOURCE_DIR};
	-checks=clang-analyzer-*,-clang-analyzer-cplusplus*;
	--fix;
)

# Compile independently the GLAD library
add_library(libglad STATIC src/glad/glad.c)
# There is no need to propagate the GLAD includes to the rest of the project
target_include_directories(libglad PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_include_directories(libglad PUBLIC ${CMAKE_SOURCE_DIR}/src/glad/)

# Copy shaders to final folder
# This only works on "cmake" calls
file(GLOB example_SHADERS "${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.glsl")
# Copy shaders, custom command as dependency of main executable
add_custom_command(
	OUTPUT ${PROJECT_BINARY_DIR}/.shaders
	DEPENDS ${example_SHADERS}
	COMMAND cp ${PROJECT_SOURCE_DIR}/shaders/* ${PROJECT_BINARY_DIR}/
	COMMAND touch -m ${PROJECT_BINARY_DIR}/.shaders 
)

# Main executable, if it is not in a library the source should be listed below
add_executable(example
	src/drawable.cpp
	src/logger.cpp
	src/shader_program.cpp
	src/shader_unit.cpp
	src/simple_example.cpp
	src/figures/triangle1.cpp
	src/figures/triangle2.cpp
	src/figures/triangle3.cpp
	# Add shader dependency
	${PROJECT_BINARY_DIR}/.shaders
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
set(GLAD_PATH "${CMAKE_SOURCE_DIR}/../../build_exports/usr/local")
target_link_directories(example PRIVATE ${GLAD_PATH}/lib/)
target_include_directories(example PRIVATE ${GLAD_PATH}/include/)

# Compile options, demanded by OpenGL in linux systems
target_compile_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	-lglfw3)
target_link_libraries(example -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)
target_link_options(example PRIVATE -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	-lglfw3)

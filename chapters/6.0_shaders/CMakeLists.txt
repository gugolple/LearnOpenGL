cmake_minimum_required(VERSION 3.15...3.30)

# Set the C++ version of the main executable for compilation
set(CXX_STANDARD 20)

# Global path to be available
set(LOCAL_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../../build_exports/usr/local")

project(
	LearnOpenGl
	VERSION 1.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_CLANG_TIDY
	clang-tidy;
	-format-style='mozilla';
	-header-filter=${CMAKE_CURRENT_SOURCE_DIR};
	-checks=clang-analyzer-*,-clang-analyzer-cplusplus*;
	--fix;
)

# Copy shaders to final folder

# We know all in figures we want to be available for compile and linking
file(GLOB FIGURE_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/figures/*.cpp")

# Copy shaders, custom command as dependency of main executable
# This only works on "cmake" calls
file(GLOB simple_SHADERS "${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.glsl")
add_custom_command(
	OUTPUT ${PROJECT_BINARY_DIR}/.shaders
	DEPENDS ${simple_SHADERS}
	COMMAND cp ${PROJECT_SOURCE_DIR}/shaders/* ${PROJECT_BINARY_DIR}/
	COMMAND touch -m ${PROJECT_BINARY_DIR}/.shaders 
)

add_library(core_shared
	OBJECT
	# All shared objects
	src/drawable.cpp
	src/logger.cpp
	src/shader_program.cpp
	src/shader_unit.cpp
	# Add all figures in one go
	${FIGURE_SRCS}
	# Add shader dependency
	${PROJECT_BINARY_DIR}/.shaders
)

# Main executable, if it is not in a library the source should be listed below
add_executable(simple
	src/simple_example.cpp
)
# Add GLAD to tge naub executable
target_link_libraries(simple libglad.a core_shared)

# Excercises executables
add_executable(ej1
	src/ej1.cpp
)
# Add GLAD to tge naub executable
target_link_libraries(ej1 libglad.a core_shared)

add_executable(ej2
	src/ej2.cpp
)
# Add GLAD to tge naub executable
target_link_libraries(ej2 libglad.a core_shared)

add_executable(ej3
	src/ej3.cpp
)
# Add GLAD to tge naub executable
target_link_libraries(ej3 libglad.a core_shared)

# Include self at src
target_include_directories(core_shared PUBLIC ${CMAKE_SOURCE_DIR}/src/)

# For GLAD/KHR headers
target_include_directories(core_shared PUBLIC ${CMAKE_SOURCE_DIR}/include/)

# Add all the local directorires for include and linking
target_link_directories(core_shared PUBLIC ${LOCAL_INCLUDE_PATH}/lib/)
target_include_directories(core_shared PUBLIC ${LOCAL_INCLUDE_PATH}/include/)

# Compile options, demanded by OpenGL in linux systems
target_compile_options(core_shared PUBLIC -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	-lglfw3)
target_link_libraries(core_shared PUBLIC -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lglfw3)
target_link_options(core_shared PUBLIC -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	-lglfw3)

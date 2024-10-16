cmake_minimum_required(VERSION 3.15...3.30)

################################################################################
########## Gloabal opts
################################################################################

# Set the C++ version of the main executable for compilation
set(CXX_STANDARD 20)

# Global path to be available
set(ROOT_PROJECT_DIR "${CMAKE_SOURCE_DIR}/../..")
set(LOCAL_INCLUDE_PATH "${ROOT_PROJECT_DIR}/build_exports/usr/local")
set(LEARNOPENGL_PATH "${ROOT_PROJECT_DIR}/LearnOpenGL")
set(LEARNOPENGL_RESOURCES "${LEARNOPENGL_PATH}/resources")
set(LEARNOPENGL_RESOURCES_TEXTURES "${LEARNOPENGL_RESOURCES}/textures")

project(
	LearnOpenGl
	VERSION 1.0
	LANGUAGES C CXX
)

# Add clang-tidy globally
set(CMAKE_CXX_CLANG_TIDY
	clang-tidy;
	-format-style='mozilla';
	-header-filter=${CMAKE_CURRENT_SOURCE_DIR};
	-checks=clang-analyzer-*,-clang-analyzer-cplusplus*;
	--fix;
)

################################################################################
########## Texture copy
################################################################################

set(TEXTURES_LIST
	${LEARNOPENGL_RESOURCES_TEXTURES}/brickwall.jpg
	${LEARNOPENGL_RESOURCES_TEXTURES}/container.jpg
)
# Copy shaders, custom command as dependency of main executable
# This is a shell command, so no need to recreate the CMake
add_custom_command(
	OUTPUT ${PROJECT_BINARY_DIR}/.textures
	DEPENDS ${TEXTURES_LIST}
	COMMAND cp ${TEXTURES_LIST} ${PROJECT_BINARY_DIR}/
	COMMAND touch -m ${PROJECT_BINARY_DIR}/.textures
)

################################################################################
########## Shader copy
################################################################################

# Copy shaders, custom command as dependency of main executable
# This is a shell command, so no need to recreate the CMake
file(GLOB simple_SHADERS "${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.glsl")
add_custom_command(
	OUTPUT ${PROJECT_BINARY_DIR}/.shaders
	DEPENDS ${simple_SHADERS}
	COMMAND cp ${PROJECT_SOURCE_DIR}/shaders/* ${PROJECT_BINARY_DIR}/
	COMMAND touch -m ${PROJECT_BINARY_DIR}/.shaders 
)

################################################################################
########## General/Shared library and options
################################################################################

# We know all in figures we want to be available for compile and linking
file(GLOB FIGURE_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/figures/*.cpp")

# This library contains all the shared object files requested by the targets
add_library(core_shared
	OBJECT
	# All shared objects
	src/drawable.cpp
	src/logger.cpp
	src/shader_program.cpp
	src/shader_unit.cpp
	src/image_loader.cpp
	# Add all figures in one go
	${FIGURE_SRCS}
	# Add shader dependency
	${PROJECT_BINARY_DIR}/.shaders # Call to the shader handling
	${PROJECT_BINARY_DIR}/.textures # Call to the texture handling
)

# Add all compilation flags and propagate them to the targets
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

################################################################################
########## All targets
################################################################################

# Main executable, if it is not in a library the source should be listed below
add_executable(simple
	src/simple_example.cpp
)
# Add GLAD to tge naub executable
target_link_libraries(simple libglad.a core_shared)

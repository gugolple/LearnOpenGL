cmake_minimum_required(VERSION 3.15...3.30)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/../build_exports/usr/local/)

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
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/src/glad.c)
target_sources(
	glad 
	PUBLIC
		FILE_SET public_headers
		TYPE HEADERS
		BASE_DIRS src
		FILES
			src/glad.h
	)

# There is no need to propagate the GLAD includes to the rest of the project
target_include_directories(glad PRIVATE ${CMAKE_SOURCE_DIR}/include/)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/src/)

install(TARGETS glad FILE_SET public_headers)

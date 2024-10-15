.DEFAULT_GOAL := run

.PHONY: lint clean run debug run-build debug-build

lint:
	clang-format --style='mozilla' -i\
		src/*.cpp\
		src/*.hpp\
		src/figures/*.hpp\
		src/figures/*.cpp

build-debug/Makefile: CMakeLists.txt
	cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug

debug-build: lint build-debug/Makefile 
	cd build-debug ; make -j$(nproc)

debug: debug-build
	cd build-debug ; gdb ./simple

build/Makefile: CMakeLists.txt
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

run-build: lint build/Makefile
	cd build ; make -j$(nproc)

run: run-build
	cd build ; ./simple

all: debug-build run-build

clean:
	rm -rf build/ build-debug/

.PHONY: clean_shaders
clean_shaders:
	rm build/.shaders

copy_shaders: clean_shaders run

.PHONY: clean_figures
clean_figures:
	rm -f build/Makefile

copy_figures: clean_figures run

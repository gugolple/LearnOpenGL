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
	cd build-debug ; gdb ./example

build/Makefile: CMakeLists.txt
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

run-build: build/Makefile
	cd build ; make -j$(nproc)

run: run-build
	cd build ; ./example

all: debug-build run-build

clean:
	rm -rf build/ build-debug/

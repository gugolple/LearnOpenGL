.PHONY: lint clean run debug

lint:
	clang-format --style='mozilla' -i\
		src/*.cpp\
		src/*.hpp\
		src/figures/*.hpp\
		src/figures/*.cpp

build-debug/Makefile: CMakeLists.txt
	cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug

debug: build-debug/Makefile lint
	cd build-debug ; make -j$(nproc) && gdb ./example

build/Makefile: CMakeLists.txt
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

run: build/Makefile lint
	cd build ; make -j$(nproc) && ./example

clean:
	rm -rf build/ build-debug/

.PHONY: lint clean build build-debug debug-debug

lint:
	clang-format --style='mozilla' -i\
		src/*.cpp\
		src/*.hpp\
		src/figures/*.hpp\
		src/figures/*.cpp

build-debug/Makefile:
	cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug

build-debug: build-debug/Makefile
	cd build-debug ; make -j$(nproc) && ./example

debug-debug: build-debug/Makefile
	cd build-debug ; make -j$(nproc) && gdb ./example

build/Makefile:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

build: build/Makefile
	cd build ; make -j$(nproc) && ./example

clean:
	rm -rf build/ build-debug/

all: install
.PHONY: clean 

build/Makefile:
	cmake . -S . -B build/

build/libglad.a: build/Makefile
	cd build ; make -j$(nproc)

install: build/libglad.a
	cd build ; make install

clean:
	rm -rf build/

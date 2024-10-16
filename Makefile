all: glad glfw stb
.PHONY: glad glfw stb clean

stb:
	cp stb/stb_image.h build_exports/usr/local/include

glad:
	cd glad && make install

glfw/Makefile: GLFWMakefile
	cp GLFWMakefile glfw/Makefile

glfw: glfw/Makefile
	cd glfw && make install

clean: glfw/Makefile
	cd glad && make clean
	cd glfw && make clean
	rm -rf build_exports glfw/Makefile

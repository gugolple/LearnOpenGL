all: glad glfw
.PHONY: glad glfw clean

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

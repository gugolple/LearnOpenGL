# Intro

This project is just me following the 
[learnopengl](https://learnopengl.com/book/book_pdf.pdf) book, with the
objective of getting a small/classic game engine like first 3d games.

For all instructions '.' refers to the root folder of this repo. All paths
have been configured referentially.

# Structure

This will only contain the excercises from the book, each one in a different
folder. All of this is under [chapters](./chapters/).

# Setup

Compile GLFW normally and then I have setted it up to use the relative path at
this unit of './build_exports/'. For that install it with (expected to be run at 
'./glfw/build/':

```{=sh}
make DESTDIR=../../build_exports/ install
```

You will probably need to follow the instructions given by the book due to
glfw not being the most trivial unit to compile.

# Compiling

For all the chapters there is a CMakeLists.txt file. the way I have
setted it up to work is to invoke cmake and create a subdirectory with
**build** in the name. This are the two most common invocations I use:

```{=sh}
# This at the chapter level so CMakeLists.txt is at current level
# For normal compilation with -Os as default of cmake
cmake -S . -B build
# For the debugging needs.
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug 
```

Additionally, when debuggin compile errors, do not forget to check the compiler
call to verify the correct includes are being used.
```{=sh}
# The basic
make VERBOSE=1

# If you want it to see in a terminal editor
make VERBOSE=1 | vim -

# If you want to see errors included
make VERBOSE=1 2>&1 | vim -
```

# Sources
- [learnopengl](https://learnopengl.com/book/book_pdf.pdf)

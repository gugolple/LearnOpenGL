# Common targets

This was to make run and debug easier, so the following targets are available:

- run
- debug
- lint

Lint is automatically run when the other two are called, before them.

# Common problems and solutions

## New source files not detected

Either add them manually to CMakeLists.txt or if already automatically globbed
by CMake then **rm <build>/Makefile** will retrigger the CMake call and add
the new files to compilation.

## New shader not detected

Again, CMake only knows the environment when called, for that we have a trigger
attached to **<build>/.shaders**. If removed it will trigger a copy of all 
shaders in **shaders/**.

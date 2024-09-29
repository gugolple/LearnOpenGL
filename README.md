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

For the compilation of the chapter units have already been setted up to search
for the files at the specified location.

# Sources
- [learnopengl](https://learnopengl.com/book/book_pdf.pdf)

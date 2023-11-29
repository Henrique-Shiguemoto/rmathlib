# rmathlib.h

This is a simple header-only math library for my projects.

## How to Use

Since this is header-only, you'll only need to get the <code>rmathlib.h</code> file and add it to your project.

If you want to use the default implementations of the library, you should add the code <code>#define RMATHLIB_IMPLEMENTATION</code> before including the .h file. If you want to implement your own math functions but use the same interface, then you won't need to do that.

See <code>main.c</code> for example of how to use the functions.

## Features

- 2D, 3D and 4D vector operations
- 2x2, 3x3 and 4x4 matrix operations
- Trigonometric functions (32 and 64 bit results)
- Random API
- Computer Graphics operations
- Planar Geometry operations
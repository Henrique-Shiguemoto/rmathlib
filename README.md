# Introduction to mthlib

This is a simple math library for myself (and I guess for everyone else too) to use in random math-dependent projects like games and game engines (which are the kinds of project I'm interested in).

The library is very simple at the moment and it could become much much better with time (faster and with more functionality). The main purpose is learning how to make static libraries for C (I will also test this library with C++ files) that I could actually use.

It supports simple 2D and 3D vector operations, trigonometric operations and some other convenient operations like clamping, square roots, conversion from degrees to radians, etc.

# How to Use

To use this library you'll have to get the following files and just copy them into your project: <code>mthlib.h</code> (for the function declarations and vector types definitions), <code>mthlib.c</code> (for the function implementations) and <code>defines.h</code> (for other #defines and typedefs used in the previous 2 files).

After this you'll have access to all the resources from this library.
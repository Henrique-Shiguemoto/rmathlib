#pragma once

/**
 * 
 * USEFUL TYPEDEFS AND DEFINES FOR EASE OF READABILITY AND ORGANIZATION
 * 
 * */

/**
 * 
 * TYPE DEFINITIONS (INSPIRED BY stdint.h)
 * 
 * */

typedef char i8;
typedef short i16;
typedef int i32;
typedef long int i64;
typedef float f32;
typedef double f64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct v2
{
    f32 x;
    f32 y;
} v2;

typedef struct v3
{
    f32 x;
    f32 y;
    f32 z;
} v3;

typedef struct v4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} v4;

/**
 * 
 * To initialize a matrix, you'll need to assign the number one by one 
 *  accessing each element by index OR you can declare a matrix and assign
 *  the "elem" member like this: mat2x2 m = {.elem = {1,2,3,4}} (mat2x2 is just an example)
 *  (This works for C99 or more updated versions of C)
 * 
 * */
typedef struct mat2x2
{
    f32 elem[4];
} mat2x2;

typedef struct mat3x3
{
    f32 elem[9];
} mat3x3;

typedef struct mat4x4
{
    f32 elem[16];
} mat4x4;

typedef v2 point2D;
typedef v3 point3D;
typedef v4 quaternion;

/**
 * 
 * FOR EDGE CASES, LIKE DIVISIONS BY ZERO
 * 
 * */

#define INFINITY ((float)(1e+300)*(1e+300))

/**
 * 
 * FOR EDGE CASES, LIKE DIVISIONS BY ZERO OF SQUARE ROOTS OF NEGATIVE NUMBERS
 * 
 * */

#define NAN (((float)(1e+300)*(1e+300))*(0.0f))

/**
 * 
 * APPROXIMATION OF PI
 * 
 * */

#define PI 3.141592653589793

/**
 * 
 * 1 DEGREE IN RADIANS (VERY USEFUL FOR ANGLE CONVERSIONS)
 * 
 * */

#define DEGREE_IN_RAD (PI/180)

/**
 * 
 * APPROXIMATION OF SQUARE ROOT OF 2
 * 
 * */

#define SQRT_2 1.414213562373095

/**
 * 
 * APPROXIMATION OF SQUARE ROOT OF 3
 * 
 * */

#define SQRT_3 1.732050807568877

/**
 * 
 * THE AMOUNT OF DECIMAL PLACES NECESSARY FOR SOME OF THE CALCULATIONS IN THE CODE BASE
 * 		USED IN SQUARE ROOT CALCULATIONS
 * 
 * */

#define PRECISION 0.0000000001

/**
 * 
 * BIAS USED BY IEEE 754 32 BIT FLOATING POINT SYSTEM TO MAKE EXPONENTS OF FLOATS ALWAYS NON-NEGATIVE
 * 		USEFUL FOR SQUARE ROOT CALCULATIONS
 * 
 * */

#define BIAS32 127

/**
 * 
 * BIAS USED BY IEEE 754 64 BIT FLOATING POINT SYSTEM TO MAKE EXPONENTS OF FLOATS ALWAYS NON-NEGATIVE
 * 		USEFUL FOR SQUARE ROOT CALCULATIONS
 * 
 * */

#define BIAS64 1023

/**
 * 
 * NOT NECESSARY, JUST TO EASE THE READABILITY
 * 
 * */

#define TRUE 1

/**
 * 
 * NOT NECESSARY, JUST TO EASE THE READABILITY
 * 
 * */

#define FALSE 0

/**
 * 
 * FOR EDGE CASES WHERE A VECTOR RETURN IS NOT DEFINED
 * 		USEFUL IN CASES LIKE CALCULATING A UNIT VECTOR OF A ZERO VECTOR
 * 
 * */

#define INVALID_V2 (v2) {NAN, NAN}

/**
 * 
 * FOR EDGE CASES WHERE A VECTOR RETURN IS NOT DEFINED
 * 		USEFUL IN CASES LIKE CALCULATING A UNIT VECTOR OF A ZERO VECTOR
 * 
 * */

#define INVALID_V3 (v3) {NAN, NAN, NAN}

/**
 * 
 * FOR EDGE CASES WHERE A 2x2 MATRIX RETURN IS NOT DEFINED
 *      USEFUL IN CASES LIKE CALCULATING AN INVERSE OF MATRIX 
 *      WHICH DOES NOT HAVE AN INVERSE
 * 
 * */
#define INVALID_2X2MATRIX (mat2x2) \
            {.elem = \
            {NAN, NAN, \
             NAN, NAN}}

/**
 * 
 * FOR EDGE CASES WHERE A 3x3 MATRIX RETURN IS NOT DEFINED
 *      USEFUL IN CASES LIKE CALCULATING AN INVERSE OF MATRIX 
 *      WHICH DOES NOT HAVE AN INVERSE
 * 
 * */
#define INVALID_3X3MATRIX (mat3x3) \
            {.elem = \
            {NAN, NAN, NAN, \
             NAN, NAN, NAN, \
             NAN, NAN, NAN}}

/**
 * 
 * FOR EDGE CASES WHERE A 4x4 MATRIX RETURN IS NOT DEFINED
 *      USEFUL IN CASES LIKE CALCULATING AN INVERSE OF MATRIX 
 *      WHICH DOES NOT HAVE AN INVERSE
 * 
 * */
             
#define INVALID_4X4MATRIX (mat4x4) \
            {.elem = \
            {NAN, NAN, NAN, NAN, \
             NAN, NAN, NAN, NAN, \
             NAN, NAN, NAN, NAN, \
             NAN, NAN, NAN, NAN}}

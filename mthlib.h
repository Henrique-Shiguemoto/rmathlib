#pragma once

#include "defines.h"

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

typedef struct mat2x2
{
    f32 elem[2][2];
} mat2x2;

typedef struct mat3x3
{
    f32 elem[3][3];
} mat3x3;

typedef struct mat4x4
{
    f32 elem[4][4];
} mat4x4;

typedef v2 point2D;
typedef v3 point3D;
typedef v4 quaternion;

/**
 * 
 * 2D VECTOR ADDITION
 * 
 * */

v2 AddV2(v2 v1, v2 v2);

/**
 * 
 * 2D VECTOR SUBTRACTION
 * 
 * */

v2 SubtractV2(v2 v1, v2 v2);

/**
 * 
 * SCALAR MULTIPLICATION WITH 2D VECTOR
 * 
 * */

v2 ScaleV2(v2 v1, f32 scalar);

/**
 * 
 * 2D VECTOR DOT PRODUCT
 * 
 * */

f64 DotV2(v2 v1, v2 v2);

/**
 * 
 * NORM OF A 2D VECTOR
 * 
 * */

f64 NormV2(v2 v1);

/**
 * 
 * 2D UNIT VECTOR WITH THE SAME DIRECTION AS THE INPUT 2D VECTOR
 * 
 * */

v2 UnitV2(v2 v1);

/**
 * 
 * 3D VECTOR ADDITION
 * 
 * */

v3 AddV3(v3 v1, v3 v2);

/**
 * 
 * 3D VECTOR SUBTRACTION
 * 
 * */

v3 SubtractV3(v3 v1, v3 v2);

/**
 * 
 * SCALAR MULTIPLICATION WITH 3D VECTOR
 * 
 * */

v3 ScaleV3(v3 v1, f32 scalar);

/**
 * 
 * 3D VECTOR DOT PRODUCT
 * 
 * */

f64 DotV3(v3 v1, v3 v2);

/**
 * 
 * 3D VECTOR CROSS PRODUCT
 * 
 * */

v3 CrossV3(v3 v1, v3 v2);

/**
 * 
 * NORM OF A 3D VECTOR
 * 
 * */

f64 NormV3(v3 v1);

/**
 * 
 * 3D UNIT VECTOR WITH THE SAME DIRECTION AS THE INPUT 3D VECTOR
 * 
 * */

v3 UnitV3(v3 v1);

//Matrix Operations

/**
 * 
 * 2x2 Matrix Addition
 * 
 * */

mat2x2 AddMatrix2x2(mat2x2 m1, mat2x2 m2);

/**
 * 
 * 2x2 Matrix Subtraction
 * 
 * */

mat2x2 SubMatrix2x2(mat2x2 m1, mat2x2 m2);

/**
 * 
 * 2x2 Matrix Multiplication with Scalar
 * 
 * */

mat2x2 ScalarMultMatrix2x2(f64 scalar, mat2x2 m1);

/**
 * 
 * 2x2 Matrix with 2x2 Matrix Multiplication
 * 
 * */

mat2x2 MultMatrix2x2(mat2x2 m1, mat2x2 m2);

/**
 * 
 * 2x2 Matrix Determinant
 * 
 * */

f64 DetMatrix2x2(mat2x2 m1);

/**
 * 
 * 2x2 Matrix Transpose
 * 
 * */

mat2x2 TransposeMatrix2x2(mat2x2 m1);

/**
 * 
 * 2x2 Matrix Inverse
 * 
 * */

mat2x2 InverseMatrix2x2(mat2x2 m1);

/**
 * 
 * 2D Vector Multiplication with 2x2 Matrix
 *      Don't really like this function name
 * 
 * */

v2 MultV2ByMatrix2x2(v2 u, mat2x2 m1);

/**
 * 
 * 3x3 Matrix Addition
 * 
 * */

mat3x3 AddMatrix3x3(mat3x3 m1, mat3x3 m2);

/**
 * 
 * 3x3 Matrix Subtraction
 * 
 * */

mat3x3 SubMatrix3x3(mat3x3 m1, mat3x3 m2);

/**
 * 
 * 2x2 Matrix Multiplication with Scalar
 * 
 * */

mat3x3 ScalarMultMatrix3x3(f64 scalar, mat3x3 m1);

/**
 * 
 * 3x3 Matrix Multiplication
 * 
 * */

mat3x3 MultMatrix3x3(mat3x3 m1, mat3x3 m2);

/**
 * 
 * 3x3 Matrix Determinant
 * 
 * */

f64 DetMatrix3x3(mat3x3 m1);

/**
 * 
 * 3x3 Matrix Transpose
 * 
 * */

mat3x3 TransposeMatrix3x3(mat3x3 m1);

/**
 * 
 * 3x3 Matrix Inverse
 * 
 * */

mat3x3 InverseMatrix3x3(mat3x3 m1);

/**
 * 
 * 3D Vector Multiplication with 3x3 Matrix
 *      Don't really like this function name
 * 
 * */

v3 MultV3ByMatrix3x3(v3 u, mat3x3 m1);

/**
 * 
 * 4x4 Matrix Addition
 * 
 * */

mat4x4 AddMatrix4x4(mat4x4 m1, mat4x4 m2);

/**
 * 
 * 4x4 Matrix Subtraction
 * 
 * */

mat4x4 SubMatrix4x4(mat4x4 m1, mat4x4 m2);

/**
 * 
 * 4x4 Matrix Multiplication with Scalar
 * 
 * */

mat4x4 ScalarMultMatrix4x4(f64 scalar, mat4x4 m2);

/**
 * 
 * 4x4 Matrix Multiplication
 * 
 * */

mat4x4 MultMatrix4x4(mat4x4 m1, mat4x4 m2);

/**
 * 
 * 4x4 Matrix Determinant
 * 
 * */

f64 DetMatrix4x4(mat4x4 m1);

/**
 * 
 * 4x4 Matrix Transpose
 * 
 * */

mat4x4 TransposeMatrix4x4(mat4x4 m1);

/**
 * 
 * 4x4 Matrix Inverse
 * 
 * */

mat4x4 InverseMatrix4x4(mat4x4 m1);

/**
 * 
 * 4D Vector Multiplication with 4x4 Matrix
 *      Don't really like this function name
 * 
 * */

v4 MultV4ByMatrix4x4(v4 u, mat4x4 m1);

//Trig functions (we're not going to implement hyperbolics, hell no)

/**
 * 
 * SINE FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Sin32(f32 angleInRadians);

/**
 * 
 * COSINE FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Cos32(f32 angleInRadians);

/**
 * 
 * TANGENT FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Tg32(f32 angleInRadians);

/**
 * 
 * COSECANT FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Cosec32(f32 angleInRadians);

/**
 * 
 * SECANT FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Sec32(f32 angleInRadians);

/**
 * 
 * COTANGENT FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Cotg32(f32 angleInRadians);

/**
 * 
 * SINE FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Sin64(f64 angleInRadians);

/**
 * 
 * COSINE FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Cos64(f64 angleInRadians);

/**
 * 
 * TANGENT FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Tg64(f64 angleInRadians);

/**
 * 
 * COSECANT FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Cosec64(f64 angleInRadians);

/**
 * 
 * SECANT FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Sec64(f64 angleInRadians);

/**
 * 
 * COTANGET FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Cotg64(f64 angleInRadians);

//Other convenient functions

/**
 * 
 * ANGLE UNIT CONVERSION FROM DEGREES TO ANGLES WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 DegreesToRadians32(f32 degrees);

/**
 * 
 * SQUARE ROOT FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Sqrt32(f32 x);

/**
 * 
 * ABSOLUTE VALUE WITH 32 BIT FLOAT RETURN
 * 
 * */

f32	Abs32(f32 x);

/**
 * 
 * CLAMPING FUNCTION WITH 32 BIT FLOAT RETURN
 * 
 * */

f32 Clamp32(f32 min, f32 max, f32 value);

/**
 * 
 * FUNCTION RETURNS THE BIGGEST VALUE BETWEEN a AND b WITH 32 BIT FLOAT RETURN
 * 
 * */

f32	Max32(f32 a, f32 b);

/**
 * 
 * FUNCTION RETURNS THE SMALLEST VALUE BETWEEN a AND b WITH 32 BIT FLOAT RETURN
 * 
 * */

f32	Min32(f32 a, f32 b);

/**
 * 
 * RETURNS THE REMAINDER OF f1 WHEN DIVIDED BY f2 WITH 32 BIT FLOAT RETURN
 * 		IF positiveResult = TRUE, THEN THE RETURN VALUE WILL ALWAYS BE POSITIVE OR 0
 * 		OTHERWISE THE RETURN VALUES COULD BE NEGATIVE
 * 
 * */

f32 Mod32(f32 f1, f64 f2, u8 positiveResult);

/**
 * 
 * CEILING FUNCTION WITH 32 BIT INTEGER RETURN
 * 
 * */

i32 Ceil32(f32 x);

/**
 * 
 * FLOOR FUNCTION WITH 32 BIT INTEGER RETURN
 * 
 * */

i32 Floor32(f32 x);

/**
 * 
 * ROUNDING FUNCTION WITH 32 BIT INTEGER RETURN
 * 
 * */

i32 Round32(f32 x);

/**
 * 
 * ANGLE UNIT CONVERSION FROM DEGREES TO ANGLES WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 DegreesToRadians64(f64 degrees);

/**
 * 
 * SQUARE ROOT FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64	Sqrt64(f64 x);

/**
 * 
 * ABSOLUTE VALUE WITH 64 BIT FLOAT RETURN
 * 
 * */

f64	Abs64(f64 x);

/**
 * 
 * CLAMPING FUNCTION WITH 64 BIT FLOAT RETURN
 * 
 * */

f64 Clamp64(f64 min, f64 max, f64 value);

/**
 * 
 * FUNCTION RETURNS THE BIGGEST VALUE BETWEEN a AND b WITH 64 BIT FLOAT RETURN
 * 
 * */

f64	Max64(f64 a, f64 b);

/**
 * 
 * FUNCTION RETURNS THE SMALLEST VALUE BETWEEN a AND b WITH 64 BIT FLOAT RETURN
 * 
 * */

f64	Min64(f64 a, f64 b);

/**
 * 
 * RETURNS THE REMAINDER OF f1 WHEN DIVIDED BY f2 WITH 64 BIT FLOAT RETURN
 * 		IF positiveResult = TRUE, THEN THE RETURN VALUE WILL ALWAYS BE POSITIVE OR 0
 * 		OTHERWISE THE RETURN VALUES COULD BE NEGATIVE
 * 
 * */

f64 Mod64(f64 f1, f64 f2, u8 positiveResult);

/**
 * 
 * CEILING FUNCTION WITH 64 BIT INTEGER RETURN
 * 
 * */

i64 Ceil64(f64 x);

/**
 * 
 * FLOOR FUNCTION WITH 64 BIT INTEGER RETURN
 * 
 * */

i64 Floor64(f64 x);

/**
 * 
 * ROUNDING FUNCTION WITH 64 BIT INTEGER RETURN
 * 
 * */

i64 Round64(f64 x);
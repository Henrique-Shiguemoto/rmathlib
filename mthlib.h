#pragma once

#include "defines.h"

f64 GetPlatformTime(); //for now it works on linux and windows

/**
 * 
 * 2D VECTOR ADDITION
 * 
 * */

v2 AddV2(v2 u, v2 v);

/**
 * 
 * 2D VECTOR SUBTRACTION
 * 
 * */

v2 SubtractV2(v2 u, v2 v);

/**
 * 
 * SCALAR MULTIPLICATION WITH 2D VECTOR
 * 
 * */

v2 ScaleV2(v2 u, f32 scalar);

/**
 * 
 * 2D VECTOR DOT PRODUCT
 * 
 * */

f64 DotV2(v2 u, v2 v);

/**
 * 
 * NORM OF A 2D VECTOR
 * 
 * */

f64 NormV2(v2 u);

/**
 * 
 * 2D UNIT VECTOR WITH THE SAME DIRECTION AS THE INPUT 2D VECTOR
 * 
 * */

v2 UnitV2(v2 u);

/**
 * 
 * COMPARES EACH CORRESPONDING COMPONENT OF TWO 2D VECTORS BASED ON AN ERROR MARGIN
 * 
 * */

b8 CompareV2(v2 u, v2 v, f32 errorMargin);

/**
 * 
 * 3D VECTOR ADDITION
 * 
 * */

v3 AddV3(v3 u, v3 v);

/**
 * 
 * 3D VECTOR SUBTRACTION
 * 
 * */

v3 SubtractV3(v3 u, v3 v);

/**
 * 
 * SCALAR MULTIPLICATION WITH 3D VECTOR
 * 
 * */

v3 ScaleV3(v3 u, f32 scalar);

/**
 * 
 * 3D VECTOR DOT PRODUCT
 * 
 * */

f64 DotV3(v3 u, v3 v);

/**
 * 
 * 3D VECTOR CROSS PRODUCT
 * 
 * */

v3 CrossV3(v3 u, v3 v);

/**
 * 
 * NORM OF A 3D VECTOR
 * 
 * */

f64 NormV3(v3 u);

/**
 * 
 * 3D UNIT VECTOR WITH THE SAME DIRECTION AS THE INPUT 3D VECTOR
 * 
 * */

v3 UnitV3(v3 u);

/**
 * 
 * COMPARES EACH CORRESPONDING COMPONENT OF TWO 2D VECTORS BASED ON AN ERROR MARGIN
 * 
 * */

b8 CompareV3(v3 u, v3 v, f32 errorMargin);

/**
 * 
 * CONVERSION FROM V3 TO V2
 * 
 * */

v2 ConvertV3ToV2(v3 u);

/**
 * 
 * 4D VECTOR ADDITION
 * 
 * */

v4 AddV4(v4 u, v4 v);

/**
 * 
 * 4D VECTOR SUBTRACTION
 * 
 * */

v4 SubtractV4(v4 u, v4 v);

/**
 * 
 * SCALAR MULTIPLICATION WITH 4D VECTOR
 * 
 * */

v4 ScaleV4(v4 u, f32 scalar);

/**
 * 
 * 4D VECTOR DOT PRODUCT
 * 
 * */

f64 DotV4(v4 u, v4 v);

/**
 * 
 * NORM OF A 4D VECTOR
 * 
 * */

f64 NormV4(v4 u);

/**
 * 
 * 4D UNIT VECTOR WITH THE SAME DIRECTION AS THE INPUT 4D VECTOR
 * 
 * */

v4 UnitV4(v4 u);

/**
 * 
 * COMPARES EACH CORRESPONDING COMPONENT OF TWO 3D VECTORS BASED ON AN ERROR MARGIN
 * 
 * */

b8 CompareV4(v4 u, v4 v, f32 errorMargin);

/**
 * 
 * CONVERSION FROM V4 TO V3
 * 
 * */

v3 ConvertV4ToV3(v4 u);

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

f32 DetMatrix2x2(mat2x2 m1);

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
 * RETURNS THE 2x2 IDENTITY MATRIX
 * 
 * */
mat2x2 CreateIdentity2x2();

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

f32 DetMatrix3x3(mat3x3 m1);

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
 * RETURNS THE 3x3 IDENTITY MATRIX
 * 
 * */
mat3x3 CreateIdentity3x3();

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

mat4x4 ScalarMultMatrix4x4(f64 scalar, mat4x4 m1);

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

f32 DetMatrix4x4(mat4x4 m1);

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

/**
 * 
 * RETURNS THE 4x4 IDENTITY MATRIX
 * 
 * */
mat4x4 CreateIdentity4x4();

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

/**
 * 
 * FUNCTION THAT RETURNS THE SIGN OF A NUMBER
 *      SINCE THE RETURN VALUE CAN ONLY BE -1 OR 1, WE'RE RETURNING A i8 here
 *      ALSO, THE RETURN VALUE FOR 0 IS GOING TO BE 1 IN THIS CASE
 * */

i8 Sign(f64 x);

//RANDOM FUNCTIONS

/**
 * 
 * RETURNS A RANDOM 32 BIT UNSIGNED INTEGER
 * 
 * */
u32 RandomU32();

/**
 * 
 * RETURNS A RANDOM 32 BIT UNSIGNED INTEGER IN AN INTERVAL
 * 
 * */
u32 RandomU32InInterval(u32 min, u32 max);

/**
 * 
 * RETURNS A RANDOM BOOLEAN VALUE
 * 
 * */
b8 RandomBool();

/**
 * 
 * RETURNS A RANDOM SIGN (-1 OR 1)
 * 
 * */
i8 RandomSign();

//GRAPHICS FUNCTIONS

/**
 * 
 * CREATION OF A 3x3 MATRIX WHICH CAN TRANSLATE A 2D POINT (IN HOMOGENEOUS COORDINATE FORM) posDelta UNITS
 * 
 * */
mat3x3 CreateTranslationMatrix2D(v2 posDelta);

/**
 * 
 * CREATION OF A 3x3 MATRIX WHICH CAN SCALE A 2D POINT (IN HOMOGENEOUS COORDINATE FORM) IN scale UNITS
 *      BASED ON origin
 * 
 * */
mat3x3 CreateScaleMatrixWithSetOrigin2D(v2 scale, v2 origin);

/**
 * 
 * CREATION OF A 3x3 MATRIX WHICH CAN SCALE A 2D POINT (IN HOMOGENEOUS COORDINATE FORM) IN scale UNITS
 *      BASED ON (0,0) AS ORIGIN
 * 
 * */
mat3x3 CreateScaleMatrix2D(v2 scale);

/**
 * 
 * CREATION OF A 3x3 MATRIX WHICH CAN ROTATE A 2D POINT (IN HOMOGENEOUS COORDINATE FORM) IN angleVec RAD
 *      BASED ON pos
 * 
 * */
mat3x3 CreateRotationAroundPointMatrix2D(f32 angleVec, v2 pos);

/**
 * 
 * CREATION OF A 3x3 MATRIX WHICH CAN ROTATE A 2D POINT (IN HOMOGENEOUS COORDINATE FORM) IN angleVec RAD
 *      BASED ON (0,0) AS ORIGIN
 * 
 * */
mat3x3 CreateRotationMatrix2D(f32 angleVec);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH TRANSLATES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN posDelta UNITS
 * 
 * */
mat4x4 CreateTranslationMatrix3D(v3 posDelta);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH SCALES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN scale UNITS
 * 
 * */
mat4x4 CreateScaleMatrix3D(v3 scale);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH ROTATES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN angle UNITS IN THE X AXIS
 * 
 * */
mat4x4 CreateEulerRotationInXMatrix3D(f32 angle);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH ROTATES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN angle UNITS IN THE Y AXIS
 * 
 * */
mat4x4 CreateEulerRotationInYMatrix3D(f32 angle);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH ROTATES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN angle UNITS IN THE Z AXIS
 * 
 * */
mat4x4 CreateEulerRotationInZMatrix3D(f32 angle);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH ROTATES A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) IN angle IN ALL THE AXIS
 *      (AXIS HIERARCHY IS X => Y => Z, Z IS THE MOST SIGNIFICANT)
 * 
 * */
mat4x4 CreateEulerRotationInXYZMatrix3D(v3 angles);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH PROJECTS A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) ONTO THE NEAR PLANE
 *      WITH PARALLEL PROJECTION
 * 
 * */
mat4x4 CreateParallelProjectionMatrix3D(f32 l, f32 r, f32 t, f32 b, f32 f, f32 n);

/**
 * 
 * CREATES A 4x4 MATRIX WHICH PROJECTS A 3D POINT (IN HOMOGENEOUS COORDINATE FORM) ONTO THE NEAR PLANE
 *      WITH PERSPECTIVE PROJECTION
 * 
 * */
mat4x4 CreatePerspectiveProjectionMatrix3D(f32 fovY, f32 aspectRatio, f32 f, f32 n);

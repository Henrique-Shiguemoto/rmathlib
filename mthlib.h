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
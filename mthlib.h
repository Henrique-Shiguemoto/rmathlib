#ifndef MTHLIB_H
#define MTHLIB_H

#define INFINITY 		((float)(1e+300)*(1e+300))
#define NAN 	 		((float)(INFINITY)*(0.0f))
#define PI 				3.141592653589793
#define DEGREE_IN_RAD 	(PI/180)
#define SQRT_2			1.414213562373095
#define SQRT_3			1.732050807568877

typedef char 				i8;
typedef short 				i16;
typedef int 				i32;
typedef long int 			i64;
typedef float 				f32;
typedef double 				f64;

typedef unsigned char 		u8;
typedef unsigned short 		u16;
typedef unsigned int 		u32;
typedef unsigned long int 	u64;

typedef struct vector2
{
	float x;
	float y;
} vector2;

typedef struct vector3
{
	float x;
	float y;
	float z;
} vector3;

vector2 	AddVector2(vector2 v1, vector2 v2);
vector2 	SubtractVector2(vector2 v1, vector2 v2);
vector2 	ScaleVector2(vector2 v1, f32 scalar);
f32 		DotVector2(vector2 v1, vector2 v2);
vector2 	CrossVector2(vector2 v1, vector2 v2);
f32 		NormVector2(vector2 v1);
vector2 	UnitVector2(vector2 v1);

vector3 	AddVector3(vector3 v1, vector3 v2);
vector3 	SubtractVector3(vector3 v1, vector3 v2);
vector3 	ScaleVector3(vector3 v1, f32 scalar);
f32 		DotVector3(vector3 v1, vector3 v2);
vector3 	CrossVector3(vector3 v1, vector3 v2);
f32 		NormVector3(vector3 v1);
vector3 	UnitVector3(vector3 v1);

f32 		Sin32(f32 angleInRadians);
f32 		Cos32(f32 angleInRadians);
f32 		Tg32(f32 angleInRadians);
f32 		Cossec32(f32 angleInRadians);
f32 		Sec32(f32 angleInRadians);
f32 		Cotg32(f32 angleInRadians);

f64 		Sin64(f64 angleInRadians);
f64 		Cos64(f64 angleInRadians);
f64 		Tg64(f64 angleInRadians);
f64 		Cossec64(f64 angleInRadians);
f64 		Sec64(f64 angleInRadians);
f64 		Cotg64(f64 angleInRadians);

//Other convenient functions

f32         AngleToRadians32(f32 degrees);
f64         AngleToRadians64(f64 degrees);

f32 		Sqrt32(f32 x);
f64			Sqrt64(f64 x);

f32			Abs32(f32 x);
f64			Abs64(f64 x);

f32 		Clamp32(f32 min, f32 max, f32 value);
f64 		Clamp64(f64 min, f64 max, f64 value);

f32			Max32(f32 a, f32 b);
f64			Max64(f64 a, f64 b);

f32			Min32(f32 a, f32 b);
f64			Min64(f64 a, f64 b);

i32 		Ceil32(f32 x);
i64 		Ceil64(f64 x);

i32 		Floor32(f32 x);
i64 		Floor64(f64 x);

#endif
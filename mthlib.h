#ifndef MTHLIB_H
#define MTHLIB_H

//#defines (NAN, INFINITY)

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

//Simple trig functions declarations (we could make new declarations accepting angles in degrees)

f32 		sin32(f32 angleInRadians);
f32 		cos32(f32 angleInRadians);
f32 		tg32(f32 angleInRadians);
f32 		cossec32(f32 angleInRadians);
f32 		sec32(f32 angleInRadians);
f32 		cotg32(f32 angleInRadians);

f64 		sin64(f64 angleInRadians);
f64 		cos64(f64 angleInRadians);
f64 		tg64(f64 angleInRadians);
f64 		cossec64(f64 angleInRadians);
f64 		sec64(f64 angleInRadians);
f64 		cotg64(f64 angleInRadians);

f32 		sqrt32(f32 x);
f64			sqrt64(f64 x);

f32			abs32(f32 x);
f64			abs64(f64 x);

#endif
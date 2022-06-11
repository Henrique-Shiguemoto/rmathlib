#include "mthlib.h"

//VECTOR2 IMPLEMENTATIONS

vector2	AddVector2(vector2 v1, vector2 v2){
	return (vector2){v1.x + v2.x, v1.y + v2.y};
}

vector2 SubtractVector2(vector2 v1, vector2 v2){
	return (vector2){v1.x - v2.x, v1.y - v2.y};
}

vector2	ScaleVector2(vector2 v1, f32 scalar){
	return (vector2){scalar*v1.x, scalar*v1.y};
}

f32 DotVector2(vector2 v1, vector2 v2){
	return (v1.x * v2.x) + (v1.y * v2.y);
}

//VECTOR3 IMPLEMENTATIONS

vector3 AddVector3(vector3 v1, vector3 v2){
	return (vector3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

vector3 SubtractVector3(vector3 v1, vector3 v2){
	return (vector3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

vector3 ScaleVector3(vector3 v1, f32 scalar){
	return (vector3){scalar*v1.x, scalar*v1.y, scalar*v1.z};
}

f32 DotVector3(vector3 v1, vector3 v2){
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

//CONVENIENT FUNCTIONS IMPLEMENTATIONS

f32 AngleToRadians32(f32 degrees){
	return degrees*DEGREE_IN_RAD;
}

f64 AngleToRadians64(f64 degrees){
	return degrees*DEGREE_IN_RAD;
}

f32 Sqrt32(f32 x){
	if(x == 0.0f || x == 1.0f) return x;
	if(x < 0) return NAN;

	return -1;
}

f64	Sqrt64(f64 x){
	if(x == 0.0f || x == 1.0f) return x;
	if(x < 0) return NAN;

	return -1;
}

f32	Abs32(f32 x){
	if(x < 0) return -x;
	return x;
}

f64	Abs64(f64 x){
	if(x < 0) return -x;
	return x;
}

f32 Clamp32(f32 min, f32 max, f32 value){
	if(value < min) return min;
	if(value > max) return max;
	return value;
}

f64 Clamp64(f64 min, f64 max, f64 value){
	if(value < min) return min;
	if(value > max) return max;
	return value;
}

f32	Max32(f32 a, f32 b){
	if(a > b) return a;
	return b;
}

f64	Max64(f64 a, f64 b){
	if(a > b) return a;
	return b;	
}

f32	Min32(f32 a, f32 b){
	if(a < b) return a;
	return b;
}

f64	Min64(f64 a, f64 b){
	if(a < b) return a;
	return b;
}

i32 Ceil32(f32 x){
	if(x < 0) return (i32)x;

	i32 i_x = (i32)x;
	if(x == (f32) i_x) return i_x;
	return i_x + 1;
}

i64 Ceil64(f64 x){
	if(x < 0) return (i64)x;

	i64 i_x = (i64)x;
	if(x == (f64) i_x) return i_x;
	return i_x + 1;
}

i32 Floor32(f32 x){
	i32 n = (i32)x;
    f32 d = (f32)n;
    if (d == x || x >= 0) return (i32)d;
    return (i32)d - 1;
}

i64 Floor64(f64 x){
	i64 n = (i64)x;
    f64 d = (f64)n;
    if (d == x || x >= 0) return (i64)d;
	return (i64)d - 1;
}

i32 Round32(f32 x){
	if(x < 0) return (i32) (x - 0.5f);
	return (i32) (x + 0.5f);
}

i64 Round64(f64 x){
	if(x < 0) return (i64) (x - 0.5f);
	return (i64) (x + 0.5f);
}
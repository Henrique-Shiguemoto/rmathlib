#include <math.h>
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

//TRIG FUNCTIONS IMPLEMENTATIONS
static f64 static_Sin64(f64 angle){
    //McLaurin's Series with Horner's Scheme
    f64 y = angle*angle;

    f64 if3 = -1.0/6.0;
    f64 if5 = 1.0/120.0;
    f64 if7 = -1.0/5040.0;
    f64 if9 = 1.0/362880.0;
    f64 if11 = -1.0/39916800.0;

    return (angle + angle*y*(if3 + y*(if5 + y*(if7 + y*(if9 + y*if11)))));
}

static f64 static_Cos64(f64 angle){
	//McLaurin's Series with Horner's Scheme
    f64 y = angle*angle;

    f64 if2 = -0.5;
    f64 if4 = 1.0/24.0;
    f64 if6 = -1.0/720.0;
    f64 if8 = 1.0/40320.0;
    f64 if10 = -1.0/3628800.0;
    f64 if12 = 1.0/479001600.0;

    return (1 + y*(if2 + y*(if4 + y*(if6 + y*(if8 + y*(if10 + y*if12))))));
}

f32 Sin32(f32 angleInRadians)		{ return (f32)Sin64(angleInRadians); }
f32 Cos32(f32 angleInRadians)		{ return (f32)Cos64(angleInRadians); }
f32 Tg32(f32 angleInRadians)		{ return (f32)Tg64(angleInRadians); }
f32 Cosec32(f32 angleInRadians)		{ return (f32)Cosec64(angleInRadians); }
f32 Sec32(f32 angleInRadians)		{ return (f32)Sec64(angleInRadians); }
f32 Cotg32(f32 angleInRadians)		{ return (f32)Cotg64(angleInRadians); }

f64 Sin64(f64 angleInRadians){
	//For precision purposes I want to make sure that angleInRadians is in a good interval
	//This interval for us is going to be [-PI/4, PI/4]
	//(the bigger angleInRadians, the less precise our calculations are)
	f64 angle = Mod64(angleInRadians, 2*PI, TRUE);
	
	if ((PI < angle) && (angle < 2*PI)) angle = -(2*PI - angle);

	if((-PI/4 <= angle) && (angle <= PI/4)){
		return static_Sin64(angle);
	}else if((PI/4 < angle) && (angle <= 3*PI/4)){
		return static_Cos64(angle - PI/2);
	}else if((3*PI/4 < angle) && (angle <= PI)){
		return static_Sin64(angle - PI)*(-1);
	}else if((-3*PI/4 < angle) && (angle < -PI/4)){
		return static_Cos64(PI/2 + angle)*(-1);
	}

	return static_Sin64(PI + angle)*(-1);
}

f64	Cos64(f64 angleInRadians){
	//For precision purposes I want to make sure that angleInRadians is in a good interval
	//This interval for us is going to be [-PI/4, PI/4]
	//(the bigger angleInRadians, the less precise our calculations are)
	f64 angle = Mod64(angleInRadians, 2*PI, TRUE);
	if ((PI < angle) && (angle < 2*PI)) angle = -(2*PI - angle);

	if((-PI/4 <= angle) && (angle <= PI/4)){
		return static_Cos64(angle);
	}else if((PI/4 < angle) && (angle <= 3*PI/4)){
		return static_Sin64(angle - PI/2)*(-1);
	}else if((-PI/4 > angle) && (angle >= -3*PI/4)){
		return static_Sin64(angle + PI/2);
	}else if((3*PI/4 < angle) && (angle <= PI)){
		return static_Cos64(angle - PI)*(-1);
	}
	return static_Cos64(angle + PI)*(-1);
}

//Unfortunetely I couldn't get it to be as precise as Sin and Cos.
//All the 4 next functions are not as precise as Sin and Cos, but we still have good results for
//		simples problems at least, We are getting error in the 6+th decimal place
//All the series expansions I tried are only good for very limited intervals of angles 
//		(Which I definetely don't want)
f64 Tg64(f64 angleInRadians){
	f64 s = Sin64(angleInRadians);
	f64 c = Cos64(angleInRadians);
	if(c == 0.0f) return INFINITY;
	return s / c;
}

f64	Cosec64(f64 angleInRadians){
	f64 s = Sin64(angleInRadians);
	if(s == 0.0) return NAN;
	return 1 / s;
}

f64	Sec64(f64 angleInRadians){
	f64 c = Cos64(angleInRadians);
	if(c == 0.0) return NAN;
	return 1.0 / c;
}

f64	Cotg64(f64 angleInRadians){
	f64 t = Tg64(angleInRadians);
	if(t == 0.0) return NAN;
	return 1.0 / t;
}

//CONVENIENT FUNCTIONS IMPLEMENTATIONS

static f64 static_Sqrt64(unionF64 x){
	//The number we want to know the square root of
	f64 arg = x.n;

	//We are extracting the exponent part of the floating point number (We are also getting rid of the BIAS)
	i64 e = x.bits.exponent - BIAS64;
	
	//This is going to be the number (1 + f) which is the mantissa plus 1. 
	//This is useful to get a great initial guess for the Newton-Raphson algorithm. 
	f64 f = 0;

    f64 rest = 1;
    
    if(e > 0){
        f = arg / (2 << (e - 1));
        
        //if exponent is even
        if((e & 1) == 0){
            rest = 1 << (e/2);
        }else{
            rest = SQRT_2*(1 << ((e-1)/2));
        }
    }
    else if(e < 0){
        f = arg * (2 << (-e - 1));
        
        //if exponent is even
        if((e & 1) == 0){
            rest = 1 / (1 << (-e/2));
        }else{
            rest = (SQRT_2 / 2)*(1.0 / (1 << -((e+1)/2)));
        }
    }
    //This is for the case where the input argument is already in the correct scientific notation
    //For example, 1.5 (base 10) = 1.1 (base 2) = 1.1 * 2^(0) (e = 0) . No need to change the number at all.
    else{
        f = arg;
    }

    //Newton Raphson Algorithm
    f64 xk = ((f - 1) / 2) + 1;
    f64 xk1 = (xk + (f/xk))/2;
    f64 error = Abs64(xk1 - xk);

    while (error > PRECISION)
    {
        xk = xk1;
        xk1 = (xk + (f/xk))/2;
        error = Abs64(xk1 - xk);
    }

	return xk1*rest;
}

f32 AngleToRadians32(f32 degrees)				{ return (f32)AngleToRadians64(degrees); }
f32 Sqrt32(f32 x)								{ return (f32)Sqrt64(x); }
f32	Abs32(f32 x)								{ return (f32)Abs64(x); }
f32 Clamp32(f32 min, f32 max, f32 value)		{ return (f32)Clamp64(min, max, value); }
f32	Max32(f32 a, f32 b)							{ return (f32)Max64(a, b); }
f32	Min32(f32 a, f32 b)							{ return (f32)Min64(a, b); }
f32 Mod32(f32 f1, f64 f2, u8 positiveResult)	{ return (f32)Mod64(f1, f2, positiveResult); }
i32 Ceil32(f32 x)								{ return (f32)Ceil64(x); }
i32 Floor32(f32 x)								{ return (i32)Floor64(x); }
i32 Round32(f32 x)								{ return (i32)Round64(x); }

f64 AngleToRadians64(f64 degrees){ 
	return degrees*DEGREE_IN_RAD;
}

f64	Sqrt64(f64 x){
	if(x == 0.0f || x == 1.0f) return x;
	if(x < 0.0f) return NAN;

	unionF64 x_union = {.n = x};

	return static_Sqrt64(x_union);
}

f64	Abs64(f64 x){
	if(x < 0) return -x;
	return x;
}

f64 Clamp64(f64 min, f64 max, f64 value){
	if(value < min) return min;
	if(value > max) return max;
	return value;
}

f64	Max64(f64 a, f64 b){
	if(a > b) return a;
	return b;
}

f64	Min64(f64 a, f64 b){
	if(a < b) return a;
	return b;
}

i64 Ceil64(f64 x){
	if(x < 0) return (i64)x;

	i64 i_x = (i64)x;
	if(x == (f64) i_x) return i_x;
	return i_x + 1;
}

i64 Floor64(f64 x){
	i64 n = (i64)x;
    f64 d = (f64)n;
    if (d == x || x >= 0) return (i64)d;
	return (i64)d - 1;
}

i64 Round64(f64 x){
	if(x < 0) return (i64) (x - 0.5f);
	return (i64) (x + 0.5f);
}

f64 Mod64(f64 f1, f64 f2, u8 positiveResult) {
	f64 result = f1 - (i64)(f1 / f2) * f2;
	if(positiveResult && result < 0) return (f2 + result);
	return result;
}
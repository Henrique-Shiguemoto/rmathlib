#include "mthlib.h"

//V2 IMPLEMENTATIONS

v2 AddV2(v2 u, v2 v)				{ return (v2){u.x + v.x, u.y + v.y}; }
v2 SubtractV2(v2 u, v2 v)			{ return (v2){u.x - v.x, u.y - v.y}; }
v2 ScaleV2(v2 u, f32 scalar)		{ return (v2){scalar*u.x, scalar*u.y}; }
f64 DotV2(v2 u, v2 v)				{ return (u.x * v.x) + (u.y * v.y); }
f64 NormV2(v2 u)					{ return Sqrt64((u.x*u.x) + (u.y*u.y)); }
v2 UnitV2(v2 u){ 
	f64 vectorNorm = NormV2(u);
	if(vectorNorm == 0.0f) return INVALID_V2;
	return (v2){ u.x / vectorNorm, u.y / vectorNorm};
}

//V3 IMPLEMENTATIONS

v3 AddV3(v3 u, v3 v)				{ return (v3){u.x + v.x, u.y + v.y, u.z + v.z}; }
v3 SubtractV3(v3 u, v3 v)			{ return (v3){u.x - v.x, u.y - v.y, u.z - v.z}; }
v3 ScaleV3(v3 u, f32 scalar)		{ return (v3){scalar*u.x, scalar*u.y, scalar*u.z}; }
f64 DotV3(v3 u, v3 v)				{ return (u.x * v.x) + (u.y * v.y) + (u.z * v.z); }
v3 CrossV3(v3 u, v3 v)				{ return (v3){ (u.y*v.z - u.z*v.y), -(u.x*v.z - u.z*v.x), (u.x*v.y - v.x*u.y)}; }
f64 NormV3(v3 u)					{ return Sqrt64((u.x*u.x) + (u.y*u.y) + (u.z*u.z)); }
v3 UnitV3(v3 u){
	f64 vectorNorm = NormV3(u);
	if(vectorNorm == 0.0f) return INVALID_V3;
	return (v3){ u.x / vectorNorm, u.y / vectorNorm, u.z / vectorNorm};
}

//2x2 MATRIX SUPPORT
mat2x2 AddMatrix2x2(mat2x2 m1, mat2x2 m2){
	mat2x2 output = { 0 };
	for(u8 i = 0; i < 4; i++)
		output.elem[i] = m1.elem[i] + m2.elem[i];
	return output;
}

mat2x2 SubMatrix2x2(mat2x2 m1, mat2x2 m2){
	mat2x2 output = { 0 };
	for(u8 i = 0; i < 4; i++)
		output.elem[i] = m1.elem[i] - m2.elem[i];
	return output;
}

mat2x2 ScalarMultMatrix2x2(f64 scalar, mat2x2 m1){
	mat2x2 output = {0};
	for(u8 i = 0; i < 4; i++)
		output.elem[i] = scalar*m1.elem[i];
	return output;
}

mat2x2 MultMatrix2x2(mat2x2 m1, mat2x2 m2){
	mat2x2 output = { 0 };
	output.elem[0] = m1.elem[0]*m2.elem[0] + m1.elem[1]*m2.elem[2];
	output.elem[1] = m1.elem[0]*m2.elem[1] + m1.elem[1]*m2.elem[3];
	output.elem[2] = m1.elem[2]*m2.elem[0] + m1.elem[3]*m2.elem[2];
	output.elem[3] = m1.elem[2]*m2.elem[1] + m1.elem[3]*m2.elem[3];
	return output;
}

f32 DetMatrix2x2(mat2x2 m1){
	return m1.elem[0]*m1.elem[3] - 
		   m1.elem[1]*m1.elem[2];
}

mat2x2 TransposeMatrix2x2(mat2x2 m1){
	mat2x2 output = { 0 };
	output.elem[0] = m1.elem[0];
	output.elem[1] = m1.elem[2];
	output.elem[2] = m1.elem[1];
	output.elem[3] = m1.elem[3];
	return output;
}

mat2x2 InverseMatrix2x2(mat2x2 m1){
	f64 det = DetMatrix2x2(m1);
	if(det == 0) return INVALID_2X2MATRIX;

	mat2x2 adjugate = { 0 };
	adjugate.elem[0] = m1.elem[3];
	adjugate.elem[1] = -m1.elem[1];
	adjugate.elem[2] = -m1.elem[2];
	adjugate.elem[3] = m1.elem[0];

	return ScalarMultMatrix2x2(1/det, adjugate);
}

v2 MultV2ByMatrix2x2(v2 u, mat2x2 m1){
	return (v2){u.x * m1.elem[0] + u.y * m1.elem[2], 
				u.x * m1.elem[1] + u.y * m1.elem[3]};
}

//3x3 MATRIX SUPPORT
mat3x3 AddMatrix3x3(mat3x3 m1, mat3x3 m2){
	mat3x3 output = {0};
	for(u8 i = 0; i < 9; i++)
		output.elem[i] = m1.elem[i] + m2.elem[i];
	return output;
}

mat3x3 SubMatrix3x3(mat3x3 m1, mat3x3 m2){
	mat3x3 output = {0};
	for(u8 i = 0; i < 9; i++)
		output.elem[i] = m1.elem[i] - m2.elem[i];
	return output;
}

mat3x3 ScalarMultMatrix3x3(f64 scalar, mat3x3 m1){
	mat3x3 output = {0};
	for(u8 i = 0; i < 9; i++)
		output.elem[i] = scalar*m1.elem[i];
	return output;
}

mat3x3 MultMatrix3x3(mat3x3 m1, mat3x3 m2){
	mat3x3 output = { 0 };

	output.elem[0] = m1.elem[0]*m2.elem[0] + m1.elem[1]*m2.elem[3] + m1.elem[2]*m2.elem[6];
	output.elem[1] = m1.elem[0]*m2.elem[1] + m1.elem[1]*m2.elem[4] + m1.elem[2]*m2.elem[7];
	output.elem[2] = m1.elem[0]*m2.elem[2] + m1.elem[1]*m2.elem[5] + m1.elem[2]*m2.elem[8];
	output.elem[3] = m1.elem[3]*m2.elem[0] + m1.elem[4]*m2.elem[3] + m1.elem[5]*m2.elem[6];
	output.elem[4] = m1.elem[3]*m2.elem[1] + m1.elem[4]*m2.elem[4] + m1.elem[5]*m2.elem[7];
	output.elem[5] = m1.elem[3]*m2.elem[2] + m1.elem[4]*m2.elem[5] + m1.elem[5]*m2.elem[8];
	output.elem[6] = m1.elem[6]*m2.elem[0] + m1.elem[7]*m2.elem[3] + m1.elem[8]*m2.elem[6];
	output.elem[7] = m1.elem[6]*m2.elem[1] + m1.elem[7]*m2.elem[4] + m1.elem[8]*m2.elem[7];
	output.elem[8] = m1.elem[6]*m2.elem[2] + m1.elem[7]*m2.elem[5] + m1.elem[8]*m2.elem[8];

	return output;
}

f32 DetMatrix3x3(mat3x3 m1){
	return m1.elem[0]*m1.elem[4]*m1.elem[8] + 
		   m1.elem[1]*m1.elem[5]*m1.elem[6] + 
		   m1.elem[2]*m1.elem[3]*m1.elem[7] -
		   m1.elem[6]*m1.elem[4]*m1.elem[2] -
		   m1.elem[7]*m1.elem[5]*m1.elem[0] -
		   m1.elem[8]*m1.elem[3]*m1.elem[1];
}

mat3x3 TransposeMatrix3x3(mat3x3 m1){
	mat3x3 output = { 0 };
	output.elem[0] = m1.elem[0];
	output.elem[1] = m1.elem[3];
	output.elem[2] = m1.elem[6];
	output.elem[3] = m1.elem[1];
	output.elem[4] = m1.elem[4];
	output.elem[5] = m1.elem[7];
	output.elem[6] = m1.elem[2];
	output.elem[7] = m1.elem[5];
	output.elem[8] = m1.elem[8];
	return output;
}

mat3x3 InverseMatrix3x3(mat3x3 m1){
	f64 det = DetMatrix3x3(m1);
	if(det == 0) return INVALID_3X3MATRIX;

	mat3x3 t = TransposeMatrix3x3(m1);

	f64 det00 = DetMatrix2x2((mat2x2){.elem = {t.elem[4], t.elem[5], t.elem[7], t.elem[8]}});
	f64 det01 = -DetMatrix2x2((mat2x2){.elem = {t.elem[3], t.elem[5], t.elem[6], t.elem[8]}});
	f64 det02 = DetMatrix2x2((mat2x2){.elem = {t.elem[3], t.elem[4], t.elem[6], t.elem[7]}});
	f64 det10 = -DetMatrix2x2((mat2x2){.elem = {t.elem[1], t.elem[2], t.elem[7], t.elem[8]}});
	f64 det11 = DetMatrix2x2((mat2x2){.elem = {t.elem[0], t.elem[2], t.elem[6], t.elem[8]}});
	f64 det12 = -DetMatrix2x2((mat2x2){.elem = {t.elem[0], t.elem[1], t.elem[6], t.elem[7]}});
	f64 det20 = DetMatrix2x2((mat2x2){.elem = {t.elem[1], t.elem[2], t.elem[4], t.elem[5]}});
	f64 det21 = -DetMatrix2x2((mat2x2){.elem = {t.elem[0], t.elem[2], t.elem[3], t.elem[5]}});
	f64 det22 = DetMatrix2x2((mat2x2){.elem = {t.elem[0], t.elem[1], t.elem[3], t.elem[4]}});

	mat3x3 adjugate = {.elem = {det00, -det01, det02, 
								-det10, det11, -det12, 
								det20, -det21, det22}};

	return ScalarMultMatrix3x3(1/det, adjugate);
}

v3 MultV3ByMatrix3x3(v3 u, mat3x3 m1){
	return (v3){ u.x * m1.elem[0] + u.y * m1.elem[3] + u.z * m1.elem[6],
				 u.x * m1.elem[1] + u.y * m1.elem[4] + u.z * m1.elem[7],
				 u.x * m1.elem[2] + u.y * m1.elem[5] + u.z * m1.elem[8]};
}

//4x4 MATRIX SUPPORT
mat4x4 AddMatrix4x4(mat4x4 m1, mat4x4 m2){
	mat4x4 output = {0};
	for(u8 i = 0; i < 16; i++)
		output.elem[i] = m1.elem[i] + m2.elem[i];
	return output;
}

mat4x4 SubMatrix4x4(mat4x4 m1, mat4x4 m2){
	mat4x4 output = {0};
	for(u8 i = 0; i < 16; i++)
		output.elem[i] = m1.elem[i] - m2.elem[i];
	return output;
}

mat4x4 ScalarMultMatrix4x4(f64 scalar, mat4x4 m1){
	mat4x4 output = {0};
	for(u8 i = 0; i < 16; i++)
		output.elem[i] = scalar*m1.elem[i];
	return output;
}

mat4x4 MultMatrix4x4(mat4x4 m1, mat4x4 m2){
	mat4x4 output = { 0 };

	output.elem[0] = m1.elem[0]*m2.elem[0] + m1.elem[1]*m2.elem[4] + m1.elem[2]*m2.elem[8] + m1.elem[3]*m2.elem[12];
	output.elem[1] = m1.elem[0]*m2.elem[1] + m1.elem[1]*m2.elem[5] + m1.elem[2]*m2.elem[9] + m1.elem[3]*m2.elem[13];
	output.elem[2] = m1.elem[0]*m2.elem[2] + m1.elem[1]*m2.elem[6] + m1.elem[2]*m2.elem[10] + m1.elem[3]*m2.elem[14];
	output.elem[3] = m1.elem[0]*m2.elem[3] + m1.elem[1]*m2.elem[7] + m1.elem[2]*m2.elem[11] + m1.elem[3]*m2.elem[15];
	output.elem[4] = m1.elem[4]*m2.elem[0] + m1.elem[5]*m2.elem[4] + m1.elem[6]*m2.elem[8] + m1.elem[7]*m2.elem[12];
	output.elem[5] = m1.elem[4]*m2.elem[1] + m1.elem[5]*m2.elem[5] + m1.elem[6]*m2.elem[9] + m1.elem[7]*m2.elem[13];
	output.elem[6] = m1.elem[4]*m2.elem[2] + m1.elem[5]*m2.elem[6] + m1.elem[6]*m2.elem[10] + m1.elem[7]*m2.elem[14];
	output.elem[7] = m1.elem[4]*m2.elem[3] + m1.elem[5]*m2.elem[7] + m1.elem[6]*m2.elem[11] + m1.elem[7]*m2.elem[15];
	output.elem[8] = m1.elem[8]*m2.elem[0] + m1.elem[9]*m2.elem[4] + m1.elem[10]*m2.elem[8] + m1.elem[11]*m2.elem[12];
	output.elem[9] = m1.elem[8]*m2.elem[1] + m1.elem[9]*m2.elem[5] + m1.elem[10]*m2.elem[9] + m1.elem[11]*m2.elem[13];
	output.elem[10] = m1.elem[8]*m2.elem[2] + m1.elem[9]*m2.elem[6] + m1.elem[10]*m2.elem[10] + m1.elem[11]*m2.elem[14];
	output.elem[11] = m1.elem[8]*m2.elem[3] + m1.elem[9]*m2.elem[7] + m1.elem[10]*m2.elem[11] + m1.elem[11]*m2.elem[15];
	output.elem[12] = m1.elem[12]*m2.elem[0] + m1.elem[13]*m2.elem[4] + m1.elem[14]*m2.elem[8] + m1.elem[15]*m2.elem[12];
	output.elem[13] = m1.elem[12]*m2.elem[1] + m1.elem[13]*m2.elem[5] + m1.elem[14]*m2.elem[9] + m1.elem[15]*m2.elem[13];
	output.elem[14] = m1.elem[12]*m2.elem[2] + m1.elem[13]*m2.elem[6] + m1.elem[14]*m2.elem[10] + m1.elem[15]*m2.elem[14];
	output.elem[15] = m1.elem[12]*m2.elem[3] + m1.elem[13]*m2.elem[7] + m1.elem[14]*m2.elem[11] + m1.elem[15]*m2.elem[15];

	return output;
}

f32 DetMatrix4x4(mat4x4 m1){
	return m1.elem[0]*m1.elem[5]*m1.elem[10]*m1.elem[15] + 
		   m1.elem[0]*m1.elem[9]*m1.elem[14]*m1.elem[7] + 
		   m1.elem[0]*m1.elem[13]*m1.elem[6]*m1.elem[11] - 
		   m1.elem[0]*m1.elem[13]*m1.elem[10]*m1.elem[7] - 
		   m1.elem[0]*m1.elem[9]*m1.elem[6]*m1.elem[15] - 
		   m1.elem[0]*m1.elem[5]*m1.elem[14]*m1.elem[11] - 
		   m1.elem[4]*m1.elem[1]*m1.elem[10]*m1.elem[15] - 
		   m1.elem[8]*m1.elem[1]*m1.elem[14]*m1.elem[7] - 
		   m1.elem[12]*m1.elem[1]*m1.elem[6]*m1.elem[11] + 
		   m1.elem[12]*m1.elem[1]*m1.elem[10]*m1.elem[7] + 
		   m1.elem[8]*m1.elem[1]*m1.elem[6]*m1.elem[15] + 
		   m1.elem[4]*m1.elem[1]*m1.elem[14]*m1.elem[11] + 
		   m1.elem[4]*m1.elem[9]*m1.elem[2]*m1.elem[15] + 
		   m1.elem[8]*m1.elem[13]*m1.elem[2]*m1.elem[7] + 
		   m1.elem[12]*m1.elem[5]*m1.elem[2]*m1.elem[11] - 
		   m1.elem[12]*m1.elem[9]*m1.elem[2]*m1.elem[7] - 
		   m1.elem[8]*m1.elem[5]*m1.elem[2]*m1.elem[15] - 
		   m1.elem[4]*m1.elem[13]*m1.elem[2]*m1.elem[11] - 
		   m1.elem[4]*m1.elem[9]*m1.elem[14]*m1.elem[3] - 
		   m1.elem[8]*m1.elem[13]*m1.elem[6]*m1.elem[3] - 
		   m1.elem[12]*m1.elem[5]*m1.elem[10]*m1.elem[3] + 
		   m1.elem[12]*m1.elem[9]*m1.elem[6]*m1.elem[3] + 
		   m1.elem[8]*m1.elem[5]*m1.elem[14]*m1.elem[3] + 
		   m1.elem[4]*m1.elem[13]*m1.elem[10]*m1.elem[3];
}

mat4x4 TransposeMatrix4x4(mat4x4 m1){
	mat4x4 output = { 0 };

	output.elem[0] = m1.elem[0];
	output.elem[1] = m1.elem[4];
	output.elem[2] = m1.elem[8];
	output.elem[3] = m1.elem[12];
	output.elem[4] = m1.elem[1];
	output.elem[5] = m1.elem[5];
	output.elem[6] = m1.elem[9];
	output.elem[7] = m1.elem[13];
	output.elem[8] = m1.elem[2];
	output.elem[9] = m1.elem[6];
	output.elem[10] = m1.elem[10];
	output.elem[11] = m1.elem[14];
	output.elem[12] = m1.elem[3];
	output.elem[13] = m1.elem[7];
	output.elem[14] = m1.elem[11];
	output.elem[15] = m1.elem[15];

	return output;
}

mat4x4 InverseMatrix4x4(mat4x4 m1){
	f32 det = DetMatrix4x4(m1);
	if(det == 0) return INVALID_4X4MATRIX;

	mat4x4 t = TransposeMatrix4x4(m1);

	f32 det00 = DetMatrix3x3((mat3x3){.elem = {t.elem[5], t.elem[6], t.elem[7],
											   t.elem[9], t.elem[10], t.elem[11],
											   t.elem[13], t.elem[14], t.elem[15]}});
	f32 det01 = -DetMatrix3x3((mat3x3){.elem = {t.elem[4], t.elem[6], t.elem[7],
											   t.elem[8], t.elem[10], t.elem[11],
											   t.elem[12], t.elem[14], t.elem[15]}});
	f32 det02 = DetMatrix3x3((mat3x3){.elem = {t.elem[4], t.elem[5], t.elem[7],
											   t.elem[8], t.elem[9], t.elem[11],
											   t.elem[12], t.elem[13], t.elem[15]}});
	f32 det03 = -DetMatrix3x3((mat3x3){.elem = {t.elem[4], t.elem[5], t.elem[6],
											   t.elem[8], t.elem[9], t.elem[10],
											   t.elem[12], t.elem[13], t.elem[14]}});
	f32 det10 = -DetMatrix3x3((mat3x3){.elem = {t.elem[1], t.elem[2], t.elem[3],
											   t.elem[9], t.elem[10], t.elem[11],
											   t.elem[13], t.elem[14], t.elem[15]}});
	f32 det11 = DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[2], t.elem[3],
											   t.elem[8], t.elem[10], t.elem[11],
											   t.elem[12], t.elem[14], t.elem[15]}});
	f32 det12 = -DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[1], t.elem[3],
											   t.elem[8], t.elem[9], t.elem[11],
											   t.elem[12], t.elem[13], t.elem[15]}});
	f32 det13 = DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[1], t.elem[2],
											   t.elem[8], t.elem[9], t.elem[10],
											   t.elem[12], t.elem[13], t.elem[14]}});
	f32 det20 = DetMatrix3x3((mat3x3){.elem = {t.elem[1], t.elem[2], t.elem[3],
											   t.elem[5], t.elem[6], t.elem[7],
											   t.elem[13], t.elem[14], t.elem[15]}});
	f32 det21 = -DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[2], t.elem[3],
											   t.elem[4], t.elem[6], t.elem[7],
											   t.elem[12], t.elem[14], t.elem[15]}});
	f32 det22 = DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[1], t.elem[3],
											   t.elem[4], t.elem[5], t.elem[7],
											   t.elem[12], t.elem[13], t.elem[15]}});
	f32 det23 = -DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[1], t.elem[2],
											   t.elem[4], t.elem[5], t.elem[6],
											   t.elem[12], t.elem[13], t.elem[14]}});
	f32 det30 = -DetMatrix3x3((mat3x3){.elem = {t.elem[1], t.elem[2], t.elem[3],
											   t.elem[5], t.elem[6], t.elem[7],
											   t.elem[9], t.elem[10], t.elem[11]}});
	f32 det31 = DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[2], t.elem[3],
											   t.elem[4], t.elem[6], t.elem[7],
											   t.elem[8], t.elem[10], t.elem[11]}});
	f32 det32 = -DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[1], t.elem[3],
											   t.elem[4], t.elem[5], t.elem[7],
											   t.elem[8], t.elem[9], t.elem[11]}});
	f32 det33 = DetMatrix3x3((mat3x3){.elem = {t.elem[0], t.elem[1], t.elem[2],
											   t.elem[4], t.elem[5], t.elem[6],
											   t.elem[8], t.elem[9], t.elem[10]}});

	mat4x4 adjugate = {.elem = { det00, det01, det02, det03, 
								 det10, det11, det12, det13,
								 det20, det21, det22, det23, 
								 det30, det31, det32, det33}};
	
	return ScalarMultMatrix4x4(1/det, adjugate);
}

v4 MultV4ByMatrix4x4(v4 u, mat4x4 m1){
	return (v4) { u.x * m1.elem[0] + u.y * m1.elem[4] + u.z * m1.elem[8] + u.w * m1.elem[12],
				  u.x * m1.elem[1] + u.y * m1.elem[5] + u.z * m1.elem[9] + u.w * m1.elem[13],
				  u.x * m1.elem[2] + u.y * m1.elem[6] + u.z * m1.elem[10] + u.w * m1.elem[14],
				  u.x * m1.elem[3] + u.y * m1.elem[7] + u.z * m1.elem[11] + u.w * m1.elem[15]};
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

//This is for the implementation of static_Sqrt64
typedef union unionF64{
	f64 n;
	struct{
		u64 mantissa : 52;
		u64 exponent : 11;
		u64 sign     : 1;
	}bits;
} unionF64;

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

f32 DegreesToRadians32(f32 degrees)				{ return (f32)DegreesToRadians64(degrees); }
f32 Sqrt32(f32 x)								{ return (f32)Sqrt64(x); }
f32	Abs32(f32 x)								{ return (f32)Abs64(x); }
f32 Clamp32(f32 min, f32 max, f32 value)		{ return (f32)Clamp64(min, max, value); }
f32	Max32(f32 a, f32 b)							{ return (f32)Max64(a, b); }
f32	Min32(f32 a, f32 b)							{ return (f32)Min64(a, b); }
f32 Mod32(f32 f1, f64 f2, u8 positiveResult)	{ return (f32)Mod64(f1, f2, positiveResult); }
i32 Ceil32(f32 x)								{ return (f32)Ceil64(x); }
i32 Floor32(f32 x)								{ return (i32)Floor64(x); }
i32 Round32(f32 x)								{ return (i32)Round64(x); }

f64 DegreesToRadians64(f64 degrees){ 
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

f64 Mod64(f64 f1, f64 f2, u8 positiveResult) {
	f64 result = f1 - (i64)(f1 / f2) * f2;
	if(positiveResult && result < 0) return (f2 + result);
	return result;
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

i8 Sign(f64 x){
	if(x < 0) return -1;
	return 1;
}
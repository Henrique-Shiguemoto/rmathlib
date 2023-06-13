#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	mat3x3 m1 = {.elem = {-5.18f, 2.3f, -4.7f, 7.45f, 3.24f, -9.51f, -6.01f, 6.03f, 8.56f}};
	mat3x3 m2 = {.elem = {-3.36f, -6.32f, 2.22f, -3.45f, -3.22f, -3.20f, -4.32f, 9.45f, -0.58f}};
	mat3x3 r = {0};
	// v3 u = {1.2f, -3.4f, 5.1f};
	// v3 r_v2 = {0};
	// f32 r_f = 0.0f;

	// mat3x3 AddMatrix3x3(mat3x3 m1, mat3x3 m2);
	// mat3x3 SubMatrix3x3(mat3x3 m1, mat3x3 m2);
	// mat3x3 ScalarMultMatrix3x3(f64 scalar, mat3x3 m1);
	// mat3x3 MultMatrix3x3(mat3x3 m1, mat3x3 m2);
	// f32 DetMatrix3x3(mat3x3 m1);
	// mat3x3 TransposeMatrix3x3(mat3x3 m1);
	// mat3x3 InverseMatrix3x3(mat3x3 m1);
	// v3 MultV3ByMatrix3x3(v3 u, mat3x3 m1);
	// mat3x3 CreateIdentity3x3();
	// b8 CompareMat3x3(mat3x3 m1, mat3x3 m2, f32 errorMargin);

	printf("%s tests done...\n", __FILE__);
	return 0;
}
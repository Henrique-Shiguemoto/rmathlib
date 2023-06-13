#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	mat3x3 m1 = {.elem = {-5.18f, 2.3f, -4.7f, 7.45f, 3.24f, -9.51f, -6.01f, 6.03f, 8.56f}};
	mat3x3 m2 = {.elem = {-3.36f, -6.32f, 2.22f, -3.45f, -3.22f, -3.20f, -4.32f, 9.45f, -0.58f}};
	mat3x3 r = {0};
	v3 u = {1.2f, -3.4f, 5.1f};
	v3 r_v3 = {0};
	f32 r_f = 0.0f;

	r = AddMatrix3x3(m1, m2);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {-8.54f, -4.02f, -2.48f, 4.0f, 0.02f, -12.71f, -10.33f, 15.48f, 7.98f}}, MTHLIB_LOW_PRECISION));
	
	r = SubMatrix3x3(m1, m2);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {-1.82f, 8.62f, -6.92f, 10.9f, 6.46f, -6.31f, -1.69f, -3.42f, 9.14f}}, MTHLIB_LOW_PRECISION));

	r = ScalarMultMatrix3x3(-5.8f, m1);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {30.044f, -13.34f, 27.26f, -43.21f, -18.792f, 55.158f, 34.858f, -34.974f, -49.648f}}, MTHLIB_LOW_PRECISION));

	r = MultMatrix3x3(m1, m2);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {29.7738f, -19.0834f, -16.1336f, 4.8732f, -147.3863f, 11.6868f, -37.5891f, 99.4586f, -37.603f}}, MTHLIB_LOW_PRECISION));
	
	r_f = DetMatrix3x3(m1);
	MTHLIB_ASSERT(Compare32(r_f, -758.592445f, MTHLIB_LOW_PRECISION));

	r = TransposeMatrix3x3(m1);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {-5.18f, 7.45f, -6.01f, 2.3f, 3.24f, 6.03f, -4.7f, -9.51f, 8.56f}}, MTHLIB_LOW_PRECISION));
	
	r = InverseMatrix3x3(m1);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {-0.112154f, 0.063313f, 0.008759f, 0.008722f, 0.095687f, 0.111096f, -0.084888f, -0.022953f, 0.044712f}}, MTHLIB_LOW_PRECISION));

	r_v3 = MultV3ByMatrix3x3(u, m1);
	MTHLIB_ASSERT(CompareV3(r_v3, (v3){-62.197f, 22.497f, 70.35f}, MTHLIB_LOW_PRECISION));
	
	r = CreateIdentity3x3();
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));

	printf("%s tests done...\n", __FILE__);
	return 0;
}
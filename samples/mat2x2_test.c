#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	mat2x2 m1 = {.elem = {-5.18f, 2.3f, -4.7f, 7.45f}};
	mat2x2 m2 = {.elem = {-3.36f, -6.32f, 2.22f, -3.45f}};
	mat2x2 r = {0};
	v2 u = {1.2f, -3.4f};
	v2 r_v2 = {0};
	f32 r_f = 0.0f;

	r = AddMatrix2x2(m1, m2);
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {-8.54f, -4.02f, -2.48f, 4.0f}}, MTHLIB_LOW_PRECISION));
	
	r = SubMatrix2x2(m1, m2);
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {-1.82f, 8.62f, -6.92f, 10.9f}}, MTHLIB_LOW_PRECISION));

	r = ScalarMultMatrix2x2(-6.3f, m1);
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {32.634f, -14.49f, 29.61f, -46.935f}}, MTHLIB_LOW_PRECISION));

	r = MultMatrix2x2(m1, m2);
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {22.5108f, 24.8026f, 32.331f, 4.0015f}}, MTHLIB_LOW_PRECISION));
	
	r_f = DetMatrix2x2(m1);
	MTHLIB_ASSERT(Compare32(r_f, -27.781f, MTHLIB_LOW_PRECISION));

	r = TransposeMatrix2x2(m1);
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {-5.18f, -4.7f, 2.3f, 7.45f}}, MTHLIB_LOW_PRECISION));
	
	r = InverseMatrix2x2(m1);
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {-0.268168f, 0.082790f, -0.169180f, 0.186458f}}, MTHLIB_LOW_PRECISION));

	r_v2 = MultV2ByMatrix2x2(u, m1);
	MTHLIB_ASSERT(CompareV2(r_v2, (v2){9.764f, -22.57f}, MTHLIB_LOW_PRECISION));
	
	r = CreateIdentity2x2();
	MTHLIB_ASSERT(CompareMat2x2(r, (mat2x2){.elem = {1.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));

	printf("%s tests done...\n", __FILE__);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	v2 u = {3.43f, 1.53f};
	v2 v = {6.28f, 9.01f};
	v2 r = {0.0f, 0.0f};
	f32 r_f = 0.0f;

	r = AddV2(u, v);
	MTHLIB_ASSERT(CompareV2(r, (v2){9.71f, 10.54f}, MTHLIB_32_PRECISION));
	
	r = SubtractV2(u, v);
	MTHLIB_ASSERT(CompareV2(r, (v2){-2.85f, -7.48f}, MTHLIB_32_PRECISION));

	r = ScaleV2(u, 4.2f);
	MTHLIB_ASSERT(CompareV2(r, (v2){14.406f, 6.426f}, MTHLIB_32_PRECISION));

	r_f = DotV2(u, v);
	MTHLIB_ASSERT(Compare32(r_f, 35.3257f, MTHLIB_32_PRECISION));
	
	r_f = NormV2(u);
	MTHLIB_ASSERT(Compare32(r_f, 3.75576f, MTHLIB_32_PRECISION));
	
	r_f = NormV2(v);
	MTHLIB_ASSERT(Compare32(r_f, 10.98264f, MTHLIB_32_PRECISION));

	r = UnitV2(u);
	MTHLIB_ASSERT(CompareV2(r, (v2){0.91326f, 0.40737f}, MTHLIB_32_PRECISION));

	r = UnitV2(v);
	MTHLIB_ASSERT(CompareV2(r, (v2){0.57181f, 0.82038f}, MTHLIB_32_PRECISION));

	return 0;
}
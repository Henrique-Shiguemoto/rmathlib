#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	v3 u = {1.4f, 0.23f, -3.18f};
	v3 v = {5.98f, -3.27f, 8.68f};
	v3 w = {0.098f, 8.33f, 4.42f};
	v3 r = {0};
	f32 r_f = 0.0f;
	v2 r_v2 = {0};

	r = AddV3(u, v);
	MTHLIB_ASSERT(CompareV3(r, (v3){7.38f, -3.04f, 5.50f}, MTHLIB_LOW_PRECISION));
	
	r = SubtractV3(u, v);
	MTHLIB_ASSERT(CompareV3(r, (v3){-4.58f, 3.5f, -11.86f}, MTHLIB_LOW_PRECISION));
	
	r = ScaleV3(u, -8.9f);
	MTHLIB_ASSERT(CompareV3(r, (v3){-12.46f, -2.047f, 28.302f}, MTHLIB_LOW_PRECISION));
	
	r_f = (f32)DotV3(u, v);
	MTHLIB_ASSERT(Compare32(r_f, -19.9825f, MTHLIB_LOW_PRECISION));

	r = CrossV3(u, v);
	MTHLIB_ASSERT(CompareV3(r, (v3){-8.4022f, -31.1684f, -5.9534f}, MTHLIB_LOW_PRECISION));
	
	r_f = (f32)NormV3(u);
	MTHLIB_ASSERT(Compare32(r_f, 3.48214f, MTHLIB_LOW_PRECISION));

	r_f = (f32)NormV3(v);
	MTHLIB_ASSERT(Compare32(r_f, 11.03610f, MTHLIB_LOW_PRECISION));
	
	r = UnitV3(u);
	MTHLIB_ASSERT(CompareV3(r, (v3){0.40205f, 0.06605f, -0.91323f}, MTHLIB_LOW_PRECISION));
	
	r_v2 = ConvertV3ToV2(u);
	MTHLIB_ASSERT(CompareV2(r_v2, (v2){1.4f, 0.23f}, MTHLIB_LOW_PRECISION));

	r_f = (f32)ScalarTripleProduct(u, v, w);
	MTHLIB_ASSERT(Compare32(r_f, -286.7702156f, MTHLIB_LOW_PRECISION));

	printf("%s tests done...\n", __FILE__);
	return 0;
}
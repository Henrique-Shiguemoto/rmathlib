#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	v4 u = {-6.13f, 5.27f, 5.05f, 8.20f};
	v4 v = {-0.85f, 5.87f, -8.83f, 6.31f};
	v4 r = {0};
	f32 r_f = 0.0f;
	v3 r_v3 = {0};

	r = AddV4(u, v);
	MTHLIB_ASSERT(CompareV4(r, (v4){-6.98f, 11.14, -3.78, 14.51f}, MTHLIB_32_PRECISION));
	
	r = SubtractV4(u, v);
	MTHLIB_ASSERT(CompareV4(r, (v4){-5.28f, -0.6f, 13.88f, 1.89f}, MTHLIB_32_PRECISION));
	
	r = ScaleV4(u, 5.1f);
	MTHLIB_ASSERT(CompareV4(r, (v4){-31.263f, 26.877f, 25.755f, 41.82f}, MTHLIB_32_PRECISION));
	
	r_f = (f32)DotV4(u, v);
	MTHLIB_ASSERT(Compare32(r_f, 43.2959f, MTHLIB_32_PRECISION));

	r_f = (f32)NormV4(u);
	MTHLIB_ASSERT(Compare32(r_f, 12.57347f, MTHLIB_32_PRECISION));

	r_f = (f32)NormV4(v);
	MTHLIB_ASSERT(Compare32(r_f, 12.36787f, MTHLIB_32_PRECISION));
	
	r = UnitV4(u);
	MTHLIB_ASSERT(CompareV4(r, (v4){-0.48753f, 0.41913f, 0.40163f, 0.65216f}, MTHLIB_32_PRECISION));

	r = UnitV4(v);
	MTHLIB_ASSERT(CompareV4(r, (v4){-0.06872f, 0.47461f, -0.71394f, 0.51019f}, MTHLIB_32_PRECISION));

	r_v3 = ConvertV4ToV3(u);
	MTHLIB_ASSERT(CompareV3(r_v3, (v3){-6.13f, 5.27f, 5.05f}, MTHLIB_32_PRECISION));

	printf("%s tests done...\n", __FILE__);

	return 0;
}
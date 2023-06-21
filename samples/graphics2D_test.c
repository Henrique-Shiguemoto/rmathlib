#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	mat3x3 r = {0};
	v2 x = {1.4f, -3.9f};
	v2 random_point = {1.0f, -5.0f};

	r = CreateTranslationMatrix2D(x);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {1.0f, 0.0f, 1.4f, 0.0f, 1.0f, -3.9f, 0.0f, 0.0f, 1.0f}}, MTHLIB_HIGH_PRECISION));
	
	r = CreateScaleMatrixWithSetOrigin2D(x, random_point);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {1.4f, 0.0f, -0.4f, 0.0f, -3.9f, -24.5f, 0.0f, 0.0f, 1.0f}}, 1000*MTHLIB_HIGH_PRECISION));

	r = CreateScaleMatrix2D(x);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {1.4f, 0.0f, 0.0f, 0.0f, -3.9f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_HIGH_PRECISION));

	r = CreateRotationAroundPointMatrix2D(0.25f*MTHLIB_PI, random_point);	
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {0.5f*MTHLIB_SQRT_2, -0.5f*MTHLIB_SQRT_2, -3.0f*MTHLIB_SQRT_2 + 1.0f, 0.5f*MTHLIB_SQRT_2, 0.5f*MTHLIB_SQRT_2, 2.0f*MTHLIB_SQRT_2 - 5.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));

	r = CreateRotationMatrix2D(1.5f*MTHLIB_PI);
	MTHLIB_ASSERT(CompareMat3x3(r, (mat3x3){.elem = {0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));
	printf("%s tests done...\n", __FILE__);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	mat4x4 r = {0};
	v3 random_vector = {0.2f, -4.6f, 9.1f};
	f32 random_angle = 0.75f*MTHLIB_PI;

	r = CreateTranslationMatrix3D(random_vector);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {1.0f, 0.0f, 0.0f, 0.2f, 0.0f, 1.0f, 0.0f, -4.6f, 0.0f, 0.0f, 1.0f, 9.1f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_HIGH_PRECISION));
	
	r = CreateScaleMatrix3D(random_vector);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {0.2f, 0.0f, 0.0f, 0.0f, 0.0f, -4.6f, 0.0f, 0.0f, 0.0f, 0.0f, 9.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_HIGH_PRECISION));
	
	r = CreateEulerRotationInXMatrix3D(random_angle);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -0.707106, -0.707106, 0.0f, 0.0f, 0.707106, -0.707106, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));
	
	r = CreateEulerRotationInYMatrix3D(random_angle);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {-0.707106f, 0.0f, 0.707106f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -0.707106f, 0.0f, -0.707106f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));
	
	r = CreateEulerRotationInZMatrix3D(random_angle);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {-0.707106f, -0.707106f, 0.0f, 0.0f, 0.707106f, -0.707106f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));

	r = CreateEulerRotationInXYZMatrix3D(random_vector);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {0.106288f, 0.035787f, 0.993691f, 0.0f, 0.125642f, -0.991823f, 0.022281f, 0.0f, 0.986363f, 0.122481f, -0.109916f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));
	
	r = CreateParallelProjectionMatrix3D(-4.1f, 3.9f, 1.2f, -5.1f, 2.4f, 6.7f);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 0.317460f, 0.0f, 0.0f, 0.0f, 0.0f, -0.465116f, 0.0f, 0.025f, 0.619047f, 2.116279f, 1.0f}}, MTHLIB_LOW_PRECISION));

	r = CreatePerspectiveProjectionMatrix3D(MTHLIB_PI*0.25f, 16.0f / 9.0f, 100.5f, 15.5f);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {1.357995f, 0.0f, 0.0f, 0.0f, 0.0f, 2.414213f, 0.0f, 0.0f, 0.0f, 0.0f, 1.182352f, -18.326470f, 0.0f, 0.0f, 1.0f, 0.0f}}, MTHLIB_LOW_PRECISION));
	
	printf("%s tests done...\n", __FILE__);
	return 0;
}
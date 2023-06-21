#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	// mat4x4 CreateTranslationMatrix3D(v3 posDelta);
	// mat4x4 CreateScaleMatrix3D(v3 scale);
	// mat4x4 CreateEulerRotationInXMatrix3D(f32 angle);
	// mat4x4 CreateEulerRotationInYMatrix3D(f32 angle);
	// mat4x4 CreateEulerRotationInZMatrix3D(f32 angle);
	// mat4x4 CreateEulerRotationInXYZMatrix3D(v3 angles);
	// mat4x4 CreateParallelProjectionMatrix3D(f32 l, f32 r, f32 t, f32 b, f32 f, f32 n);
	// mat4x4 CreatePerspectiveProjectionMatrix3D(f32 fovY, f32 aspectRatio, f32 f, f32 n);
	printf("%s tests done...\n", __FILE__);
	return 0;
}
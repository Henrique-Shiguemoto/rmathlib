#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	printf("RandomU32() = %u\n", RandomU32());
	printf("RandomU32InInterval() = %u\n", RandomU32InInterval(1, 500));
	printf("RandomBool() = %s\n", RandomBool() == MTHLIB_TRUE ? "MTHLIB_TRUE" : "MTHLIB_FALSE");
	printf("RandomSign() = %i\n", RandomSign());
	printf("Random32() = %f\n", Random32());
	
	v2 rand_v2 = RandomV2();
	printf("RandomV2() = (v2){%f, %f}\n", rand_v2.x, rand_v2.y);	
	v3 rand_v3 = RandomV3();
	printf("RandomV3() = (v3){%f, %f, %f}\n", rand_v3.x, rand_v3.y, rand_v3.z);
	v4 rand_v4 = RandomV4();
	printf("RandomV4() = (v4){%f, %f, %f, %f}\n", rand_v4.x, rand_v4.y, rand_v4.z, rand_v4.w);
	printf("\n");
	mat2x2 rand_mat2x2 = RandomMat2x2();
	for (i32 i = 0; i < 4; ++i) printf("rand_mat2x2.elem[%i] = %f\n", i, rand_mat2x2.elem[i]);
	printf("\n");
	mat3x3 rand_mat3x3 = RandomMat3x3();
	for (i32 i = 0; i < 9; ++i) printf("rand_mat3x3.elem[%i] = %f\n", i, rand_mat3x3.elem[i]);
	printf("\n");
	mat4x4 rand_mat4x4 = RandomMat4x4();
	for (i32 i = 0; i < 16; ++i) printf("rand_mat4x4.elem[%i] = %f\n", i, rand_mat4x4.elem[i]);
	printf("\n");

	printf("%s tests done...\n", __FILE__);
	return 0;
}
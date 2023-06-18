#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	mat4x4 m1 = {.elem = {-5.18f, 2.3f, -4.7f, 7.45f, 3.24f, -9.51f, -6.01f, 6.03f, 8.56f, -3.83f, -0.37f, 7.59f, 3.14f, -3.16f, -0.62f, -9.50f}};
	mat4x4 m2 = {.elem = {-3.36f, -6.32f, 2.22f, -3.45f, -3.22f, -3.20f, -4.32f, 9.45f, -0.58f, -5.89f, 8.09f, 1.13f, -9.82f, 8.13f, -6.05f, 9.68f}};
	mat4x4 r = {0};
	v4 u = {1.2f, -3.4f, 5.1f, -4.3f};
	v4 r_v4 = {0};
	f32 r_f = 0.0f;

	r = AddMatrix4x4(m1, m2);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {-8.54f, -4.02f, -2.48f, 4.0f, 0.02f, -12.71f, -10.33f, 15.48f, 7.98f, -9.72f, 7.72f, 8.72f, -6.68f, 4.97f, -6.67f, 0.18f}}, MTHLIB_LOW_PRECISION));
	
	r = SubMatrix4x4(m1, m2);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {-1.82f, 8.62f, -6.92f, 10.9f, 6.46f, -6.31f, -1.69f, -3.42f, 9.14f, 2.06f, -8.46f, 6.46f, 12.96f, -11.29f, 5.43f, -19.18f}}, MTHLIB_LOW_PRECISION));
	
	r = ScalarMultMatrix4x4(-3.8f, m1);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {19.684f, -8.74f, 17.86f, -28.31f, -12.312f, 36.138f, 22.838f, -22.914f, -32.528f, 14.554f, 1.406f, -28.842f, -11.932f, 12.008f, 2.356f, 36.1f}}, MTHLIB_LOW_PRECISION));
	
	r = MultMatrix4x4(m1, m2);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {-60.4342f, 113.6291f, -104.5311f, 106.411f, -35.993f, 94.378f, -36.8264f, -49.4684f, -90.7482f, 22.0428f, -13.364f, 7.3276f, 93.2744f, -83.316f, 73.0812f, -133.3556f}}, MTHLIB_LOW_PRECISION));
	
	r_f = DetMatrix4x4(m1);
	MTHLIB_ASSERT(Compare32(r_f, 3736.0847f, 0.001f));
	
	r = TransposeMatrix4x4(m1);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {-5.18f, 3.24f, 8.56f, 3.14f, 2.3f, -9.51f, -3.83f, -3.16f, -4.7f, -6.01f, -0.37f, -0.62f, 7.45f, 6.03f, 7.59f, -9.50f}}, MTHLIB_LOW_PRECISION));

	r = InverseMatrix4x4(m1);
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {0.0781f, -0.0834f, 0.1489f, 0.1273f, 0.1687f, -0.1519f, 0.1132f, 0.1263f, -0.2395f, 0.0489f, -0.0819f, -0.2222f, -0.0146f, 0.0197f, 0.01691f, -0.0906f}}, 0.0001f)); // too little precision... :c

	r_v4 = MultV4ByMatrix4x4(u, m1);
	MTHLIB_ASSERT(CompareV4(r_v4, (v4){12.922f, 29.149f, 15.573f, 67.997f}, MTHLIB_LOW_PRECISION));
	
	r = CreateIdentity4x4();
	MTHLIB_ASSERT(CompareMat4x4(r, (mat4x4){.elem = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}, MTHLIB_LOW_PRECISION));

	printf("%s tests done...\n", __FILE__);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	b8 r = MTHLIB_FALSE;

	r = ParallelLines2D((line2D){.direction = {10.05f, -5.4f}}, (line2D){.direction = {-74.4705f, 40.014f}});
	MTHLIB_ASSERT(r);

	r = ParallelLines3D((line3D){.direction = {-3.46f, -4.89f, 5.67f}}, (line3D){.direction = {30.5518f, 43.1787f, -50.0661f}});
	MTHLIB_ASSERT(r);
	
	r = IntersectingLines2D((line2D){.direction = {110.76f, -10.27f}}, (line2D){.direction = {30.62f, -21.88f}});
	MTHLIB_ASSERT(r);

	r = IntersectingLines3D((line3D){.direction = {3.66f, 8.16f, -6.40f}, .arbitraryPoint = {5.5f, -3.2f, -6.05f}}, (line3D){.direction = {0.46f, 0.26f, 8.08f}, .arbitraryPoint = {5.5f, -3.2f, -6.05f}});
	MTHLIB_ASSERT(r);

	r = SkewLines((line3D){.direction = {3.66f, 8.16f, -6.40f}, .arbitraryPoint = {5.5f, -3.2f, -6.05f}}, (line3D){.direction = {0.46f, 0.26f, 8.08f}, .arbitraryPoint = {9.9f, -43.1f, 0.0f}});
	MTHLIB_ASSERT(r);

	printf("%s tests done...\n", __FILE__);
	return 0;
}
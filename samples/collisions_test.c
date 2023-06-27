#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	b8 r = MTHLIB_FALSE;
	
	r = CollisionAABB2D((AABB2D){.min = {0.0f, 0.0f}, .max = {1.0f, 1.0f}}, (AABB2D){.min = {0.5f, 0.5f}, .max = {2.0f, 2.0f}});
	MTHLIB_ASSERT(r);

	r = CollisionPointAndAABB2D((point2D){0.0f, 0.0f}, (AABB2D){.min = {-1.0f, -1.0f}, .max = {1.0f, 1.0f}});
	MTHLIB_ASSERT(r);

	r = CollisionPointAndSphere2D((point2D){0.0f, 0.0f}, (sphere2D){.center = {0.0f, 0.0f}, .radius = 1.0f});
	MTHLIB_ASSERT(r);

	r = CollisionSphere2D((sphere2D){.center = {-5.9f, 8.5f}, .radius = 3.4f}, (sphere2D){.center = {-4.1f, 1.0f}, .radius = 9.0f});
	MTHLIB_ASSERT(r);

	r = CollisionAABB3D((AABB3D){.min = {-5.1f, -4.3f, -0.1f}, .max = {5.1f, 24.0f, 9.4f}}, (AABB3D){.min = {-0.1f, -2.3f, 1.1f}, .max = {15.1f, 27.0f, 90.1f}});
	MTHLIB_ASSERT(r);

	r = CollisionPointAndAABB3D((point3D){8.04f, -3.02f, -7.24f}, (AABB3D){.min = {-100.2f, -93.4f, -52.1f}, .max = {20.0f, 2.4f, 112.3f}});
	MTHLIB_ASSERT(r);
	
	r = CollisionPointAndSphere3D((point3D){1.0f, 1.0f, 1.0f}, (sphere3D){.center = {0.0f, 1.4f, 2.2f}, .radius = 5.6f});
	MTHLIB_ASSERT(r);

	r = CollisionSphere3D((sphere3D){.center = {-7.3f, 5.11f, 6.9f}, .radius = 11.1f}, (sphere3D){.center = {-5.0f, -4.0f, 1.1f}, .radius = 1.4f});
	MTHLIB_ASSERT(r);

	printf("%s tests done...\n", __FILE__);
	return 0;
}
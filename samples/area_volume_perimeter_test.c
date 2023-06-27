#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	f32 r = 0.0f;
	
	r = AreaTriangle2D((triangle2D){.a = {3.94f, 0.98f}, .b = {-2.91f, -6.37f}, .c = {0.3f, 9.1f}});
	MTHLIB_ASSERT(Compare32(r, 41.188f, MTHLIB_LOW_PRECISION));
	
	r = AreaSphere2D((sphere2D){.radius = 12.7f});
	MTHLIB_ASSERT(Compare32(r, 506.70747f, MTHLIB_LOW_PRECISION));

	r = AreaAABB2D((AABB2D){.min = {-4.1f, 24.2f}, .max = {34.2f, 52.8f}});
	MTHLIB_ASSERT(Compare32(r, 1095.38f, 100*MTHLIB_LOW_PRECISION));
	
	r = AreaQuad2D((quad2D){.a = {5.4f, 5.5f}, .b = {0.48f, 5.24f}, .c = {-0.98f, -1.64f}, .d = {7.12f, 4.49f}});
	MTHLIB_ASSERT(Compare32(r, 26.0973f, MTHLIB_LOW_PRECISION));

	r = PerimeterSphere2D((sphere2D){.radius = 54.32f});
	MTHLIB_ASSERT(Compare32(r, 341.302625f, MTHLIB_LOW_PRECISION));
	
	r = PerimeterAABB2D((AABB2D){.min = {-3.4f, 5.6f}, .max = {1.0f, 1.0f}});
	MTHLIB_ASSERT(Compare32(r, 18.0f, MTHLIB_LOW_PRECISION));

	r = PerimeterQuad2D((quad2D){.a = {-8.27f, -1.87f}, .b = {-3.28f, 6.71f}, .c = {2.42f, -0.29f}, .d = {-3.49f, -9.67f}});
	MTHLIB_ASSERT(Compare32(r, 39.187456f, MTHLIB_LOW_PRECISION));

	r = PerimeterTriangle2D((triangle2D){.a = {3.45f, -8.46f}, .b = {4.31f, -9.06f}, .c = {-1.8f, -3.79f}});
	MTHLIB_ASSERT(Compare32(r, 16.143863f, MTHLIB_LOW_PRECISION));

	r = AreaTriangle3D((triangle3D){.a = {6.15f, 7.19f, 5.8f}, .b = {-1.09f, 8.15f, -6.86f}, .c = {1.66f, 7.54f, 7.12f}});
	MTHLIB_ASSERT(Compare32(r, 33.334f, 10*MTHLIB_LOW_PRECISION));
	
	r = AreaQuad3D((quad3D){.a = {-6.34f, 7.69f, -4.96f}, .b = {-0.43f, -4.11f, 3.51f}, .c = {2.67f, -1.26f, 8.87f}, .d = {-1.09f, -0.09f, -6.94f}});
	MTHLIB_ASSERT(Compare32(r, 129.41f, 1000*MTHLIB_LOW_PRECISION));

	r = VolumeSphere3D((sphere3D){.radius = 13.2f});
	MTHLIB_ASSERT(Compare32(r, 9634.083429f, MTHLIB_LOW_PRECISION));
	
	r = VolumeAABB3D((AABB3D){.min = {-5.3f, 4.5f, 9.2f}, .max = {6.6f, 7.1f, 8.8f}});
	MTHLIB_ASSERT(Compare32(r, 12.376f, 10*MTHLIB_LOW_PRECISION));

	r = PerimeterTriangle3D((triangle3D){.a = {3.11f, -2.04f, -8.24f}, .b = {-6.53f, -4.28f, 9.85f}, .c = {-2.62f, -1.58f, -1.14f}});
	MTHLIB_ASSERT(Compare32(r, 41.728835f, MTHLIB_LOW_PRECISION));

	r = SurfaceAreaSphere3D((sphere3D){.radius = 12.2f});
	MTHLIB_ASSERT(Compare32(r, 1870.378602f, 100*MTHLIB_LOW_PRECISION));
	
	r = SurfaceAreaAABB3D((AABB3D){.min = {-1.4f, -3.4f, -5.6f}, .max = {2.3f, 3.4f, 4.5f}});
	MTHLIB_ASSERT(Compare32(r, 262.42f, MTHLIB_LOW_PRECISION));

	printf("%s tests done...\n", __FILE__);
	return 0;
}
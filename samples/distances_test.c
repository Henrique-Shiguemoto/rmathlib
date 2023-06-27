#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	f32 r = 0.0f;

	r = DistanceBetweenPoints2D((point2D){3.4f, -0.7f}, (point2D){-3.5f, 18.4f});
	MTHLIB_ASSERT(Compare32(r, 20.308126f, MTHLIB_LOW_PRECISION));
	
	r = DistanceBetweenPoints3D((point3D){12.5f, -10.3f, 0.34f}, (point3D){9.12f, -24.67f, 19.39f});
	MTHLIB_ASSERT(Compare32(r, 24.100286f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenPointAndLine2D((point2D){13.4f, -87.1f}, (line2D){.direction = {2.4f, 7.8f}, .arbitraryPoint = {1.0f, 0.0f}});
	MTHLIB_ASSERT(Compare32(r, 37.466537f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenLines2D((line2D){.direction = {3.1f, 4.5f}, .arbitraryPoint = {7.3f, 1.2f}}, (line2D){.direction = {6.2f, 9.0f}, .arbitraryPoint = {9.5f, 0.3f}});
	MTHLIB_ASSERT(Compare32(r, 2.322291f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenPointAndLine3D((point3D){1.2f, 3.4f, 5.6f}, (line3D){.direction = {7.4f, 0.1f, -4.4f}, .arbitraryPoint = {10.3f, 12.5f, -3.7f}});
	MTHLIB_ASSERT(Compare32(r, 9.557048f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenLines3D((line3D){.direction = {0.88f, -0.791f, 1.148f}, .arbitraryPoint = {-8.371f, 7.5f, 2.085f}}, (line3D){.direction = {-1.56f, 6.318f, -7.126f}, .arbitraryPoint = {-6.36f, 2.073f, 5.209f}});
	MTHLIB_ASSERT(Compare32(r, 2.183631f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenPointAndPlane((point3D){-0.11f, 4.23f, -1.14f}, (plane){.normal = {-4.99f, 0.76f, -0.31f}, .arbitraryPoint = {2.58f, -7.33f, -6.09f}});
	MTHLIB_ASSERT(Compare32(r, 4.088190f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenLineAndPlane((line3D){.direction = {1.0f, 1.0f, 3.716129f}, .arbitraryPoint = {9.14f, -95.18f, 1.3f}}, (plane){.normal = {-9.2f, -8.08f, 4.65f}, .arbitraryPoint = {2.58f, -7.33f, -6.09f}});
	MTHLIB_ASSERT(Compare32(r, 52.210783f, MTHLIB_LOW_PRECISION));

	r = DistanceBetweenPlanes((plane){.normal = {6.77f, -1.41f, 7.20f}, .arbitraryPoint = {2.34f, 3.14f, -3.36}}, (plane){.normal = {6.77f, -1.41f, 7.20f}, .arbitraryPoint = {1.89f, -5.68f, 4.37f}});
	MTHLIB_ASSERT(Compare32(r, 6.515623f, MTHLIB_LOW_PRECISION));

	printf("%s tests done...\n", __FILE__);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	f32 angleInDegrees = 77.3125f;
	f32 angleInRadians = DegreesToRadians32(angleInDegrees);
	f32 r = 0.0f;

	f64 angleInDegrees_64 = -181.4242f;
	f64 angleInRadians_64 = DegreesToRadians32(angleInDegrees_64);
	f64 r_64 = 0.0f;

	r = Sin32(angleInRadians);
	MTHLIB_ASSERT(Compare32(r, 0.975582f, MTHLIB_LOW_PRECISION));
	r = Cos32(angleInRadians);
	MTHLIB_ASSERT(Compare32(r, 0.219633f, MTHLIB_LOW_PRECISION));
	r = Tg32(angleInRadians);
	MTHLIB_ASSERT(Compare32(r, 4.441868f, MTHLIB_LOW_PRECISION));
	r = Cosec32(angleInRadians);
	MTHLIB_ASSERT(Compare32(r, 1.025028f, MTHLIB_LOW_PRECISION));
	r = Sec32(angleInRadians);
	MTHLIB_ASSERT(Compare32(r, 4.553042f, MTHLIB_LOW_PRECISION));
	r = Cotg32(angleInRadians);
	MTHLIB_ASSERT(Compare32(r, 0.225130f, MTHLIB_LOW_PRECISION));

	r_64 = Sin64(angleInRadians_64);
	MTHLIB_ASSERT(Compare64(r_64, 0.024854f, MTHLIB_LOW_PRECISION));
	r_64 = Cos64(angleInRadians_64);
	MTHLIB_ASSERT(Compare64(r_64, -0.999691f, MTHLIB_LOW_PRECISION));
	r_64 = Tg64(angleInRadians_64);
	MTHLIB_ASSERT(Compare64(r_64, -0.024862f, MTHLIB_LOW_PRECISION));
	r_64 = Cosec64(angleInRadians_64);
	MTHLIB_ASSERT(Compare64(r_64, 40.234293f, 0.001f)); // too little precision... :c
	r_64 = Sec64(angleInRadians_64);
	MTHLIB_ASSERT(Compare64(r_64, -1.000309f, MTHLIB_LOW_PRECISION));
	r_64 = Cotg64(angleInRadians_64);
	MTHLIB_ASSERT(Compare64(r_64, -40.22186391f, 0.001f));  // too little precision... :c

	printf("%s tests done...\n", __FILE__);
	return 0;
}


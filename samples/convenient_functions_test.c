#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
    if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
    f32 angle_degrees = 94.141f;
    f32 angle_radians = -5.133f;
    f32 x = 5.1234f;
    f32 y = 219.1929f;
    
    f64 angle_degrees_64 = 1029.441;
    f64 angle_radians_64 = 3.141592;
    f64 x_64 = 16.3428;
    f64 y_64 = 59.7812;

    MTHLIB_ASSERT(Compare32(DegreesToRadians32(angle_degrees), 1.64307041f, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Compare32(RadiansToDegrees32(angle_radians), -294.09924f, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Compare32(Sqrt32(x), 2.263492f, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Abs32(-41.1f) == 41.1f);
    MTHLIB_ASSERT(Clamp32(-1.0f, 1.0f, x) == 1.0f);
    MTHLIB_ASSERT(Max32(x, y) == y);
    MTHLIB_ASSERT(Min32(x, y) == x);
    MTHLIB_ASSERT(Compare32(Mod32(y, x, MTHLIB_FALSE), 4.0101f, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Ceil32(x) == 6);
    MTHLIB_ASSERT(Floor32(x) == 5);
    MTHLIB_ASSERT(Round32(x) == 5);
    
    MTHLIB_ASSERT(Compare64(DegreesToRadians64(angle_degrees_64), 17.967134905, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Compare64(RadiansToDegrees64(angle_radians_64), 179.99996255, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Compare64(Sqrt64(x_64), 4.042622f, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Abs64(-0.3213) == 0.3213);
    MTHLIB_ASSERT(Clamp64(0, 100, y_64) == y_64);
    MTHLIB_ASSERT(Max64(x_64, y_64) == y_64);
    MTHLIB_ASSERT(Min64(x_64, y_64) == x_64);
    MTHLIB_ASSERT(Compare64(Mod64(y_64, x_64, MTHLIB_FALSE), 10.7528, MTHLIB_LOW_PRECISION));
    MTHLIB_ASSERT(Ceil64(x_64) == 17);
    MTHLIB_ASSERT(Floor64(x_64) == 16);
    MTHLIB_ASSERT(Round64(y_64) == 60);
    MTHLIB_ASSERT(Sign(x_64) == 1);
    
    printf("%s tests done...\n", __FILE__);
    return 0;
}
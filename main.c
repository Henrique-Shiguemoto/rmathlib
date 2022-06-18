/*

	THIS IS A FILE FOR TESTING THE LIBRARY ONLY.
	BY: RICK SHIGUEMOTO FELIZARDO.

*/

#include <stdio.h>
#include "mthlib.h"

int main(void){
	v3 u = {.x = 2.5491, .y = 1.9115, .z = -9.7238};
	v3 v = {.x = -6.0012, .y = 3.9931, .z = 5.5163};
	v3 result = CrossV3(u, v);

	printf("Cross Product = (%f, %f, %f)", result.x, result.y, result.z);

	return 0;
}
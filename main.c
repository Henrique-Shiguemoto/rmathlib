/*

	THIS IS A FILE FOR TESTING THE LIBRARY ONLY.
	BY: RICK SHIGUEMOTO FELIZARDO.

*/

#include <stdio.h>
#include <math.h>
#include "mthlib.h"

int main(void){
	for (f32 i = -1000; i < 1000; i += 0.01)
	{
		f32 result = sin(i);
		f32 myResult = Sin32(i);
		f32 error = Abs32(result - myResult);
		if(error > PRECISION){
			printf("%lf - Error = %.15lf\n", i, error);
		}
	}

	printf("Done!\n");
	return 0;
}
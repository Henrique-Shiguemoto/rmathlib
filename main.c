/*

	THIS IS A FILE FOR TESTING THE LIBRARY ONLY.
	BY: RICK SHIGUEMOTO FELIZARDO.

*/

#include <stdio.h>
#include <math.h>
#include "mthlib.h"

int main(void){
	//Debug Sin
	f64 i = 999.020000;
	f64 result = sin(i);
	f64 myResult = Sin64(i);
	f64 error = Abs64(result - myResult);
	printf("result   = %.15lf\n", result);
	printf("myResult = %.15lf\n", myResult);
	printf("error    = %.15lf\n", error);

	printf("Done!\n");
	return 0;
}
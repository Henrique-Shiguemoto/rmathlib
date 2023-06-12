#include <stdio.h>
#include <stdlib.h>
#include "../mthlib.h"

#define MTHLIB_ASSERT(x); \
	if(!(x)){ fprintf(stderr, "ASSERT - ERROR AT: (%d)\n", __LINE__); exit(1); }

int main(void){
	printf("Time = %lf\n", GetPlatformTime());
	printf("%s tests done...\n", __FILE__);
	return 0;
}
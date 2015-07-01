#include <stdio.h>

int printf(const char *fmt, ...){

	puts("LD_PRELOAD works!!!");
	return 0;
}

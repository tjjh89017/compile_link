#include <stdio.h>

int printf(const char *fmt, ...){

	puts("LD_PRELOAD works!!!");
	puts("using libtest.so rather than libc");
	return 0;
}

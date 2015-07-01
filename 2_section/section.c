#include <stdio.h>
#include <stdlib.h>

/*
 * a   -> .data
 * b   -> .bss
 * PI  -> .rodata
 * c   ->  stack
 * d   ->  heap
 */

int a = 0x0a0b0c0d;
int b;
const double PI = 3.14159f;

int main(){

	int c = 0x123456;
	int *d = (int*)malloc(sizeof(int));

	printf(" a = 0x%08x\n", a);
	printf(" b = 0x%08x\n", b);
	printf(" c = 0x%08x\n", c);
	printf("*d = 0x%08x\n", *d);
	printf("PI = %f\n", PI);

	printf(" &a = %p\n", &a);
	printf(" &b = %p\n", &b);
	printf(" &c = %p\n", &c);
	printf("  d = %p\n", d);
	printf("&PI = %p\n", &PI);

	return 0;
}

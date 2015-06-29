#include "foo.h"

int foo_a = 0x123;

int print_foo_a(){

	printf("foo_a = %d\n", foo_a);
	return foo_a;
}

int foo_static(){

	static int b = 0;
	printf("static b = %d\n", b);

	b++;
	return b;
}

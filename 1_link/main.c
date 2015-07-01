#include <stdio.h>
#include <stdlib.h>

#include "foo.h"

extern int foo_a;
int main_a = 0;

int main(){

	foo_static();
	print_foo_a();
	foo_a = 123456789;
	print_foo_a();

	printf("main_a = %d\n", main_a);
	return 0;
}

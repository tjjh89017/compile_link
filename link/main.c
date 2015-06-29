#include <stdio.h>
#include <stdlib.h>

#include "foo.h"

extern int foo_a;

int main(){

	foo_static();
	print_foo_a();
	foo_a = 123456789;
	print_foo_a();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "foo.h"

void foo(){

	printf("This is foo!\n");
}

/*
 * Unreachable
 */
void foo2(){

	printf("Unreachable!\n");
}

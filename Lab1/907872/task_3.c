
#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"


int main(int argc, char* argv[]){

	int value = atoi(argv[1]);
	printf("%d! is %d\n", value, factorial(value));
	return 0;
}
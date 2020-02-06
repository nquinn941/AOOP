
#include "factorial.h"

int factorial(int value){
	int factorial = 1; 
	for(int i=1;i<=value;i++){
		factorial = factorial * i;
	}
	return factorial;
}
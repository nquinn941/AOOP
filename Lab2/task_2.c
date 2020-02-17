#include <stdio.h>
#include <stdlib.h>
#include "array_ops.h"


int main(int argc, char* argv[]){

	int numberOfElements = argc -1;
	printf("Number of input values: %d \n",numberOfElements);

	if(numberOfElements == 0){
		return 0;
	}

	else{
		float *values = malloc(numberOfElements * sizeof(float));

		int i;
		for(i=0;i<numberOfElements;i++){
		values[i] = atof(argv[i+1]);
		}

		for(i=0;i<numberOfElements;i++){
		printf("values[%d] = %f\n",i,values[i]);
		}

		printf("\nmax value = %f\n", array_max(values,numberOfElements));
		printf("min value = %f\n", array_min(values,numberOfElements));
		printf("mean value = %f\n", array_mean(values,numberOfElements));

		free(values);
	}

	return 0;

	
}
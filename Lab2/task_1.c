#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int numberOfElements = argc -1;
	printf("Number of input values: %d \n",numberOfElements);

	if(numberOfElements==0){
		return 0;
	}

	float *values = malloc(numberOfElements * sizeof(float));

	int i;
	for(i=0;i<numberOfElements;i++){
		values[i] = atof(argv[i+1]);
	}

	for(i=0;i<numberOfElements;i++){
		printf("values[%d] = %f\n",i,values[i]);
	}

	free(values);

	return 0;
}
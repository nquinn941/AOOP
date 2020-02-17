
#include "array_ops.h"

float array_max(float *values, int length){
	float max_value =0;

	int i;
	for(i=0;i<length;i++){
		if(values[i]>max_value){
			max_value = values[i];
		}
	}

	return max_value;
}

float array_min(float *values, int length){
	float min_value =1000;

	int i;
	for(i=0;i<length;i++){
		if(values[i]<min_value){
			min_value = values[i];
		}
	}
	return min_value;
}

float array_mean(float *values, int length){
	float total_value =0;

	int i;
	for(i=0;i<length;i++){
		total_value+=values[i];
	}

	float mean_value = total_value/length;

	return mean_value;
}

void array_insertion_sort(float *array, const int length){
	int i,j;
	float key;
	for(i=1;i<length;i++){
		key = array[i];
		j = i-1;

		while(j>=0 && key <array[j]){
			array[j+1] = array[j];
			j--;
		}

		array[j+1] =key;
	}
}


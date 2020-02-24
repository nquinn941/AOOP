#include <stdio.h>

#include "constituency.h"

int main(int argc, char *argv[]){
	const int num_constituencies = 5;
	struct Constituency constituencies [num_constituencies];


	construct_Constituency (&constituencies[0],"Swansea East" ,(unsigned int []){1,2,3,4},4);

	construct_Constituency (&constituencies[1],"Swansea West",(unsigned int []){0,2},2);

	construct_Constituency (&constituencies[2],"Gower",(unsigned int []){0,1,3},3);

	construct_Constituency (&constituencies[3],"Neath",(unsigned int []){0,2,4},3);

	construct_Constituency (&constituencies [4],"Aberavon",(unsigned int []){0,3},2);

	int i;

	for(i=0;i<num_constituencies;i++){
		print_Constituency(&constituencies[i]);
		printf("\n");
	}

	//print constituency with most neighbours 
	int j; 
	int max=0;
	int maxIndex;
	struct Constituency maxConstituency;

	for(j=0;j<num_constituencies;j++){
		
		int num_neighbours = constituencies[j].num_neighbours;
		
		if(num_neighbours>max){
			max = num_neighbours;
			maxIndex=j;	
		}
	}
	maxConstituency=constituencies[maxIndex];
	
	printf("%s has the most bordering constituencies:\n",maxConstituency.name);

	unsigned int neighbour_array[maxConstituency.num_neighbours];

	int k;
	for(k=0;k<maxConstituency.num_neighbours;k++){
		neighbour_array[k]=maxConstituency.neighbours[k];
	}

	int l;
	for(l=0;l<maxConstituency.num_neighbours;l++){
		unsigned int index =neighbour_array[l];
		printf("%s\n",constituencies[index].name);
	}

	int m;
	int min=100;
	int minIndex;
	struct Constituency minConstituency;

	for(m=0;m<num_constituencies;m++){
		
		int num_neighbours = constituencies[m].num_neighbours;
		
		if(num_neighbours<min){
			min=num_neighbours;
			minIndex=m;
		}
	}
	minConstituency=constituencies[minIndex];


	printf("\n%s has the least bordering constituencies:\n",minConstituency.name);

	unsigned int min_neighbour_array[minConstituency.num_neighbours];

	int n;
	for(n=0;n<minConstituency.num_neighbours;n++){
		min_neighbour_array[n]=minConstituency.neighbours[n];
	}

	int o; 
	for(o=0;o<minConstituency.num_neighbours;o++){
		unsigned int index =min_neighbour_array[o];
		printf("%s\n",constituencies[index].name);
	}

	int z;
	for(z=0;z<num_constituencies;z++){
		destruct_Constituency(&constituencies[z]);
	}
	return 0;
}
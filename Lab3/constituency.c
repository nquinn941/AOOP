#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constituency.h"

void construct_Constituency(struct Constituency *c,char *name,const unsigned int *neighbours,unsigned int num_neighbours){
	c->name = (char*) malloc(strlen(name) * sizeof(char));
	strncpy(c->name, name, strlen(name));
	

	c->neighbours = (unsigned int*) malloc(num_neighbours * sizeof(unsigned int));
	int i;
	for(i=0;i<num_neighbours;i++){
		c->neighbours[i]=neighbours[i];
	}

	c->num_neighbours = num_neighbours;
}

void destruct_Constituency(struct Constituency *c){
	if(c->name!=NULL){
		free(c->name);
		c->name=NULL;
	}

	int i;
	for(i=0;i<c->num_neighbours;i++){
		c->neighbours[i]=0;
	}

	c->num_neighbours=0;
	
}

void print_Constituency(struct Constituency *c){
	printf("%s\t\t\t",c->name);
	printf("%d Neighbours\t\t",c->num_neighbours);
	int i;
	for(i=0;i<c->num_neighbours;i++){
		printf("%d ",c->neighbours[i]);
	}
	printf("\n");
}

int load_Constituencies(char *filename,struct Constituency *c[],unsigned int *num_constituencies){
	//open file in read only mode 
	FILE *fp = fopen(filename,"r");
	int number_cons_read;

	//check file has been opened 
	if(fp){
		printf("File Opened Successfully\n");
	}

	else{
		printf("File Not Opened\n");
		return 1;
	}

	//read in the first int for how many constituencies 
	fscanf(fp,"%d",&number_cons_read);
	*num_constituencies = number_cons_read;

	//allocate enough memory for all the constituency 
	*c = malloc(number_cons_read*sizeof(struct Constituency));

	int i;
	for(i=0;i<number_cons_read;i++){
		int number_of_neighbours;
		char comma;
		fscanf(fp,"%d %*c",&number_of_neighbours);
		//printf("Number of neighbours: %d  Neighbours: ",number_of_neighbours);
		

		int k;
		unsigned int *neighbour_numbers=malloc(number_of_neighbours*sizeof(unsigned int));
		for(k=0;k<number_of_neighbours;k++){
			fscanf(fp,"%d %*c",&neighbour_numbers[k]);
			//printf(" %d ", neighbour_numbers[k]);
		}
		
		char string_name [255];

		fscanf(fp,"%s \n",string_name);
		//printf(" Name: %s\n",string_name);

		struct Constituency *current = *c+i;
	
		construct_Constituency(current,string_name,neighbour_numbers,number_of_neighbours);

	
	}



	fclose(fp);
	return 1;

}
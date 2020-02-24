#ifndef __constituency__
#define __constituency__

struct Constituency{
	char *name;
	unsigned int *neighbours;
	unsigned int num_neighbours;
};

void construct_Constituency(struct Constituency *c,char *name,const unsigned int *neighbours, const unsigned int num_neighbours);
void destruct_Constituency(struct Constituency *c);
void print_Constituency(struct Constituency *c);
int load_Constituencies(char *filename,struct Constituency *c[],unsigned int *num_constituencies);

#endif



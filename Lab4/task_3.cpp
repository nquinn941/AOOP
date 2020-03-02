#include <iostream>
#include <new>
#include "cat.h"

int main(int argc, char* argv[]){

	int useful_args = argc-1;
	int number_of_cats=0;
	bool even;

	if(useful_args %2 ==0){
		number_of_cats= useful_args/2;
		even=true;
	}

	else{
		number_of_cats=(useful_args+1)/2;
		even=false;
	}

	std::cout << "Allocating clowder of size " << number_of_cats <<std::endl;
	Cat *cats = new Cat[number_of_cats];

	if(even){
		int i,j=0;
		for(i=1;i<argc;i+=2){
			cats[j] = Cat(argv[i],atoi(argv[i+1]));
			j++;
		}
	}

	else{
		int i,j=0;
		for(i=1;i<argc;i+=2){
			if(i==useful_args){
				cats[j] = Cat(argv[i]);
			}
			else{
				cats[j] = Cat(argv[i],atoi(argv[i+1]));
			}
			j++;
		}
	}
	
	int k;
	for(k=0;k<number_of_cats;k++){
		std::cout << cats[k].get_name() << " has " << cats[k].get_lives() << " lives."  <<std::endl;
	}

	int l;
	for(l=0;l<number_of_cats;l++){
		cats[l].~Cat();
	}
	return 0;
}
#include <iostream>
#include "Cat.h"

int main(int argc, char* argv[]){

	Cat a("Garfield",42);
	std::cout << std::hash<Cat>()(a) << " = "  << a <<std::endl;
	return 0;
}
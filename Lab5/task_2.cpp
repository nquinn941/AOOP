#include <iostream>
#include <string>
#include "Shape.h"

int main(int argc, char* argv[]){

	Shape *x = new Rectangle(0,0,1,1); 
	std::cout << x->to_string() <<std::endl;

	x->centre_at(2,3);
	std::cout <<x->to_string()<<std::endl;

	delete x;

	return 0;
}
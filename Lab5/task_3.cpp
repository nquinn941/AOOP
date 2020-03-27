#include <iostream>
#include <string>
#include "Shape.h"

int main(int argc, char* argv[]){

	Shape *ptr[10] = {
		new Circle(0,0,1),
		new Rectangle(0,0,1,1),
		new Triangle(0,0,1,1,0,1),
		new Circle(2,3,1),
		new Rectangle(1,3,2,2),
		new Triangle(0,0,2,2,0,2),
		new Circle(3,6,3),
		new Rectangle(1,2,3,4),
		new Triangle(1,1,2,2,1,2),
		new Circle(3,6,3),
	};

	for(int i=0;i<10;i++){
		std::cout << ptr[i]->to_string() <<std::endl;
	}

	for(int i=0;i<10;i++){
		ptr[i]-> centre_at (12,14);
	}

	for(int i=0;i<10;i++){
		std::cout << ptr[i]->to_string() <<std::endl;
	}

	for(int i=0;i<10;i++){
		delete ptr[i];
	}

	return 0;

}
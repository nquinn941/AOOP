#include "constituency.h"

#include <iostream>
#include <fstream>
#include<iterator>


std::istream& operator>>(std::istream &is, Constituency &constituency){

	int number_neighbours;
	is >> number_neighbours;


	std::vector<int> neighbours(number_neighbours);

	for(int i=0;i<number_neighbours;i++){
		is >> neighbours[i];
	}

	std::string name; 
	is >> name;

	Constituency new_constituency(name,neighbours);

	constituency = new_constituency;

	return is;

}

int main(int argc, char *argv[]){
	std::ifstream inputFile("wales.graph");
	if(!inputFile.is_open()){
		return 1;
	}

	int expected_constituencies;

	inputFile >>expected_constituencies;

	std::cout << "Expected Constituencies = " <<expected_constituencies <<std::endl;

	
	Constituency constituency;
	inputFile >> constituency;

	std::cout <<constituency.get_name();

	for(auto &neighbour : constituency.get_neighbours()){
		std::cout << ", " << neighbour;
	}

	std::cout <<std::endl;


	return 0;
}


#include "constituency.h"

#include <iostream>
#include <fstream>
#include <iterator>

std::istream& operator>>(std::istream &is, Constituency &constituency){

	int number_neighbours=0;
	is >> number_neighbours;


	std::vector<int> neighbours(number_neighbours);

	for(int i=0;i<number_neighbours;i++){
		is >> neighbours[i];
	}

	std::string name; 
	is >> name;

	constituency = Constituency(name,neighbours);

	return is;

}

int main(int argc, char *argv[]){
	std::ifstream inputFile("wales.graph");
    if(!inputFile.is_open()) {
        return 1;
    }

    
    int expected_constituencies;
    inputFile >> expected_constituencies;

    std::cout << "expected_constituencies = " << expected_constituencies << std::endl;

    std::vector<Constituency> constituencies;
    std::copy(std::istream_iterator<Constituency>(inputFile), std::istream_iterator<Constituency>(), std::back_inserter(constituencies));


    if(constituencies.size()!=expected_constituencies){
    	std::cout << "Couldnt find the expected amount of constituencies" <<std::endl;
    }

    for(Constituency current: constituencies) {
        std::cout << current.get_name();
        for(auto &neighbour: current.get_neighbours()) {
            std::cout << ", " << neighbour;
        }
        std::cout << std::endl;
    }

    return 0;
}


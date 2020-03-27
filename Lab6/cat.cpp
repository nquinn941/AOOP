#include "cat.h"
#include <iostream>
#include <string>
#include <sstream>


Cat::Cat():name("Tom"),lives(9){
	std::cout << "Default Constructor called... " <<std::endl;
}


Cat::Cat(std::string name): name(name),lives(9){
	std::cout << "Constructor called with name... " <<std::endl;
}

Cat::Cat(std::string name, unsigned int lives): name(name),lives(lives){
	std::cout << "Constructor called with name and lives... " <<std::endl;
}

Cat::~Cat(){
	std::cout << "Destructor Called... " <<std::endl;
}

std::string Cat::get_name()const {
	return name;

}

unsigned int Cat::get_lives()const {
	return lives;
}

void Cat::set_name(const std::string &new_name){
	std::cout << "set_name called... " <<std::endl;
	name=new_name;
}

void Cat::set_lives(const unsigned int& new_lives){
	std::cout << "set_lives called... " <<std::endl;

	if(get_lives()>0 && new_lives==0){
		lives=new_lives;
		set_name("The Cat Formerly Known As " + get_name());
	}
	if(new_lives>=get_lives()){
		return;
	}
	else{
		lives=new_lives;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Cat &cat){
	os<< cat.get_name()<< " has "<< cat.get_lives()<< " lives..."; 
	return os;
}

bool Cat::operator==(const Cat &cat) const{
	return (get_name() == cat.get_name()) && (get_lives() == cat.get_lives());
}

bool Cat::operator<(const Cat &cat) const{
	if(get_name() != cat.get_name()){
		return (get_name() < cat.get_name()); 
	}
	else{
		return(get_lives() < cat.get_lives());
	}
	
}

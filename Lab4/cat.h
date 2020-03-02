#pragma once 
#include <string>

class Cat{
public: 

	Cat();

	Cat(std::string name);

	Cat(std::string name,unsigned int lives);

	~Cat();

	std::string get_name()const;

	unsigned int get_lives()const ;

	void set_name(const std::string & name);

	void set_lives(const unsigned int &lives);

private:
	std::string name;
	unsigned int lives;
};
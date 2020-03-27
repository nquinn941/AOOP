#pragma once 
#include <string>
#include <functional>
#include <sstream>
#include <iostream>

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

	friend std::ostream& operator<<(std::ostream& os, const Cat &cat);

	bool operator==(const Cat &cat) const;

	bool operator<(const Cat &cat) const;

private:
	std::string name;
	unsigned int lives;
};



namespace std{

	template<>
	struct hash<Cat> {
		size_t operator()(const Cat &obj) const{ 
			std::stringstream ss;
			ss <<obj;

			std::size_t hash_result = std::hash<std::string>{}(ss.str());

			return hash_result;
		}
	};
		
}

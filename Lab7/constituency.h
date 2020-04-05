#pragma once 

#include <vector>
#include <string>

class Constituency{
private:

	std::string name;
	std::vector<int> neighbours;
	

public:
	Constituency() = default;
	Constituency(const std::string &name, const std::vector<int> &neighbours);
	const std::string& get_name() const;
	const std::vector<int>& get_neighbours() const;
};
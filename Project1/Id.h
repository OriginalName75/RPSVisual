#pragma once
#include <string>
class Id
{
public:
	int id;
	std::string name;
	bool operator==(const Id & b)
	{
		return b.id == this->id;
	}
	Id(std::string name);
	Id();
	~Id();
};


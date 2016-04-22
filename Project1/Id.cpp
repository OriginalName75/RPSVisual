#include "Id.h"

#include <iostream>

Id::Id(std::string name)
{
	
	static int id = 0;
	this->id = id++;
	
	this->name = name;
}

Id::Id():Id("")
{
	
}


Id::~Id()
{
}

#pragma once
#include <iostream>
class Person
{
protected:
	std::string name{ "Jan" };
	std::string surname{ "Kowalski" };
	size_t age;
public:
	virtual void introduce() = 0;//przedstawianie się
};


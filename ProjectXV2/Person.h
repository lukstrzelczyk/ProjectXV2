#pragma once
#include <iostream>
#include "Functions.h"
class Person
{
protected:
	std::string name{ "Jan" };
	std::string surname{ "Kowalski" };
	size_t age;
public:
	Person(std::string n = "Jan", std::string s = "Kowalski", size_t a = Random(18, 50));
	virtual void introduce() = 0;//przedstawianie się
};


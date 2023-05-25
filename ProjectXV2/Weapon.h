#pragma once
#include <iostream>
#include "Functions.h"
class Weapon
{
	std::string name;
	size_t caliber;
	size_t mass;
	std::string type;
public:
	Weapon(std::string n, float c, size_t m, std::string t);
	~Weapon();
	virtual void shot() = 0;
	virtual void reload() = 0;
	virtual void show() = 0;

};


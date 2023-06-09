#pragma once
#include <iostream>
#include "Functions.h"
class Wepon
{
protected:
	std::string name;
	size_t serial_num{ IDGenerator::get_id() };
	size_t caliber;

public:
	Wepon(std::string n, size_t c) : name{ n }, caliber{ c } {};
	~Wepon() {};
	virtual void printoperator(std::ostream& out) const = 0;
	virtual void shoot(size_t) = 0;
	virtual void reload() = 0;
	virtual void show() = 0;
	virtual void replenish_ammo() = 0;
	friend std::ostream& operator <<(std::ostream& out, const Wepon& S);
};


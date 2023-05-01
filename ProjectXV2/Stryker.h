#pragma once
#include <iostream>
#include "Vehicle.h"
#include "Functions.h"
class Stryker:public Vehicle
{
	std::string version{ "A" };
	std::string armament{ "30 mm Mk44 Bushmaster II gun" };
	size_t number_of_carried_soldiers{ 9 };
	const size_t ID{ IDGenerator::get_id() };
public:
	Stryker(std::string v, std::string arm, size_t no, size_t id, size_t w = 16470, size_t s = 97, size_t ft = 500, size_t f = 500, std::string t = "ICV", size_t c = 2);
	Stryker(const Stryker& clone);
	~Stryker();
	Stryker& operator=(const Stryker& clone) {
		this->Stryker::~Stryker();
		this->Stryker::Stryker(clone);

	}
};


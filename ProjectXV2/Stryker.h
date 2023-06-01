#pragma once
import "iostream";
#include "Vehicle.h"
#include "Functions.h"
class Stryker:public Vehicle
{
	std::string name;
	std::string version{ "A" };
	std::string armament{ "30 mm Mk44 Bushmaster II gun" };
	size_t number_of_carried_soldiers{ 9 };
	const size_t ID{ IDGenerator::get_id() };
public:
	Stryker(std::string nam = "Stryker", std::string v = "A", std::string arm = "30 mm Mk44 Bushmaster II gun", size_t no = 9, size_t id = IDGenerator::get_id(), size_t w = 16470, size_t s = 97, size_t mr = 500, size_t r = 500, std::string t = "ICV", size_t c = 2, std::string en = "Caterpillar C7", size_t p = 350, size_t ew = 588, size_t et = 1254);
	Stryker(const Stryker& clone);
	~Stryker();
	Stryker& operator=(const Stryker& clone) {
		this->Stryker::~Stryker();
		this->Stryker::Stryker(clone);
	}
	bool operator==(const Stryker& clone);
	bool operator<(const Stryker& clone);
	friend class MyCompare;
	void drive(const size_t& distance);
	void refuel();
	void show();
	void printoperator(std::ostream& out)const;
};


#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"
#include "Stryker.h"
#include "Vehicle.h"
#include "Person.h"
#include "Csoldier.h"
#include "Officer.h"

class Unit
{
	static Unit* unit;
	std::string name{"Company A"};
	std::string type;
	Officer* leader{ nullptr };
	std::vector<Person*> soldiers;
	std::vector<Stryker> vehicles;
public:
	Unit(std::string n = "Company A", std::string t = "Motorized",size_t nos=Random(20,40),size_t nov=Random(2,5));
	~Unit();
	Stryker operator[](const size_t& index);
	size_t get_soldiers_size()const;
	size_t get_vehicles_size()const;
	void show_soldier(const size_t& index);
	void add_order(const size_t& index, std::string order);
	void take_away_order(const size_t& index, size_t& idx);
	void operator++();
	void operator--();
	friend std::istream& operator>>(std::istream& in, Unit& U);
	friend std::ostream& operator<<(std::ostream& out, Unit& U);
	static Unit* get_Unit();
	void delete_soldier(const size_t& index);
};


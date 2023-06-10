#pragma once
#include <iostream>
#include <memory>
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
#include <map>

class Unit
{
	class MyCompare {	
	public:
		friend class Unit;
		bool operator()(Stryker s, const Stryker t) const {
			return s < t;
		}
	};
	static Unit* unit;
	std::string name{"Company A"};
	std::string type;
	std::unique_ptr<Officer> leader{ nullptr };
	std::vector<std::shared_ptr<Person>> soldiers;
	std::vector<Stryker> vehicles;
	std::map<Stryker, std::vector<std::shared_ptr<Person>>,MyCompare> sol_in_veh;
public:
	void save_to_file();
	Unit(std::string n = "Company A", std::string t = "Motorized",size_t nos=Random(20,40),size_t nov=Random(2,4));
	~Unit();
	Stryker& operator[](const size_t& index);
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
	void enlistment();
	void aging();
	void assign();
	void show_map()const;
};


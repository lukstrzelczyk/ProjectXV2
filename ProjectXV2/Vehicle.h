#pragma once
#include <iostream> 
#include "Engine.h"
#include "Diesel.h"
#include "Functions.h"

class Vehicle
{
protected:
	Engine* engine;
private:
	size_t weight{ 1000 };
	size_t speed{50};
	const size_t max_range{100};
	size_t range{100};
	const std::string type{"Vehicle"};
	size_t crew{ 2 };
	//to do list of crewman nwe class crewman
public:
	Vehicle(size_t w = 0, size_t s = 0, size_t ft = 0, size_t f = 0, std::string t = "", size_t c = 0) ;
	~Vehicle();
	virtual void refuel() = 0;
	virtual void drive() = 0;
	size_t get_weight()const;
	size_t get_speed()const;
	size_t get_range()const;
	size_t get_max_range()const;
	size_t get_crew()const;
	std::string get_type()const;
};


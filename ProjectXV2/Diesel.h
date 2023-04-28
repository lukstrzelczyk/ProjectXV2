#pragma once
#include <iostream>

#include "Engine.h"
class Diesel: public Engine
{
	std::string name;
	const std::string fuel_type{ "Diesel" };
	const size_t combustion{ 15 };//spalanie 10l/100km
public:
	Diesel(std::string n="Caterpillar C7", size_t p=350, size_t w= 588, size_t t=1254);
	void show_properties();
};


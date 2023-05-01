#include "Diesel.h"
#include <iostream>
#include <iomanip>

Diesel::Diesel(std::string n, size_t p , size_t w, size_t t) : name{n},Engine(p,w,t)
{}

std::string Diesel::get_name() const
{
	return name;
}

std::string Diesel::get_fuel_t() const
{
	return fuel_type;
}

size_t Diesel::get_combustion()const {
	return combustion;
}

void Diesel::show_properties()
{
	std::cout << std::setw(12) << "Name:" << name << std::endl;
	std::cout << std::setw(12) << "Power: " << get_p() << " hp"<<std::endl;
	std::cout << std::setw(12) << "Weight: " << get_w() << " kg"<<std::endl;
	std::cout << std::setw(12) << "Torque: " << get_t() << " N/m"<<std::endl;
	std::cout << std::setw(12) << "Fuel type: " << fuel_type << std::endl;
	std::cout << std::setw(12) << "Combustion: " << combustion<<"l/100km" << std::endl;
}

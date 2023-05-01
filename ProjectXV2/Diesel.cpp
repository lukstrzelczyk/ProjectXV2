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
	std::cout  << "Name:" << std::setw(12) << name << std::endl;
	std::cout  << "Power: " << std::setw(12) << get_p() << " hp"<<std::endl;
	std::cout  << "Weight: " << std::setw(12) << get_w() << " kg"<<std::endl;
	std::cout  << "Torque: " << std::setw(12) << get_t() << " N/m"<<std::endl;
	std::cout  << "Fuel type: " << std::setw(12) << fuel_type << std::endl;
	std::cout  << "Combustion: " << std::setw(12) << combustion<<"l/100km" << std::endl;
}

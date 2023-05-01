#include "Vehicle.h"

Vehicle::Vehicle(size_t w=0, size_t s=0, size_t ft=0, size_t f=0, std::string t="", size_t c=0) : weight{w}, speed{s}
, max_range{ ft }, range{ f }, type{ t }, crew{ c } {
	engine = nullptr;
}

Vehicle::~Vehicle()
{
	delete engine;
}

size_t Vehicle::get_weight() const
{
	return weight;
}
size_t Vehicle::get_speed()const
{
	return speed;
}
size_t Vehicle::get_range()const
{
	return range;
}
size_t Vehicle::get_max_range()const
{
	return max_range;
}
size_t Vehicle::get_crew()const
{
	return crew;
}
std::string Vehicle::get_type()const
{
	return type;
}
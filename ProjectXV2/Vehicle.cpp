#include "Vehicle.h"

Vehicle::Vehicle(size_t w, size_t s, size_t ft, size_t f, std::string t, size_t c) : weight{w}, speed{s}
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
void Vehicle::set_range(const size_t&r)
{
	range = r;
}
std::string Vehicle::get_type()const
{
	return type;
}
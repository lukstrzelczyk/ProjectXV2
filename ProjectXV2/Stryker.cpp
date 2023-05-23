#include "Stryker.h"
#include <Windows.h>


Stryker::Stryker(std::string nam, std::string v, std::string arm, size_t no, size_t id, size_t w, size_t s, size_t mr, size_t r, std::string t, size_t c, std::string en, size_t p, size_t ew, size_t et)
	:name{nam},version{v},armament{arm},number_of_carried_soldiers{no},ID{id},Vehicle{w,s,mr,r,t,c}
{
	engine = new Diesel{ en,p,ew,et };
}
Stryker::Stryker(const Stryker& clone):ID{clone.ID},Vehicle{clone.get_weight(),clone.get_speed(),
clone.get_max_range(),clone.get_range(),clone.get_type(),clone.get_crew()}
{
	name = clone.name;
	delete engine;
	version = clone.version;
	armament = clone.armament;
	number_of_carried_soldiers = clone.number_of_carried_soldiers;
	engine = new Diesel{ clone.engine->get_name(),clone.engine->get_p(),clone.engine->get_w(),clone.engine->get_t() };
}

Stryker::~Stryker()
{
	delete engine;
	engine = nullptr;
	
}

void Stryker::drive(const size_t& distance) {
	if (get_range() == 0)std::cout << "Vehicle has no fuel" << std::endl;
	if (distance >= get_range()) {
		std::cout << "Vehicle has driven " << get_range() << "km and now is stationary due to lack of fuel" << std::endl;
		set_range(0);
	}
	else {
		set_range(get_range() - distance);
		std::cout << "Vehicle has driven " << distance << "km and has fuel for another " << get_range() << "km" << std::endl;
	}
	Sleep(2000);
}

bool Stryker::operator==(const Stryker& clone)
{
	return (ID==clone.ID)? true : false ;
}

void Stryker::refuel()
{
	if(get_range()!=get_max_range())
	set_range(get_max_range());
	std::cout << "Fuel tank is full" << std::endl;
}

bool Stryker::operator<(const Stryker& clone)
{

	return ID<clone.ID;
}

void Stryker::show()
{
	std::cout<< name << "  " << version << std::endl;
	std::cout << "Type: " << get_type() << std::endl;
	std::cout << "Number of carried soldeirs: " << number_of_carried_soldiers << std::endl;
	std::cout << "Crew: " << get_crew() << std::endl;
	std::cout << "Armament: " << armament << std::endl;
	std::cout << "ID: " << ID << std::endl;
	std::cout << "Engine: ";
	engine->show_properties();
	std::cout << "Weight: " << get_weight() << std::endl;
	std::cout << "Speed: " << get_speed() << std::endl;
	std::cout << "Max range: " << get_max_range() << std::endl;
	std::cout << "Range: " << get_range() << std::endl;
}

void Stryker::printoperator(std::ostream& out) const
{

	out << name << "  " << version << std::endl;
	out << "Type: " << get_type() << std::endl;
	out << "Number of carried soldeirs: " << number_of_carried_soldiers << std::endl;
	out << "Crew: " << get_crew() << std::endl;
	out << "Armament: " << armament << std::endl;
	out << "ID: " << ID << std::endl;
	out << "Engine: " << std::endl;
	engine->show_properties();
	out << "Weight: " << get_weight() << std::endl;
	out << "Speed: " << get_speed() << std::endl;
	out << "Max range: " << get_max_range() << std::endl;
	out << "Range: " << get_range() << std::endl;
}


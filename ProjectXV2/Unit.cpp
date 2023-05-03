#include "Unit.h"

Unit* Unit::unit = nullptr;

Unit::Unit(std::string n, std::string t, size_t nos, size_t nov): name{n},type{t}
{
	leader = new Officer;
	for (auto i = 0; i < nos; i++) {
		soldiers.push_back(new Csoldier);
	}
	for (auto i = 0; i < nov; i++) {
		vehicles.push_back(Stryker::Stryker());
	}
}

Unit::~Unit()
{
	delete leader;
	for (auto i = soldiers.begin(); i != soldiers.end(); ++i) {
		delete *i;
	}
}

Stryker Unit::operator[](const size_t& index)
{
	return vehicles.at(index);
}

size_t Unit::get_soldiers_size() const
{
	return soldiers.size();
}

size_t Unit::get_vehicles_size()const {
	return vehicles.size();
}

void Unit::show_soldier(const size_t& index)
{
	soldiers.at(index)->show();
}

void Unit::add_order(const size_t& index, std::string order)
{
	soldiers.at(index)->add_order(order);
}

void Unit::take_away_order(const size_t& index, size_t& idx)
{
	if (soldiers.at(index)->get_num()) {
		idx = Random(0, soldiers.at(index)->get_num() - 1);
		soldiers.at(index)->take_away_order(idx);
	}
	else std::cout << "this soldier has no commendations\n";
	Sleep(1000);
}

void Unit::operator++()
{
	vehicles.push_back(Stryker::Stryker());
}

void Unit::operator--()
{
	vehicles.pop_back();
}

Unit* Unit::get_Unit()
{
	if (!unit) {
		unit = new Unit;
	}
	return unit;
}

void Unit::delete_soldier(const size_t& index)
{
	auto i = soldiers.begin();
	i = i + index;
	soldiers.erase(i);
}

std::istream& operator>>(std::istream& in, Unit& U)
{
	std::string line;
	while (std::getline(in, line)) {
		U.soldiers.push_back(new Csoldier(Csoldier::load(line)));
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, Unit& U)
{
	out << "=============== Company " << U.name << " ===============" << std::endl;
	out << "leader:\n";
	U.leader->introduce();
	out << "=============================================\n";
	out << "Company type: " << U.type << std::endl;
	out << "=============================================\n";
	out << "Company size: " << U.soldiers.size() << std::endl;
	out << "=============================================\n";
	out << "soldiers: \n";
	for (auto i = 0; i <U.soldiers.size(); i = i + 3) {
		out << std::setw(10) << "ID: " << std::setw(30) << U.soldiers.at(i)->get_ID()<< std::setw(5) << "";
		if (i + 1 < U.soldiers.size()) {
			out << std::setw(30) << U.soldiers.at(i+1)->get_ID() << std::setw(5) << "";
			if (i + 2 < U.soldiers.size()) {
				out << std::setw(30) << U.soldiers.at(i+2)->get_ID();
			}
		}
		out << std::endl << std::setw(10) << "Name: " << std::setw(30) << U.soldiers.at(i)->get_name() + " " + U.soldiers.at(i)->get_surname() << std::setw(5) << "";
		if (i + 1 < U.soldiers.size()) {
			out << std::setw(30) << U.soldiers.at(i+1)->get_name() + " " + U.soldiers.at(i+1)->get_surname() << std::setw(5) << "";
			if (i + 2 < U.soldiers.size()) {
				out << std::setw(30) << U.soldiers.at(i+2)->get_name() + " " + U.soldiers.at(i+2)->get_surname();
			}
		}
		out << std::endl << std::setw(10) << "Rank: " << std::setw(30) << U.soldiers.at(i)->get_rank() << std::setw(5) << "";
		if (i + 1 < U.soldiers.size()) {
			out << std::setw(30) << U.soldiers.at(i+1)->get_rank() << std::setw(5) << "";
			if (i + 2 < U.soldiers.size()) {
				out << std::setw(30) << U.soldiers.at(i+2)->get_rank();
			}
		}
		out << std::endl << std::endl;
	}
	out << "=============================================\n";
	out << "Number of vehicles: "<<U.vehicles.size()<<std::endl;
	out << "Vehicle: " << std::endl;
	for (auto i = U.vehicles.begin(); i != U.vehicles.end(); ++i) {
		out << *i;
		out << "------------------------------------------------------\n";
	}
	return out;
}

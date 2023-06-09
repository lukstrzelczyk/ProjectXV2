#include "Bushmaster_30.h"

Bushmaster_30::Bushmaster_30(std::string n = "30 mm Mk44 Bushmaster II gun", size_t c = 30, std::string t = "belt fed", size_t s = 300) :
	Wepon(n, c), mag_type{ t }, belt_size{ s }
{
	for (auto i = 0; i < 300;i++) {
		if (i % 5 == 0)belt.push_back(ammo::ammo("HEIT", 30));
		else if (i % 5 == 4)belt.push_back(ammo::ammo("API", 30));
		else belt.push_back(ammo::ammo());

	}
}

void Bushmaster_30::prtinoperator(std::ostream& out)
{
	out << "Name:          "<<name << std::endl;
	out << "Serial Number: "<<serial_num << std::endl;
	out << "Caliber:       "<<caliber << " mm" << std::endl;
	out <<mag_type << std::endl;
	out <<"Belt size:      " <<belt_size<<std::endl;
}


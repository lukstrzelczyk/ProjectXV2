#pragma once
#include <iostream>
#include <vector>
#include "Wepon.h"
#include <algorithm>
class Bushmaster_30 : public Wepon
{
	class ammo {
		size_t caliber{30};
		std::string type{"HEI"};
	public:
		ammo() = default;
		ammo(std::string t,size_t c ) :caliber{c}, type{t} {};
		friend class Bushmaster_30;
	};
	std::string mag_type;
	size_t belt_size;
	std::vector<ammo> belt;
public:
	Bushmaster_30(std::string, size_t, std::string, size_t);
	void prtinoperator(std::ostream& out);
	void shoot(size_t burst);
};


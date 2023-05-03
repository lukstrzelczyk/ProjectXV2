#include "Officer.h"

Officer::Officer(std::string cu= "Company A") :commanded_unit{ cu }, Csoldier("first lieutenant")
{}

void Officer::promote_soldier(Csoldier& soldier)
{
	size_t index{ find_string(enlisted_ranks, 3, soldier.get_rank()) };
	if (index == -1)std::cout << "unknow rank";
	else if (index == 2)std::cout << "This soldier has  highest possible rank for enlisted soldier";
	else soldier.set_rank(enlisted_ranks[index + 1]);
}

void Officer::introduce()
{
	Csoldier::introduce();
	std::cout << "Commanded unit: " << commanded_unit << std::endl;
}

void Officer::show() {
	Csoldier::show();
	std::cout << "Commanded unit: " << commanded_unit << std::endl;
}
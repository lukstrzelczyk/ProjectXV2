#include "Officer.h"

Officer::Officer(const Officer& clone):Csoldier(clone)
{
	/*age = clone.age;
	name = clone.name;
	surname = clone.surname;
	set_rank( clone.get_rank());
	num_of_dec = sample.num_of_dec;
	if (num_of_dec) decorations = new CCommendation * [num_of_dec];
	for (auto i = 0; i < num_of_dec; i++) {
		decorations[i] = new CCommendation;
		decorations[i]->commendation = sample.decorations[i]->commendation;
		decorations[i]->date = sample.decorations[i]->date;
	}*/
	commanded_unit = clone.commanded_unit;
}

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
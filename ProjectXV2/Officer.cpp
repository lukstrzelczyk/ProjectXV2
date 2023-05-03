#include "Officer.h"

Officer::Officer(const Officer& clone):Csoldier(clone)
{
	commanded_unit = clone.commanded_unit;
}

Officer::Officer(std::string cu, size_t _age, std::string _name, std::string _surname, std::string _rank, size_t num, size_t id):
	commanded_unit{cu},Csoldier(_age,_name,_surname,_rank,num,id)
{}

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

void Officer::printoperator(std::ostream& out) const
{
	out<<commanded_unit<<';';
	Csoldier::printoperator(out);
}

Officer* Officer::load(std::string text)
{
	size_t pos{};//zmienne używane przy .find()
	size_t pos1{};
	std::string* date = nullptr;
	std::string* orders = nullptr;
	std::string temp{};
	std::string name, surname, rank,cu;
	size_t age, id, num;
	pos1 = text.find(';');
	cu = text.substr(0, pos1);
	pos = text.find(';', pos1 + 1);
	name = text.substr(pos1 + 1, pos - 1 - pos1);
	pos1 = text.find(';', pos + 1);
	surname = text.substr(pos + 1, pos1 - 1 - pos);
	pos = text.find(';', pos1 + 1);
	rank = text.substr(pos1 + 1, pos - 1 - pos1);
	pos1 = text.find(';', pos + 1);
	temp = text.substr(pos + 1, pos1 - 1 - pos);
	age = digit_check(temp, "age");
	pos = text.find(';', pos1 + 1);
	temp = text.substr(pos1 + 1, pos - 1 - pos1);
	id = digit_check(temp, "ID");
	pos1 = text.find(';', pos + 1);
	temp = text.substr(pos + 1, pos1 - 1 - pos);
	num = digit_check(temp, "num");
	if (num) {
		date = new std::string[num];
		orders = new std::string[num];
		for (auto i = 0; i < num; i++) {
			pos = text.find(';', pos1 + 1);
			orders[i] = text.substr(pos1 + 1, pos - 1 - pos1);
			pos1 = text.find(';', pos + 1);
			date[i] = text.substr(pos + 1, pos1 - 1 - pos);
		}

	}
	Officer* nowy=new Officer{cu, age,name,surname,rank,num,id };
	for (auto i = 0; i < num; i++) {
		nowy->set_order(i, orders[i], date[i]);
	}
	return nowy;
}

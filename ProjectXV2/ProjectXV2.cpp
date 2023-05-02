#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
#include "Stryker.h"
#include "Vehicle.h"
#include "Person.h"
#include "Csoldier.h"

int main()
{
	//Stryker* s = new Stryker;
	//std::cout << (*s);
	////s->show();
	//s->drive(100);
	//std::cout << (*s);
	////s->show();
	//s->refuel();
	//std::cout << (*s);
	//delete s;
	std::fstream file;
	std::string line;
	file.open("Soldier.txt", std::ios::out);
	Csoldier* p = new Csoldier(2);
	p->show();
	file << (*p);
	file.close();
	file.open("Soldier.txt", std::ios::in);
	std::getline(file, line);
	Csoldier* d = new Csoldier(Csoldier::load(line));
	file.close();
	/*if(p->get_num())
	p->take_away_order(Random(0, p->get_num()));
	std::cout << (*p);
	p->add_order(orders[1]);
	std::cout << (*p);*/
	d->show();

	delete p;
	delete d;
}


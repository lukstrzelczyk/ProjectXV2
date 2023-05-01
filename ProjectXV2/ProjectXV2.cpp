#include <iostream>
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
	Csoldier* p = new Csoldier(2);
	std::cout<<(*p);
	if(p->get_num())
	p->take_away_order(Random(0, p->get_num()));
	std::cout << (*p);
	p->add_order(orders[1]);
	std::cout << (*p);
	delete p;
}


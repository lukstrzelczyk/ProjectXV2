#include <iostream>
#include "Functions.h"
#include "Stryker.h"
#include "Vehicle.h"

int main()
{
	Stryker* s = new Stryker;
	std::cout << (*s);
	//s->show();
	s->drive(100);
	std::cout << (*s);
	//s->show();
	s->refuel();
	std::cout << (*s);
	delete s;
	
}


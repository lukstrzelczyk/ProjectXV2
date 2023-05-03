#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Functions.h"
#include "Stryker.h"
#include "Vehicle.h"
#include "Person.h"
#include "Csoldier.h"
#include "Officer.h"

#define DBG 1
 
int main()
{
#ifdef DBG
	Csoldier* p = new Csoldier;
	Officer* d = new Officer;
	p->show();
	d->show();
	d->promote_soldier(*p);
	p->show();
	delete p;
	delete d;

	return 0;
#endif // !DBG



	std::string decision;
	size_t cons{ 0 };
	//CCompany* kompania{ nullptr };
	bool flag{ true };
	do {
		system("cls");
		std::cout << "\t\tProject X\n\n";
		std::cout << "1. Init\n";
		std::cout << "2. Manage Company\n";
		std::cout << "3. Add volunteer\n";
		std::cout << "4. Enlistment\n";
		std::cout << "5. Next Year\n";
		std::cout << "6. Add getline\n";
		std::cout << "7. Load from file\n";
		std::cout << "8. Save to file\n";
		std::cout << "0. Exit\n";
		std::getline(std::cin, decision);
		switch (input_check(decision, 0, 8))
		{
		case 1:
			break;
		case 2:
			system("cls");
			
			break;
		case 3:
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 0: flag = false;
			//delete kompania;
			break;
		default:
			std::cout << "This option does not exist. Try again";
			Sleep(1500);
			break;
		}
	} while (flag);
	return 0;
}


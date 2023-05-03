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
#include "Unit.h"

void manage_soldier(const size_t& index);
void manage_company();
void load_from_file();
void manage_vehicle(const size_t& index);


//#define DBG 1
 
int main()
{
#ifdef DBG
	std::cout << (*Unit::get_Unit());
	delete Unit::get_Unit();
	return 0;
#endif // !DBG

	std::string decision;
	size_t cons{ 0 };
	//CCompany* kompania{ nullptr };
	bool flag{ true };
	do {
		system("cls");
		std::cout << "\t\tProject X\n\n";
		std::cout << "1. Manage Company\n";
		std::cout << "2. Add vehicle\n";
		std::cout << "3. Enlistment\n";
		std::cout << "4. Next Year\n";
		std::cout << "5. Load from file\n";
		std::cout << "6. Save to file\n";
		std::cout << "7. Delete vehicle\n";
		std::cout << "8. Manage vehicle\n";
		std::cout << "0. Exit\n";
		std::getline(std::cin, decision);
		switch (input_check(decision, 0, 8))
		{
		case 1:
			manage_company();
			break;
		case 2:
			++(*Unit::get_Unit());
			break;
		case 3:
			Unit::get_Unit()->enlistment();
			break;
		case 4:
			Unit::get_Unit()->aging();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			Unit::get_Unit()->save_to_file();
			break;
		case 7:
			if (Unit::get_Unit()->get_vehicles_size())
				--(*Unit::get_Unit());
			else {
				std::cout << "There isn't any vehicles left\n";
				Sleep(1000);
			}
			break;
		case 8:
			manage_vehicle(Random(0,Unit::get_Unit()->get_vehicles_size()-1));
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

void manage_company() {
	std::string dec{ "error" };
	bool flag = true;
	do {
		system("cls");
		std::cout << (*Unit::get_Unit());
		std::cout << std::endl << "================================\n";
		std::cout << "1. manage soldier\n";
		std::cout << "2. delete soldier\n";
		std::cout << "3. go back to menu\n";
		std::getline(std::cin, dec);
		switch (input_check(dec, 1, 3)) {
		case 1:
			manage_soldier( Random(0, Unit::get_Unit()->get_soldiers_size() - 1));
			break;
		case 2:
			if (Unit::get_Unit()->get_soldiers_size())
				Unit::get_Unit()->delete_soldier(Random(0, Unit::get_Unit()->get_soldiers_size() - 1));
			else {
				std::cout << "There isn't any soldiers left";
				Sleep(1000);
			}
			break;
		case 3:
			flag = false;
			break;
		default:
			std::cout << "This option does not exist. Try again";
			Sleep(1500);
			break;
		}
	} while (flag);
}

void manage_soldier(const size_t& index) {
	size_t t = 0;
	std::string dec{ "error" };
	bool flag = true;
	do {
		system("cls");
		Unit::get_Unit()->show_soldier(index);
		std::cout << std::endl << "================================\n";
		std::cout << "1. add commendation\n";
		std::cout << "2. take away commendation\n";
		std::cout << "3. go back to menu\n";
		std::getline(std::cin, dec);
		switch (input_check(dec, 1, 3)) {
		case 1:
			//kompania->add_commendation(index,orders[Random(0,3)]);
			Unit::get_Unit()->add_order(index,orders[Random(0, 3)]);
			break;
		case 2:
			Unit::get_Unit()->take_away_order(index,t);
			break;
		case 3:
			flag = false;
			break;
		default:
			std::cout << "This option does not exist. Try again";
			Sleep(1500);
			break;
		}
	} while (flag);
}
void load_from_file()
{
	std::ifstream myFile("Soldier.txt");
	if (myFile.is_open()) {
		myFile >> (*Unit::get_Unit());
	}
	else std::cout << "unable to open the file\n";
	myFile.close();
}

void manage_vehicle(const size_t& index) {
	size_t t = 0;
	std::string dec{ "error" };
	bool flag = true;
	do {
		system("cls");
		(*Unit::get_Unit())[index].show();
		std::cout << std::endl << "================================\n";
		std::cout << "1. Drive\n";
		std::cout << "2. Refuel\n";
		std::cout << "3. go back to menu\n";
		std::getline(std::cin, dec);
		switch (input_check(dec, 1, 3)) {
		case 1:
			//kompania->add_commendation(index,orders[Random(0,3)]);
			(*Unit::get_Unit())[index].drive(Random(24,600));
			break;
		case 2:
			(*Unit::get_Unit())[index].refuel();
			break;
		case 3:
			flag = false;
			break;
		default:
			std::cout << "This option does not exist. Try again";
			Sleep(1500);
			break;
		}
	} while (flag);
}
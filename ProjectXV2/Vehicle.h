#pragma once
#include <iostream> 
#include "Engine.h"
#include "Diesel.h"
#include "Functions.h"

class Vehicle
{
protected:
	Engine* engine;
private:
	size_t weight{ 1000 };
	size_t speed{50};
	const size_t fuel_tank{100};
	size_t fuel{100};
	const std::string type{"Vehicle"};
public:
	Vehicle(size_t w, size_t s, size_t ft, size_t f, std::string t) : weight{ w }, speed{ s }
	, fuel_tank{ ft }, fuel{ f }, type{ t } {
		engine = new Diesel;
	};
	~Vehicle() {
		delete engine;
	}
	virtual void refuel() = 0;

};


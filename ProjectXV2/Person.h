#pragma once
#include <iostream>
#include "Functions.h"
class Person
{
protected:
	std::string name{ "Jan" };
	std::string surname{ "Kowalski" };
	size_t age;
public:
	Person(std::string n = "Jan", std::string s = "Kowalski", size_t a = Random(18, 50));
	virtual void introduce() = 0;//przedstawianie się
	virtual void printoperator(std::ostream& out) const =0;
	virtual void show() = 0;
	virtual std::string get_name()const=0;
	virtual std::string get_surname()const = 0;
	virtual std::string get_rank()const = 0;
	virtual std::string get_commendation(const size_t& index)const = 0;
	virtual std::string get_date(const size_t& index)const = 0;
	virtual size_t get_ID()const = 0;
	virtual size_t get_age()const = 0;
	virtual size_t get_num()const = 0;
	virtual void set_rank(const std::string& new_rank) = 0;
	virtual void set_age(const size_t& a) = 0;
	virtual void set_order(const size_t& index, std::string order, std::string date) = 0;
	friend std::ostream& operator <<(std::ostream& out, const Person& S);
	virtual void add_order(std::string order)=0;
	virtual void take_away_order(const short& index)=0;

};


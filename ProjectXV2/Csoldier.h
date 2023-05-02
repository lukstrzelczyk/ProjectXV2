#pragma once
#include "Person.h"
#include <iostream>
#include "Functions.h"

const std::string orders[] = { "Medal of Honor","Distinguished Service Cross","Purple Heart","Bronze Star Medal" };
const std::string enlisted_ranks[] = { "private","sargent","corporal" };
const std::string imiona[8] = { "Gniewko","Mieszko","Andrzej","Zygmunt","Jan","Kazimierz","Judasz","Tomasz" };
const std::string nazwiska[8] = { "Strzelczyk","Kowalski","Spokojny","Wielki","Mniejszy","Tomasz","Von Richtoffen","Zdradziecki" };

class Csoldier :   public Person
{
	const size_t ID{ IDGenerator::get_id() };
	std::string rank;
	class CCommendation {
		std::string commendation;
		std::string date;
	public:
		CCommendation();
		CCommendation(std::string com, std::string date);
		friend std::ostream& operator <<(std::ostream& out, const Csoldier& S);
		friend class Csoldier;
	};
	friend std::ostream& operator <<(std::ostream& out, const Csoldier& S);
	CCommendation** decorations{ nullptr };
	size_t num_of_dec;
public: 
	Csoldier(size_t _age, std::string _name, std::string _surname, std::string _rank, size_t num, size_t id);
	Csoldier(std::string rank);
	Csoldier(const Csoldier& sample);
	Csoldier(std::string text, int cos);
	Csoldier(size_t num);
	~Csoldier();
	//-------------------
	std::string get_name()const;
	std::string get_surname()const;
	std::string get_rank()const;
	std::string get_commendation(const size_t& index)const;
	std::string get_date(const size_t& index)const;
	size_t get_ID()const;
	size_t get_age()const;
	size_t get_num()const;
	//-------------------

	void show();
	void introduce();//show without orders
	void add_order(std::string order);
	void take_away_order(const short& index);
	static Csoldier load(std::string text);
	Csoldier& operator=(const Csoldier& clone) {
		this->Csoldier::~Csoldier();
		this->Csoldier::Csoldier(clone);
	}
	
};


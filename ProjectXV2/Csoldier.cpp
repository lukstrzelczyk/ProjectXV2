#include "Csoldier.h"
#include <iomanip>
#include <Windows.h>
#include <string>

enum { jan = 1, feb = 2, mar = 3, apr = 4, may = 5, jun = 6, jul = 7, aug = 8, sept = 9, oct = 10, nov = 11, dec = 12 };

Csoldier::CCommendation::CCommendation()
{
	commendation = orders[Random(0, 4)];
	size_t day{ 1 }, month{ Random(1,12) }, year{ Random(1996,2018) };
	if (month == feb)day = Random(1, 28);
	else if (month == apr || month == jun || month == sept || month == nov)day = Random(1, 30);
	else day = Random(1, 31);
	date.append(std::to_string(day));
	date.append(".");
	date.append(std::to_string(month));
	date.append(".");
	date.append(std::to_string(year));
}
Csoldier::CCommendation::CCommendation(std::string com, std::string dat):commendation{com},date{dat}
{}

std::ostream& operator <<(std::ostream& out, const Csoldier& S) {
	out << "\t" << S.name << " " << S.surname << std::endl;
	out << "Rank:               " << S.rank << std::endl;
	out << "Age:                " << S.age << std::endl;
	out << "ID:                 " << S.ID << std::endl;
	out << "Ccomendations:      ";
	if (S.num_of_dec == 0)out << "No commendations\n";
	else {
		for (auto i = 0; i < S.num_of_dec; i++) {
			out << S.decorations[i]->commendation << " " << S.decorations[i]->date << "; ";
		}
		out << std::endl;
	}
	return out;
}

Csoldier::Csoldier()
{
	age = Random(18, 54);
	name = imiona[Random(0, 7)];
	surname = nazwiska[Random(0, 7)];
	rank = enlisted_ranks[0];
	num_of_dec = Random(0, 3);
	if (num_of_dec) decorations = new CCommendation*[num_of_dec];
	for (auto i = 0; i < num_of_dec; i++) {
		decorations[i] = new CCommendation;
	}
}

Csoldier::Csoldier(size_t _age = Random(18, 54), std::string _name = imiona[Random(0, 7)], std::string _surname = nazwiska[Random(0, 7)], std::string _rank = enlisted_ranks[0], size_t num = Random(0, 3), size_t id = Random(1, 765))
	:ID(id),  rank(_rank), num_of_dec(num)
{
	age = _age;
	surname = _surname;
	name = _name;
	if (num_of_dec) decorations = new CCommendation * [num_of_dec];
	for (auto i = 0; i < num_of_dec; i++) {
		decorations[i] = new CCommendation;
	}
}

Csoldier::Csoldier(std::string rank)
{
	age = Random(18, 54);
	name = imiona[Random(0, 7)];
	surname = nazwiska[Random(0, 7)];
	this->rank = rank;
	if (num_of_dec) decorations = new CCommendation * [num_of_dec];
	for (auto i = 0; i < num_of_dec; i++) {
		decorations[i] = new CCommendation;
	};
}

Csoldier::Csoldier(const Csoldier& sample) :ID(sample.ID)
{
	age = sample.age;
	name = sample.name;
	surname = sample.surname;
	rank = sample.rank;
	num_of_dec = sample.num_of_dec;
	if (num_of_dec) decorations = new CCommendation * [num_of_dec];
	for (auto i = 0; i < num_of_dec; i++) {
		decorations[i] = new CCommendation; 
		decorations[i]->commendation = sample.decorations[i]->commendation;
		decorations[i]->date = sample.decorations[i]->date;
	}
} //trzeba się zastanowić kiedy użyć!!!!!!!!!!!!!!

Csoldier::Csoldier(std::string text, int cos) {
	size_t pos{};//zmienne używane przy .find()
	size_t pos1{};
	std::string temp{};
	pos = text.find(';');
	name = text.substr(0, pos - 1);
	pos1 = text.find(';', pos + 1);
	surname = text.substr(pos + 1, pos1 - 1 - pos);
	pos = text.find(';', pos1 + 1);
	rank = text.substr(pos1 + 1, pos - 1 - pos1);
	pos1 = text.find(';', pos + 1);
	temp = text.substr(pos + 1, pos1 - 1 - pos);
	age = digit_check(temp, "age");
	num_of_dec = 0;
	decorations = nullptr;
}

Csoldier::Csoldier(size_t num)
{
	age = Random(18, 54);
	name = imiona[Random(0, 7)];
	surname = nazwiska[Random(0, 7)];
	rank = "private";
	num_of_dec = num;
	if (num_of_dec) decorations = new CCommendation * [num_of_dec];
	for (auto i = 0; i < num_of_dec; i++) {
		decorations[i] = new CCommendation;
	};
}

//---------------------------------------------------
//desruktor------------------------------------------

Csoldier::~Csoldier()
{
	if (num_of_dec) {
		for (auto i = 0; i < num_of_dec; i++)delete decorations[i];
		delete[] decorations;
	}
	decorations = nullptr;
	num_of_dec = 0;
}

void Csoldier::introduce()
{
	std::cout <<"Name:"<<std::setw(10)<<"" << name << std::endl;
	std::cout <<"Surname:" << std::setw(7)<<""<< surname << std::endl;
	std::cout <<"Rank:" << std::setw(10) << "" << rank << std::endl;
}

std::string Csoldier::get_name() const{ return name; }
std::string Csoldier::get_surname() const{ return surname; }
std::string Csoldier::get_rank() const{ return rank; }
std::string Csoldier::get_commendation(const size_t& index) const{ return decorations[index]->commendation; }
std::string Csoldier::get_date(const size_t& index) const{ return decorations[index]->date; }
size_t Csoldier::get_age()const { return age; }
size_t Csoldier::get_num() const { return num_of_dec; }
size_t Csoldier::get_ID()const { return ID; }

void Csoldier::add_order(std::string order)
{
	CCommendation** temp = new CCommendation*[num_of_dec + 1];
	for (auto i = 0; i < num_of_dec; i++) {
		temp[i] = decorations[i];
	}
	time_t now = time(0);
	tm t;
	std::string day;
	localtime_s(&t, &now);
	day = std::to_string(t.tm_mday);
	day.append(".");
	day.append(std::to_string(t.tm_mon + 1));
	day.append(".");
	day.append(std::to_string(t.tm_year + 1900));
	temp[num_of_dec] = new CCommendation(order,day);
	delete[] decorations;
	decorations = temp;
	num_of_dec++;
}

void Csoldier::take_away_order(const short& index)
{
	if (num_of_dec == 0) {
		std::cout << "This soldier has already no commendations";
		Sleep(1000);
		return;
	}
	else if (num_of_dec == 1) {
		delete[] this->decorations;
		this->decorations = nullptr;
	}
	else {
		CCommendation** temp = new CCommendation*[num_of_dec - 1];
		for (auto i = 0, j = 0; i < num_of_dec - 1; i++, j++)
		{
			if (j == index) {
				delete decorations[j];
				j++;
			}
			temp[i] = decorations[j];
		}
		delete[] this->decorations;
		this->decorations = temp;
	}
	num_of_dec--;
}

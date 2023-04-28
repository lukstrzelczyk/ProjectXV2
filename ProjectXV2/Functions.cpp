#include "Functions.h"
//#include "CCompany.h"
#include <random>
#include <string>
#include <cctype>
#include <Windows.h>

size_t input_check(std::string dec, size_t min, size_t max)
{
	if (dec.empty())return -1;
	bool is_ok = true;
	for (auto i = 0; i < dec.length(); i++) {
		if (!isdigit(dec.at(i))) return -1;
	}
	if (stoi(dec) < min || stoi(dec) > max) return -1;
	return stoi(dec);
}

size_t Random(size_t min, size_t max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<size_t> distrubition(min, max);
	return distrubition(eng);
}


size_t IDGenerator::_id = Random(1, 765);

size_t IDGenerator::get_id() {
	return _id++;
}

size_t digit_check(std::string& text, const std::string napis) {
	bool is_ok = true;
	do {
		if (is_ok == false) {
			std::cout << "Type in " << napis << " once again\n";
			std::getline(std::cin, text);
		}
		is_ok = true;
		for (int i = 0; i < text.length(); i++) {
			if (!isdigit(text.at(i))) {
				is_ok = false;
				break;
			}
		}
		if (is_ok) {
			if (stoi(text) < 0) is_ok = false;
		}
	} while (!is_ok);
	return stoi(text);
}

size_t find_string(const std::string tab[], const size_t& size, const std::string& text)
{
	size_t index{ 0 };
	for (index; index < size; index++) {
		if (text.compare(tab[index]) == 0)return index;
	}
	return -1;
}

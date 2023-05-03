#include "Person.h"

Person::Person(std::string n, std::string s, size_t a):name{n},surname{s},age{a}
{}

std::ostream& operator<<(std::ostream& out, const Person& S)
{
	S.printoperator(out);
	return out;
}

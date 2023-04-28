#pragma once
#include <iostream>

size_t input_check(std::string dec, size_t min, size_t max);

size_t Random(size_t min, size_t max);

class IDGenerator {
	static size_t _id;
public:
	static size_t get_id();
};

size_t digit_check(std::string& text, const std::string napis);

size_t find_string(const std::string tab[], const size_t& size, const std::string& text);


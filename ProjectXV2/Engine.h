#pragma once
class Engine
{
private:
	size_t power{ 0 };//horse power
	size_t weight{ 20 };//kg
	size_t torque{ 0 };// N/m
public:
	Engine(size_t p = 0, size_t w = 0, size_t t = 0) :power{ p }, weight{ w }, torque{ t } {};
	virtual void show_properties() = 0;
	size_t get_p()const { return power; }
	size_t get_w()const { return weight; }
	size_t get_t()const { return torque; }
	virtual std::string get_name()const = 0;
	void set_p(const size_t& p) { power = p; }
	void set_w(const size_t& w) { weight = w; }
	void set_t(const size_t& t) { torque = t; }
};


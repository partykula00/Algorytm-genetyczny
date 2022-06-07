#pragma once
#ifndef TPARAM_H_
#define TPARAM_H_

#include <string>

class Tparam
{
private:
	std::string name, description;
	double x_start, x_end, dx;
	int val_id;

public:
	Tparam(double x_start, double x_end, double dx, double val);
	Tparam(double x_start, double x_end, double dx);

	void set_name(std::string name) { this->name = name; }
	std::string get_name() { return name; }

	

	void set_description(std::string des) { description = des;}
	std::string get_description() { return description; }

	void set_range(double x_start, double x_end, double dx);

	void set_val(double val) { val_id = get_val_id(val); }
	double get_val() { return x_start + val_id * dx; }

	void info();
private:
	int get_val_id(double val);

};

#endif /*TPARAM_H*/
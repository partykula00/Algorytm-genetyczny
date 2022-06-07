#pragma once
#ifndef TGEN_H_
#define TGEN_H_

#include <string>

class Tgen
{
private:
	std::string name, description;
	double x_start, x_end, dx;
	int val_id;

public:
	Tgen(double x_start, double x_end, double dx, double val);
	Tgen(double x_start, double x_end, double dx);
	Tgen(std::string name, double x_start, double x_end, double dx);

	void set_name(std::string name) { this->name = name; }
	std::string get_name() { return name; }

	void set_rand_val();

	void set_description(std::string des) { description = des;}
	std::string get_description() { return description; }

	void set_range(double x_start, double x_end, double dx);
	void get_range();

	void set_val(double val) { val_id = get_val_id(val); }
	double get_val() { return x_start + val_id * dx; }

	

	void info();

	int get_val_id(double val);

};

#endif /*TPARAM_H*/
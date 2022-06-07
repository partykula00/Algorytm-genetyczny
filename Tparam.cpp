#include <iostream>
#include <math.h>

#include "Tparam.h"

using namespace std;

Tparam::Tparam(double x_start, double x_end, double dx, double val)
{
	set_range(x_start, x_end, dx);
	set_val(val);
}
Tparam::Tparam(double x_start, double x_end, double dx)
{
	set_range(x_start, x_end, dx);
}

void Tparam::set_range(double x_start, double x_end, double dx)
{
	this->x_start = x_start;
	this->x_end = x_end;
	this->dx = dx;
}

//void Tparam::set_val(double val) { val_id= get_val_id(val);}
//double Tparam::get_val(){double val = x_start + val_id *dx; return val;}

int Tparam::get_val_id(double val)
{
	if (val < x_start) return 0;
	else if (val > x_end) return (x_end - x_start) / dx;
	else
	{

		double x = x_start;
		int _id = 0;

		while (fabs(x + _id * dx - val) > dx / 2) _id++;

		return _id;
	}
}

void Tparam::info()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	cout << "++ Parameter range: \n";
	cout << "++ - Start value: " << x_start << "\n";
	cout << "++ - End value: " << x_end << "\n";
	cout << "++ - Step: " << dx << "\n";
	cout << "++ \n";
	cout << "++ Present value: " << get_val() << "\n";
	cout << "++ Present val_id: " << val_id << "\n";

	cout << "++++++++++++++++++++++++++++++++\n\n";
}
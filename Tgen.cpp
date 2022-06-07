#include <iostream>
#include <math.h>
#include <stdlib.h>

#include "Tgen.h"

using namespace std;


Tgen::Tgen(double x_start, double x_end, double dx, double val)
{   
	set_range(x_start, x_end, dx);
	set_val(val);
}
Tgen::Tgen(double x_start, double x_end, double dx)
{
	set_range(x_start, x_end, dx);
}
Tgen::Tgen(string name, double x_start, double x_end, double dx)
{
	set_name(name);
	set_range(x_start, x_end, dx);
}

void Tgen::set_range(double x_start, double x_end, double dx)
{
	this->x_start = x_start;
	this->x_end = x_end;
	this->dx = dx;
}
/*void Tgen::get_range()
{
	cout << "Start value:" << x_start << "\n";
	cout << "End value:" << x_end << "\n";
	cout << "Step:" << dx << "\n";
}
*/

void Tgen::set_rand_val()
{
	int vals_count = fabs(x_end - x_start) / dx + 1;
	val_id = rand() % vals_count;

}

//void Tparam::set_val(double val) { val_id= get_val_id(val);}
//double Tparam::get_val(){double val = x_start + val_id *dx; return val;}

int Tgen::get_val_id(double val)
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

void Tgen::info()
{
	cout << "\n";
	cout << "++ - Start value: " << x_start << "\n";
	cout << "++ - End value: " << x_end << "\n";
	cout << "++ - Step: " << dx << "\n";
	cout << "++ \n";
	cout << "++ Present value: " << get_val() << "\n";
	cout << "++ Present val_id: " << val_id << "\n";

	cout << "++++++++++++++++++++++++++++++++\n\n";
}
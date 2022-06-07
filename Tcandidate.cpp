#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Tcandidate.h"

using namespace std;


Tcandidate::Tcandidate()
{
	mark = 0;
	rand_gens_val();
}


void Tcandidate::rand_gens_val()
{
	for (int i = 0; i < GENS_COUNT; i++)
	{
		genotype[i].set_rand_val();
	}

}

int Tcandidate::rate()
{
	double x1 = genotype[0].get_val();
	double x2 = genotype[1].get_val();

	mark = pow((x1 + 3), 3) + x1 * x2 + pow(x2, 2);

	if (mark) mark = 1 / mark;
	return mark;
}

void Tcandidate::info()
{

	cout << "+++++ Genotype ++++++\n";
	cout << "++ gens count: " << GENS_COUNT << "\n";

	for (int i = 0; i < GENS_COUNT; i++)
	{
		cout << "++ " << genotype[i].get_name() << ": " << genotype[i].get_val() << "\n";
		cout << "\n";
		
		// wyci¹gamy z klasy candidate tablice klas Tgen i uruchamiamy funkcje info zadeklarowan¹ w Tgen.cpp Tgeh.h
    }
	cout << "++ \n";
	cout << "++ rate: " << mark << "\n";
	cout << "++++++++++++++++++++++\n";
    cout << "++ \n";
	
}

void Tcandidate::gen()
{
    int val = genotype[0].get_val();
	vector<int> bin1;
	while(val)
	{
		bin1.insert(bin1.begin(), val % 2);
		val = (val - val % 2) / 2;
	}
	cout << "zapis binarny x1 ";
	for (int i = 0; i < bin1.size(); i++)
	{

		cout << bin1[i];
	}
	cout << "\n";

	val = genotype[1].get_val();
	vector<int> bin2;
	while(val)
	{
		bin2.insert(bin2.begin(), val % 2);
		val = (val - val % 2) / 2;
	}
	cout << "zapis binarny x2 ";
	for (int i = 0; i < bin2.size(); i++)
	{

		cout << bin2[i];
	}
	cout << "\n";

}


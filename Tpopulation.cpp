#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Tpopulation.h"
#include "Tgen.h"
#include "Tcandidate.h"


using namespace std;

int Tpopulation::_id = -1;

Tpopulation::Tpopulation(unsigned int  cans_count)
{
	_id++;
	candidates_count = cans_count;
	for (unsigned int i = 0;i < cans_count;i++)
	{
		candidates.push_back({});
	}

}
void Tpopulation::calculate()
{
	double best_val;
	for (int i = 0;i < candidates_count;i++)
	{
		candidates[i].rate();
		double val = candidates[i].get_mark();
		if (i) best_val = max(best_val, val);
		else best_val = val;
	}
	this->best_val = best_val;
}
void Tpopulation::info()
{
	cout << "++++ POPULATION #" << _id << " ++++\n";
	for (int i = 0;i < candidates_count; i++)
	{   
		
		cout << "Candidate " << i << ": ";
		cout<<candidates[i].get_mark() << "\n";
	}
	cout << "++++++ \n";
}

Tcandidate Tpopulation::get_best_candidate()
{
	int i = 0;
	while (candidates[i].get_mark() != best_val)i++;
	
	return candidates[i];

}

void Tpopulation::get_rand_best_candiadtes()
{
	int suma_candidates = 0, suma_candidates2 = 0;

	for (int i = 0; i < candidates_count; i++) //tworzenie zakresu
	{
		suma_candidates += 3e-2 / candidates[i].get_mark();
		//cout<<suma_candidates<<endl;
	}

	int randomowo_candydat = rand() % suma_candidates;
	
	bool stop = 1; // warunek zatrzymania
	id_rand_ruletka = -1;
	while (stop)
	{
		id_rand_ruletka++;
		suma_candidates2 += 3e-2 / candidates[id_rand_ruletka].get_mark();
		if (randomowo_candydat <= suma_candidates2) //szukanie osobnika
		{
			cout << "wylosowany kandydat: " << id_rand_ruletka << "\n\n";
			candidates[id_rand_ruletka].info();
			candidates[id_rand_ruletka].gen();
			candidates2.push_back(candidates[id_rand_ruletka]);
			//cout << "e";
			//candidates2[0].info();
			//candidates2[0].gen();
			stop = 0;
		}

	}
	cout << "\n";
	cout << "KANDYDAT 2: ";
		cout << "\n";
	suma_candidates = 0, suma_candidates2 = 0;

	for (int i = 0; i < candidates_count; i++) //tworzenie zakresu
	{
		suma_candidates += 1e-2 / candidates[i].get_mark();
		//cout<<suma_candidates<<endl;
	}

	randomowo_candydat = rand() % suma_candidates;

	stop = 1; // warunek zatrzymania
	id_rand_ruletka = -1;
	while (stop)
	{
		id_rand_ruletka++;
		suma_candidates2 += 1e-2 / candidates[id_rand_ruletka].get_mark();
		if (randomowo_candydat <= suma_candidates2) //szukanie osobnika
		{
			cout << "wylosowany kandydat: " << id_rand_ruletka << "\n\n";
			candidates[id_rand_ruletka].info();
			candidates[id_rand_ruletka].gen();
			candidates2.push_back(candidates[id_rand_ruletka]);
			//cout << "e";
			//candidates2[0].info();
			//candidates2[0].gen();
			stop = 0;
		}

	}
	stop = 1;
	while(stop)
	{
		double suma2 = 0;
		for (int i = 0; i < candidates2_count; i++)
		{
			suma2 += candidates2[i].get_mark();

		}
		threshold = suma2 / candidates2_count * 0.75;
		

		for (int i = 0; i < candidates2_count; i++)
		{
			if (candidates2[i].get_mark() < threshold)
			{
				cout << "Kandydat" << i << "sie krzyzuje";
				cout << "\n";
			}
			else
			{
				cout << "Kandydat" << i << "sie nie krzyzuje";
				cout << "\n";
				stop = 0;
			}

		}
	}
	
	
}






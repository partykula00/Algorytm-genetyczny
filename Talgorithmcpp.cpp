#include<iostream>
#include<math.h>

#include"Talgorithm.h"

using namespace std;

Talgorithm::Talgorithm(unsigned int candidates_count, unsigned int max_population_count, unsigned int min_improvement_proc)
{

	stop_max_population_count = max_population_count;
	stop_min_improvement_proc = min_improvement_proc;

	wsk_population_pres = new Tpopulation{ candidates_count };
}

Talgorithm::~Talgorithm()
{
	delete wsk_population_pres;
	delete wsk_population_prev;
	cout << "memeory cleaned\n";

}

void Talgorithm::run()
{
	while (!wsk_population_prev || !is_stop())
	{
		wsk_population_pres->calculate();

		cout << "++ Population #" << (*wsk_population_pres).get_id() << " best result: " << (*wsk_population_pres).get_best_val() << "\n";
		
		unsigned int candidates_count = (*wsk_population_pres).get_candidates_count();

		delete wsk_population_prev;
		wsk_population_prev = wsk_population_pres;

		//tak algorytm nie dziala

		wsk_population_pres = new Tpopulation{ candidates_count };
	}
}

bool Talgorithm::is_stop()
{
	Tpopulation population = (*wsk_population_pres);

	bool bool_stop_population_max = 0;
	bool bool_stop_improvement_min = 0;

	if (!wsk_population_prev)
	{
		bool_stop_population_max = (population.get_id() == stop_max_population_count);
	}
	else
	{
		Tpopulation population_prev = (*wsk_population_prev);

		double population_val = population.get_best_val();
		double population_prev_val = population_prev.get_best_val();
		unsigned int error = fabs(population_prev_val - population_val) / population_prev_val * 100;
		bool_stop_population_max = (population.get_id() == stop_max_population_count);
		bool_stop_improvement_min = (error < stop_min_improvement_proc);

	}
	return  bool_stop_population_max || bool_stop_improvement_min;
}
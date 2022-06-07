#pragma once
#ifndef TALGORITHM_H_
#define TALGORITHM_H_

#include "Tpopulation.h"

class Talgorithm
{
	unsigned int   stop_max_population_count;
	unsigned int   stop_min_improvement_proc;

	Tpopulation* wsk_population_pres = nullptr;
	Tpopulation* wsk_population_prev = nullptr;
public:

	Talgorithm(unsigned int candidates_count = 10, unsigned int max_population_count = 20, unsigned int min_improvement_proc = 3);

	~Talgorithm();

	void run();

private:

	bool is_stop();
};
#endif /*TALGORITHM_H_*/

#pragma once
#ifndef TPOPULATION_H_
#define TPOPULATION_H_

#include "Tcandidate.h"
#include <vector>

class Tpopulation
{
	static int _id;
	int candidates_count;
	int candidates2_count = 2;
	std::vector <Tcandidate> candidates;
	std::vector <Tcandidate> candidates2;
	double best_val = 0;
	double threshold;
	double id_rand_ruletka;

public:
	Tpopulation(unsigned int cans_count = 0);
	void calculate();
	void type();
	void get_rand_best_candiadtes();
	void krzyzowanie();
	Tcandidate get_best_candidate();
	unsigned int get_id() { return _id;}
	unsigned int get_candidates_count() { return candidates_count; }
	double get_best_val() { return best_val; }
	void info();
	

private:


};
#endif /*TPOPULATION_H_*/


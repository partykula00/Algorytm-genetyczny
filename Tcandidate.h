#pragma once
#ifndef TCANDIDATE_H_
#define TCANDIDATE_H_

#include "Tgen.h"

#define GENS_COUNT 2

class Tcandidate
{
	
	Tgen genotype[GENS_COUNT] =
	{
		Tgen("x1",0, 100, 1),
		Tgen("x2",0, 40, 1)
	};
	
	double mark;

public:
	Tcandidate();
	double get_mark() { return mark; };
	
	int rate();

	void info();
	void info2();
	void gen();

private:

	void rand_gens_val();
};

#endif /*TCANDIDATE_H_*/

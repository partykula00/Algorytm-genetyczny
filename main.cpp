#include <iostream>
#include "Tgen.h"
#include "Tcandidate.h"
#include "Tpopulation.h"
#include "Talgorithm.h"

using namespace std;

int main()
{
	Tcandidate can1{};
	//can1.rate();
	//can1.info();
	Tcandidate can2{};
	//can2.rate();
	//can2.info();
	Tcandidate can3{};
	Tcandidate bestcan{};
    Tpopulation pop{ 4 };
	cout << "Zaraz po utworzeniu " << "\n";
	pop.info();
	cout << "\n";

	pop.calculate();
	cout << "Po wykonaniu obliczen \n";
	pop.info();
	cout << "\n";

	pop.get_rand_best_candiadtes();

	



	//  
	/*
	Talgorithm task{ 5 };

	task.run();

	
	*/


	
}
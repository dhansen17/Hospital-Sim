#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <ctime>

//This will create a random numbers
class Random {

public:

	//Initializes random numbers using time
	Random() 
	{
		srand((unsigned int)std::time(0));
	}

	
	Random(int number)
	{
		srand(number);
	}


	int next_int(int n) 
	{
		return int(next_double() * n);
	}

	double next_double() 
	{
		return double(rand()) / RAND_MAX;
	}

};

#endif
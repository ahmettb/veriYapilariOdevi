#ifndef Radix_hpp
#define Radix_hpp

#include "Queue.hpp"
#include <cmath>

class Radix{
	private:	
		int* numbers;
		int length;
		queue1**queues;
		int maxStep;
		int power(int e);
		int MaxStepNumber();
		int StepCount(int);
		int* QueueCurrentLengths();
	public:
		Radix(int*, int);
		int* Sort();
		~Radix();
};
#endif
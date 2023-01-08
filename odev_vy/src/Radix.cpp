/** 
* @file Radix.cpp
* @description  Parametre olarak verilen diziyi radix ve kuyruk veri yapısıyla birlikte küçükten büyüğe sıralama.
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/


#include "Radix.hpp"
#include "Queue.hpp"
#include <math.h>
#include <stdio.h>

int Radix::MaxStepNumber(){
	int max=0;
	for(int i=0;i<length;i++){
		if(StepCount(numbers[i])>max) max = StepCount(numbers[i]);
	}
	return max;
}
int Radix::StepCount(int number){
	number = abs(number);
	int basamak=0;
	while(number>0){
		basamak++;
		number /= 10;
	}
	return basamak;
}
Radix::Radix(int *numbers, int length){
	this->numbers = new int[length];
	this->length = length;
	for(int i=0;i<length;i++){ this->numbers[i] = numbers[i]; }
	queues = new queue1*[10];
	for(int j=0;j<10;j++){ queues[j] = new queue1(); }
	maxStep = MaxStepNumber();
}
int* Radix::QueueCurrentLengths(){
	int *lengths = new int[10];
	for(int i=0;i<10;i++){
		lengths[i] = queues[i]->count();
	}
	return lengths;
}
int Radix::power(int e){
	int result=1;
	for(int i=0;i<e;i++) result *= 10;
	return result;
}
int* Radix::Sort(){
	int numberIndex=0;
	// read from array once and add to queues
	for(;numberIndex<length;numberIndex++){
		int stepValue = numbers[numberIndex]%10;
		int num = numbers[numberIndex];
		queues[stepValue]->enqueue(num);
	}
		
	//i starting from 1 because of first digit processed
	for(int i=1;i<maxStep;i++){
		//get the current length in all queues
		int *qlengths = QueueCurrentLengths();
		for(int index=0;index<10;index++){
			int len=qlengths[index];
			for(;len>0;len--){
				int number = queues[index]->peek();
				queues[index]->dequeue();
				int stepValue = (number/power(i))%10;			
				queues[stepValue]->enqueue(number);				
			}
		}
		delete [] qlengths;
	}
	int* ordered = new int[length];
	numberIndex=0;
	for(int index=0;index<10;index++){
		while(!queues[index]->isEmpty()){
			int number = queues[index]->peek();
			ordered[numberIndex++] = number;
			queues[index]->dequeue();
		}
	}
		
	return ordered;
}
Radix::~Radix(){	
	delete [] numbers;
	for(int i=0;i<10;i++) delete queues[i];
	delete [] queues;
}
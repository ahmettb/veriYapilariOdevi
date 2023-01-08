

#ifndef Queue_hpp
#define Queue_hpp
#include <iostream>
using namespace std;
class queue1{
	public:
		int front;
		int back;
		int capacity;
		int length;
		int *items;
		void reserve(int newCapacity);
		queue1();
		void clear();
		int count()const;
		bool isEmpty()const; 
		/// Kuyrukta en öndeki elemanı getirir
		int peek();
		void enqueue(int item);
		void dequeue();
		~queue1();
			
	
};
#endif

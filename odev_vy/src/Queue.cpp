/** 
* @file Queue.cpp
* @description Kuyruk veri yapısı kullanılarak bir dizideki elemanları küçükten büyüğe radix sınıfı yardımıyla sıralama.
* @course Dersi 1.Öğretim A Grubu
* @assignment 2
* @date 20.12.2022
* @author AHMET BOZTEMUR ahmet.boztemur@sakarya.edu.tr
*/


#include "Queue.hpp"
#include "Queue.hpp"

	void queue1::reserve(int newCapacity){
			int *temp = new int[newCapacity];
			for(int i=front,j=0;j<length; j++){
				temp[j] = items[i]; 
				i = (i + 1) % capacity;
			}
			capacity = newCapacity;
			delete[] items;
			items = temp;
			front = 0;
			back = length - 1;
		}



        	queue1::queue1(){
			capacity=1;
			front=0;
			back=-1;
			length=0;			
			items=new int[capacity];
		}
		void queue1:: clear(){			
			front=0;
			back=-1;
			length=0;
		}
		int queue1:: count() const{
			return length;
		}
		bool queue1::isEmpty() const {
			if(length == 0) return true;
			return false;
		}


		int queue1:: peek(){
			if(isEmpty()) throw "Empty List";
			return items[front];
		}

		void queue1::enqueue(int item){
			if(length == capacity) reserve(2*capacity);
			back = (back + 1) % capacity;
			items[back] = item;
			length++;
		}


		void queue1:: dequeue(){
			if(isEmpty()) throw "Empty List";			
			front = (front + 1) % capacity;
			length--;
		}


queue1::		~queue1(){
			delete[] items;
		}
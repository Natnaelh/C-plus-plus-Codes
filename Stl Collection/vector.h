#ifndef _Myvector_h
#define _Myvector_h
#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;

template <typename Elemtype>
class Myvector{

	public:
		Myvector();
		~Myvector();
		int size();
		void pushback(Elemtype s);
		Elemtype popback();
		Elemtype getAt(int i);
		int capacity();
		void clear();
		bool empty();
		Elemtype front();
		Elemtype back();
		void setAt(int index , Elemtype e);
		void insertAt(int index, Elemtype e);
		void removeAt(int index);

	private:
		Elemtype *arr;
		int numUsed  , numsAllocated;
		void doubleCapacity();
		void shrinkCapacity();

};

template <typename Elemtype>
Myvector<Elemtype>::Myvector(){
	arr = new Elemtype[10];
	numsAllocated = 10;	
	numUsed = 0;
}
template <typename Elemtype>
Myvector<Elemtype>::~Myvector(){
	delete[] arr;
}
template <typename Elemtype>
int Myvector<Elemtype>::size(){
	return numUsed;
}

template <typename Elemtype>
void Myvector<Elemtype>::pushback(Elemtype s){
	if(numUsed == capacity())
		doubleCapacity();
	arr[numUsed++] = s;
}
template <typename Elemtype>
Elemtype Myvector<Elemtype>::popback(){
	/*if (empty()) {cerr<<"Vector empty!"<<endl;}
	else{*/
	Elemtype elem = getAt(size()-1);
	removeAt(size()-1);

	// if(numUsed < (capacity()/3))
	// 	shrinkCapacity();
	return elem;
			// }
}

template<typename Elemtype>
int Myvector<Elemtype>::capacity(){
	return numsAllocated;
}

template<typename Elemtype>
void Myvector<Elemtype>::clear(){
	Elemtype *emptyarr = new Elemtype[0];
	delete[] arr;
	arr = emptyarr;
}

template<typename Elemtype>
bool Myvector<Elemtype>::empty(){
	return numUsed == 0;
}

template <typename Elemtype>
Elemtype Myvector<Elemtype>::getAt(int i){
	if (i < 0 || i >= numUsed){
		cerr<< "Index reached out of bound "<<endl;
		exit(-1);
	}
	else{ 
		return arr[i]; 
	}
}
template <typename Elemtype>
void Myvector<Elemtype>::doubleCapacity(){
	Elemtype *doubled = new Elemtype[numsAllocated*2];
	for(int i = 0 ; i < numUsed; i ++){
		doubled[i] = arr[i];
	}
	delete[] arr;

	arr = doubled;
	numsAllocated *= 2;
}
template<typename Elemtype>
Elemtype Myvector<Elemtype>::front(){
	return getAt(0);
}
template<typename Elemtype>
Elemtype Myvector<Elemtype>::back(){
	return getAt(size()-1);
}
template<typename Elemtype>
void Myvector<Elemtype>::setAt(int index , Elemtype e){
	if (index < 0 || index >= size())
		cerr<<"Out of bounds";
		exit(-1);
	arr[index] = e;
}

template<typename Elemtype>
void Myvector<Elemtype>::insertAt(int index , Elemtype e){
	if (index < 0 || index >= size())
		cerr<<"index Out of bounds"<<endl;
		exit(-1);
	if (numUsed == numsAllocated)
		doubleCapacity();
	for (int i = size(); i >= index; i--){
		arr[i+1] = arr[i];
	}
	arr[index] = e;
	numUsed++;
}

template<typename Elemtype>
void Myvector<Elemtype>::removeAt(int index){
	if (index < 0 || index >= size()){
		cerr<<"index Out of bounds"<<endl;
		exit(-1);
	}
	else{
	for (int j = index; j< numUsed ; j++)
		arr[j] = arr[j+1];
	numUsed--; }

}

/*template <typename Elemtype>
void Myvector<Elemtype>::shrinkCapacity(){
	Elemtype *shrinked = new Elemtype[numsAllocated/2];
	for (int i = 0 ; i < numUsed; i++)
		shrinked[i] = arr[i];
	delete[] arr;
	arr = shrinked;
	numsAllocated /= 2;
}*/
#endif





#ifndef _Mystack_h
#define _Mystack_h

#include<iostream>
#include"vector.h"

using namespace std;

template <typename Elemtype>
class Mystack{
public:
	Mystack();
	~Mystack();
	int size();
	void push(Elemtype e);
	Elemtype pop();

private:
	Myvector<Elemtype> elemts;
};

template <typename Elemtype>
Mystack<Elemtype>::Mystack(){
}

template<typename Elemtype>
Mystack<Elemtype>::~Mystack(){

}

template<typename Elemtype>
int Mystack<Elemtype>::size(){
	return elemts.size();

}

template<typename Elemtype>
void Mystack<Elemtype>::push(Elemtype e){
	elemts.pushback(e);

}

template<typename Elemtype>
Elemtype Mystack<Elemtype>::pop(){
	if (size()==0){
		cerr<<"Stack Empty "<<endl;
	}
	else{
	Elemtype elem = elemts.getAt(elemts.size()-1);
	elemts.removeAt(elemts.size()-1);
	return elem;
}


}











#endif 
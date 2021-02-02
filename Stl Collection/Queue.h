#include <iostream>
#ifndef _Myqueue_h
#define _Myqueue_h
using namespace std;

template <typename ElemType>
class Myqueue{
public:
	Myqueue();
	~Myqueue();

	bool isEmpty();
	void Enqueue(ElemType e);
	ElemType Dequeue();

private:
	struct cellT
	{
		ElemType value;
		struct cellT *next;
	};

	cellT *head , *tail;
};

#endif

template<typename ElemType>
Myqueue<ElemType>::Myqueue(){
	head , tail = NULL;
}
template<typename ElemType>
Myqueue<ElemType>::~Myqueue(){
	//code to delete all cells
}
template<typename ElemType>
bool Myqueue<ElemType>::isEmpty(){
	return (head == NULL);
}
template<typename ElemType>
void Myqueue<ElemType>::Enqueue(ElemType e){
	cellT *newCell = new cellT;
	newCell -> value = e;
	newCell -> next = NULL;
	if(isEmpty()){
		head , tail = newCell;
	}
	else{
		tail -> next = newCell;
		tail = newCell;
	}
}

template<typename ElemType>
ElemType Myqueue<ElemType>::Dequeue(){
	if(isEmpty()){
		cerr<<"Queue is Empty "<<endl;
	}
	else{
		ElemType front = head -> value;
		cellT *old = head;
		head = head -> next;
		delete old;
		return front;
}

}
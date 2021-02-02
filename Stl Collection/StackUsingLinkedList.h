#include <iostream>
#ifndef _mystack_h
#define _mystack_h
using namespace std;
template <typename ElemType>


class Mystack{

public:
	Mystack();
	~Mystack();

	bool isEmpty();
	void push(ElemType e);
	ElemType pop();

private:
	struct Node
	{
		ElemType value;
		struct Node *next;
		
	};
	Node *head ;
};

#endif

template<typename ElemType>
Mystack<ElemType>::Mystack(){
	head = NULL;
}

template<typename ElemType>
Mystack<ElemType>::~Mystack(){
	//delete entire node
}

template<typename ElemType>
bool Mystack<ElemType>::isEmpty(){
	return (head == NULL);
}

template <typename ElemType>
void Mystack<ElemType>::push(ElemType e){
	Node *newNode = new Node;
	newNode->value = e;
	newNode->next = head;
	head = newNode;

}

template<typename ElemType>
ElemType Mystack<ElemType>::pop(){
	if (isEmpty()){
		cerr<<"Stack is Empty! "<<endl;
	}
	else{ 
	ElemType top = head->value;
	Node *old = head;
	head = head -> next;
	delete old;
	return top;


}

}




















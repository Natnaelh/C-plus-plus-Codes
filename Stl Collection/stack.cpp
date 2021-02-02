#include <iostream>
#include "StackUsingLinkedList.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Mystack<int> mystack;
	mystack.push(5);
	mystack.push(0);
	mystack.push(40);
	mystack.push(9);
	while(!(mystack.isEmpty())){
		cout<<mystack.pop()<<" ";
	}
	return 0; 
}
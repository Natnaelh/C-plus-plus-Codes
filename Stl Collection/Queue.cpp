#include <iostream>
#include"Queue.h"

using namespace std;


int main (){
	Myqueue<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(5);
	while(!(q.isEmpty())){
		cout << q.Dequeue()<<" ";
	}

	return 0;
}
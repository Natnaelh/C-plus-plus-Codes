#include <iostream>
#include <string>
using namespace std;

struct ListNode{

	int data;
	struct ListNode *next;

};

ListNode *head = NULL;

void pushFront(int newData){
	ListNode *newNode = new ListNode;
	newNode-> data = newData;
	newNode->next = head;
	head = newNode;
}

void displayList(){
	ListNode *ptr = head;
	while(ptr != NULL){
		cout << ptr -> data<<endl;
		ptr = ptr->next;
	}
}

void insertSorted(int item){
	ListNode  *newNode = new ListNode;
	ListNode *prev = NULL;
	ListNode *ptr = head;
	newNode->data = item;							-
	while(ptr != NULL && ptr->data < item){
		prev = ptr;
		ptr = ptr -> next;
	}
	newNode->next = ptr;
	if (prev == NULL){
		head = newNode;
	}
	else{
		prev->next = newNode;
		
	}
}

int size(){
	ListNode *ptr = head;
	int count = 0;
	while(ptr != NULL){
		count += 1;
		ptr = ptr-> next;
	}	
	return count;
}

void remove(int item){
	ListNode *ptr = head;
	ListNode *prev = NULL;
	if (head == NULL) return;
	if (head->data == item){
		ptr = head->next;
		delete head;
		head = ptr;
	}
	else{
		ptr = head;
		while(ptr != NULL && ptr->data != item){
			prev = ptr;
			ptr = ptr -> next;
		}
		prev->next = ptr->next;
		

	}
}

int front(){
	return head -> data;
}

int back(){
	ListNode *ptr = head;
	ListNode *prev = NULL;
	while(ptr != NULL){
		prev = ptr;
		ptr= ptr -> next;
	}
	return prev->data;
}


void pushBack(int item){
	ListNode *newNode = new ListNode;
	newNode->data = item;
	ListNode *ptr = head;
	ListNode *prev = NULL;
	while(ptr != NULL){
		prev = ptr;
		ptr= ptr -> next;
	}
	newNode->next = ptr;
	prev->next = newNode;
}

// void 

void clear(){
	ListNode *ptr = head;
	ListNode *prev = NULL;
	while (ptr != NULL){
		prev = ptr;
		delete ptr;
		ptr = NULL;
		ptr = prev -> next;
	}
}


int main(){
	pushFront(3);
	pushFront(8);
	pushFront(10);
	pushFront(1);
	pushBack(15);
	pushFront(5);
	displayList();
	pushBack(-2);
	pushBack(6);
	remove(5);
	cout<<endl;
	displayList();
	cout<<"First item: "<<front()<<endl;
	cout<<"Last item: "<<back()<<endl;
	cout<<"Total items it List: "<<size()<<endl;
	cout<<endl;
	cout<<endl;
	clear();
	displayList();
		


	// return 0;
}
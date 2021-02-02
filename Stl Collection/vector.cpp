#include <iostream>
#include <string>
#include "vector.h"


using namespace std;



int main(){

	Myvector<int> vec;
	for (int j = 0 ; j < 20 ; j++)
		vec.pushback(j);
/*	cout<<vec.capacity()<<endl;
	cout<<vec.size()<<endl;
	cout<<vec.getAt(5)<<endl;*/
	for (int i = 0 ; i < vec.size() ; i++)
		cout<<vec.getAt(i)<<" ";
	cout <<"size: "<<vec.size()<<endl;
	cout<<endl;
	for (int i = 0 ; i < 15 ; i++)
		cout<<vec.popback()<<" ";
	cout <<"size: "<<vec.size()<<endl;
	cout << endl;
/*	cout<<vec.capacity()<<endl;	
	cout<<vec.size()<<endl;*/
	// cout<<vec.getAt(4)<<endl;
	// vec.clear();
/*	cout<<vec.size()<<endl;
	cout << vec.empty()<<endl;*/
	// cout<<vec.getAt(2)<<endl;
	// return 0;
	/*for (int i = 0 ; i <= vec.size(); i ++)
		cout<<vec.getAt(i)<<" ";*/
	vec.setAt(2,50);
	for (int i = 0 ; i < vec.size(); i ++)
		cout<<vec.getAt(i)<<" ";
	cout <<endl;
	vec.insertAt(0,20);
	for (int i = 0 ; i < vec.size(); i ++)
		cout<<vec.getAt(i)<<" ";
	cout <<"size: "<<vec.size()<<endl;
	cout << "front: "<< vec.front() << " Back: " << vec.back()<<endl;
	cout <<endl;
	vec.removeAt(0);
	cout <<"size: "<<vec.size()<<endl;
	cout << "front: "<< vec.front() << " Back: " << vec.back()<<endl;
	for (int i = 0 ; i < vec.size(); i++)
		cout<<vec.getAt(i)<<" ";
}


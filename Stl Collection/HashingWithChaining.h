#ifndef _mymap_h
#define _mymap_h
#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename valtype>

class mymap
{
public:
	mymap();
	~mymap();
	void addValue(string key , valtype value);
	valtype getValue(string key);
	
private:
	static const int NumofBuckets = 99;
	struct cellT
	{
		string key;
		valtype value;
		cellT *next;
		
	};

	cellT *Buckets[NumofBuckets];
	int MapStringToInt(string key, int NumofBuckets);
	cellT *findCell(string key, cellT *head);
};

#endif



template<typename valtype>
mymap<valtype>::mymap(){
	for(int i = 0 ; i < NumofBuckets ; i++){
		Buckets[i] = NULL;
	}

} 

template<typename valtype>
mymap<valtype>::~mymap(){
 //code to delete all data
}


template<typename valtype>
void mymap<valtype>::addValue(string key , valtype val){

	int index = MapStringToInt(key, NumofBuckets);
	cellT *found = findCell(key , Buckets[index]);
	
	if (found != NULL){
		found -> value = val;
	}
	else{
		cellT *newCell = new cellT;
		newCell-> key = key;
		newCell-> value = val;
		newCell -> next = Buckets[index];
		Buckets[index] = newCell;

	}

}


template<typename valtype>
valtype mymap<valtype>::getValue(string key){
	int index = MapStringToInt(key, NumofBuckets);
	cout<<key<<": "<<index<<endl;
	cellT *found = findCell(key , Buckets[index]);
	if(found != NULL){ 
		return found->value; 
					}
	else  {
		cerr<<"Key not found "<<endl;
		exit(-1);
	}

}

const int multiplier = -1664117991L;
template<typename valtype>
int mymap<valtype>::MapStringToInt(string key, int NumofBuckets){
	int hashed = 0;
	for (int i = 0 ; i < key.length() ;i++){
		hashed = hashed * multiplier + key[i];
	}

	return (hashed % NumofBuckets);
}

template<typename valtype>
typename mymap<valtype>::cellT *mymap<valtype>::findCell(string key , cellT *head){
	for(cellT *cell = head ; cell != NULL ; cell = cell->next){
		if(cell->key == key) return cell;	
	}
	return NULL;

}
#ifndef _Map_h
#define _Map_h
#include <string>
#include "vector.h"
using namespace std;

template <typename Valtype>
class Map
{
public:
	Map();
	~Map();
	Valtype getValue(string key);
	void add(string key, Valtype value);
	
private:
	struct pairT
	{
		string key;
		Valtype value;
	};
	Myvector<pairT> entries;
	int FindIndexOfKey(string key);
};

#endif

template <typename Valtype>
Map<Valtype>::Map(){

}

template<typename Valtype>
Map<Valtype>::~Map(){

}

template<typename Valtype>
void Map<Valtype>::add(string k , Valtype val){
	pairT  p;
	int found = FindIndexOfKey(k);
	if (found != -1)
		
		p.key = k;
		p.value = val;
		entries.setAt(found-1,p);
	
	
	entries.pushback(p);
}
	



template<typename Valtype>
Valtype Map<Valtype>::getValue(string key){
	int found = FindIndexOfKey(key);
	if (found != -1){
		return entries.getAt(found-1).value;
	}
	else{
		std::cerr<<"Key not found "<<endl;
	}

}


template <typename Valtype>
int Map<Valtype>::FindIndexOfKey(string k){
	
	for (int i = 0; i < entries.size(); i++)
		if(entries.getAt(i).key == k) return i;
	return -1;
}
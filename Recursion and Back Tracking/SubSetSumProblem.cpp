#include <iostream>
#include<set>
#include <string>

using namespace std;

bool SubsetSumExists(set<int>& myset , int target);

int main(){
	set<int> myset;
	myset.insert(10);
	myset.insert(1);
	myset.insert(-1);
	myset.insert(2);
	myset.insert(7);
	myset.insert(12);
	myset.insert(-5);

	int target = 9;

	cout<<SubsetSumExists(myset , target);
}



bool SubsetSumExists(set<int>& myset , int target){
	if (myset.empty()){
		return target == 0;
	}
	else{
		int element = myset.first();
		set<int> rest = myset - element;
		return SubsetSumExists(rest , target)|| SubsetSumExists(rest, target-element);

	}
}


#include <iostream>
#include<vector>

using namespace std;


void QuickSort(vector<int> & vec,int start, int end);
int Partition(vector<int> &vec , int start, int end);


void QuickSort(vector<int> &vec , int start , int end){
	if(start >= end){
		return;
	}

	int boundary = Partition(vec,start,end);
	QuickSort(vec,start,boundary-1);
	QuickSort(vec,boundary+1,end);


}


int Partition(vector<int> & vec , int start, int end){
	int pivot = vec[start];
	int lh = start+1;
	int rh = end;
	while(true){
		while(lh < rh && vec[lh] < pivot) lh++;
		while(rh > lh && vec[rh] > pivot) rh--;
		if(lh == rh) break;
		int temp = vec[rh];
		vec[rh] = vec[lh];
		vec[lh] = temp;
	}
	if (vec[rh] >= pivot) return start;
	vec[start] = vec[rh];
	vec[rh] = pivot;
	return rh;
}


int main(){

	vector<int> myvec ;
	myvec.push_back(45);
	myvec.push_back(35);
	myvec.push_back(25);
	myvec.push_back(15);
	myvec.push_back(5);
	myvec.push_back(55);
	myvec.push_back(75);
	QuickSort(myvec, 0, myvec.size()-1);
	// cout<<"[";
	//for (int i = 0 ; i < resultvec.size()-1; i++){
	//	cout<<resultvec[i];
	//}
	//cout<<resultvec[resultvec.size()]

}
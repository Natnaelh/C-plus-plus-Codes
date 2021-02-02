#include<iostream>
#include <vector>

using namespace std;


vector<int> InsertionSort(vector<int> &);


vector<int> InsertionSort(vector<int> &vec){

	for (int j = 1; j < vec.size(); j++){
		int key = vec[j];
		int i = j-1;
		while(i >= 0 && key < vec[i]){
			vec[i+1] = vec[i];
			i -= 1;
		}
		vec[i+1] = key;
	}
	return vec;
}

int main(){ 
vector<int> myvec;
myvec.push_back(40);
myvec.push_back(17);
myvec.push_back(8);
myvec.push_back(-5);
myvec.push_back(100);
InsertionSort(myvec);

for (vector<int>::iterator iter = myvec.begin();iter != myvec.end();iter++){
	cout<<*iter<<", ";
}
cout<<endl;
}
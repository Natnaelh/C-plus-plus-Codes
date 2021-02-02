#include <iostream>
#include <vector>
using namespace std;

vector<int> MergeSort(vector<int> & vec);
vector<int> Merge(vector<int> & vec, vector<int>& left, vector<int> & right);

vector<int>  MergeSort(vector<int> & vec){
	int n = vec.size();
	if (n <= 1)
		return vec;
	vector<int> left;
	vector<int> right;
	for(int i = 0; i < n;i++){
		if (i < n/2)
			left.push_back(vec[i]);
		else
			right.push_back(vec[i]);
	}
	MergeSort(left);
	MergeSort(right);
	vec.clear();
	return Merge(vec,left,right);

}

vector<int> Merge(vector<int> & vec, vector<int>& left, vector<int> & right){
	int l = left.size();
	int r = right.size();
	int i = 0;
	int j = 0;

	while(i < l && j < r){
		if(left[i] <= right[j]){
			vec.push_back(left[i]);
			i++;
		}
		else{
			vec.push_back(right[j]);
			j++;
		}
	}

	while(i < l){
		vec.push_back(left[i]);
		i++;
	}	
	while(j < r){
		vec.push_back(right[j]);
		j++;
	}	
	return vec;

}

int main(){

	vector<int> myvec;
	myvec.push_back(5);
	myvec.push_back(4);
	myvec.push_back(3);
	myvec.push_back(2);
	myvec.push_back(1);
	vector<int> sorted = MergeSort(myvec);
	cout<<"[";
	for (int i = 0; i < sorted.size()-1;i++){
		cout<<sorted[i]<<",";
	}
	cout<<sorted[sorted.size()-1];
	cout<<"]"<<endl;
}
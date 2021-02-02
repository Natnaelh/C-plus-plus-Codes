#include<iostream>
#include<vector>
#include<string>

using namespace std;


vector<int> selectionSort(vector<int>& vec);


int main(){

	vector<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	vector<int> sorted = selectionSort(vec);
	vector<int>::iterator iter;
	for (iter = sorted.begin();iter != sorted.end();iter++){
		cout<<*iter<<", ";
	}

}


vector<int> selectionSort(vector<int>& vec){
		int n = vec.size();
		for(int i = 0; i < n;i++){
			int traceSmallest = i;
			for (int j = i+1; j < n;j++){
				if (vec[j] < vec[traceSmallest])
					traceSmallest = j;
			}
			int temp = vec[traceSmallest];
			vec[traceSmallest] = vec[i];
			vec[i] = temp;

		}
		return vec;

}
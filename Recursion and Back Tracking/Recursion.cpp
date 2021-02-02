#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fact(n);
int fibonacci(int n);
int additiveSequence(int n, int t0, int t1);
int Inefficientfib(n);
bool IsPalindrome(string str);
bool EfficientPal(string str);
bool palHelper(string str, int first, int last);
int findInSortedVector(string key, vector<string>& vec);
int binarySearch(string key, vector<string>& vec,int p0 , int p1);


int main(){
	cout<<"Fib of 5 " << fibonacci(5)<<endl; 
	return 0;
}


int fibonacci(int n){
	return additiveSequence(n, 0, 1);
}


int additiveSequence(int n, int tzero, int tone){
	if (n == 0) return tzero;
	if (n == 1) return tone;
	return additiveSequence(n-1, tone , tzero + tone);
}



int Inefficientfib(int n){
	if (n == 0):
		return 0;
	if (n == 1)
		return 1;
	return Inefficientfib(n-1) + Inefficientfib(n-2);
}


int fact(n){
	if (n == 0){
		return 1;
	}
	else{
		return n * fact(n-1);
	}
}



bool IsPalindrome(string pal){
	len = pal.length();
	if (len == 1){
	 return true;
	}
	else{
		return (pal[0] == pal[len-1]) && IsPalindrome(pal.substring(1,len-2));
	}
}



bool EfficientPal(string str){
	len  = str.length();
	return palHelper(str,  0 , len)
}

bool palHelper(string str, int first , int last){
	if (first >= last) return true;
	else
		return (str[first] == str[last]) && palHelper(str , first+1, last - 1);
}

int findInSortedVector(string key, vector<int>& vec){
	vecsize = vec.size();
	return binarySearch(key, vec , 0 , vecsize -1);
}

int binarySearch(string key, vector<string>& sequence,int p0 , int p1){
	if (p0 >= p1){
		return -1;
	}
	else{
		mid = (po + p1)/2;
		if (key == vec[mid]){
			return mid;
		}
		if (key < vec[mid]){

			return binarySearch(key, vec , p0 , mid - 1);
		}
		else{
		 binarySearch(key, vec, mid + 1, p1);
	}

}




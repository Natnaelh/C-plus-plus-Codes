#include <iostream>

using namespace std;


int fact(int n);
int combination(int n , int k);

int main (){
	int n , k;
	cout << "This program calculates the mathematical function C(n,k,) " << endl;
	cout << "Enter n ";
	cin >> n;
	cout << "Enter k ";
	cin >> k ;
	cout << "C(n,k) = " << combination(n, k)<<endl;
	return 0;

}

int combination(int n , int k ){
	return fact(n) / (fact(n-k) * fact(k));

}

int fact (int n ){
	int i = 1 ; 
	int result = 1;
	for (i ; i <= n ; i++){
		result *= i;
	}

	return result;
}
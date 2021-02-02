#include <iostream>
using namespace std;

int euclidGcd(int x, int y);
int main(){
	int x, y;
	cout << "This calculates the GCD "<< endl;
	cout << "Enter first number " ;
	cin >> x;
	cout << "Enter second number " ;
	cin >> y;
	cout << "GCD of "<< x << " and " << y << " = " << euclidGcd(x,y)<<endl;
    
    return 0;
}


int euclidGcd(int x, int y){
	int r = x % y;
	while (r != 0){ 
		
		x = y;
		y = r;
		r = x % y;
	 }

	 return y;
}


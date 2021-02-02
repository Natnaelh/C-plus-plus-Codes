#include <iostream>
#include <string>

using namespace std;

void moveTower(int n, char start , char finish, char temp);
string movingAsingleTower(char star, char finish);


int main(){
	int n;
	char start = 'A' ; 
	char finish = 'B';
	char temp = 'C';
	cout <<"Enter disk size: "<<endl;
	cin >> n;
	moveTower(n, start, finish , temp);
}


void moveTower(int n , char start, char finish , char temp){
	if(n == 1){
		movingAsingleTower(start, finish);
	}
	else{
		moveTower(n-1, start, temp, finish);
		movingAsingleTower(start , finish );
		moveTower(n-1 , temp , finish , start);
	}
}

string movingAsingleTower(char start, char finish){
	cout<<start<<" ---> "<<finish<<endl; 
}
#include <iostream>
#include <string>

using namespace std;

void listPermutations(const string& str, const string& chosen);

int main(){

	string str ;
	cout << "Enter a string to permute: "<<endl;
	cin >> str;

	string chosen = "";
	listPermutations(str, chosen);
}

void listPermutations(const string& str, const string& chosen){
	if(str == ""){
		cout<<chosen<< " ";
	}
	else{
		for(int i = 0; i < str.size();i++){
			char ch  = str[i];
			string remaining = str.substr(0,i) + str.substr(i+1);
			listPermutations(remaining , chosen + ch);
		}


	}
}



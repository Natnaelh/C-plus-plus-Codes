#include<iostream>
#include<fstream>
#include<string>
#include<cstring>


using namespace std;

string promptuserforfile(ifstream & infile, string prompt = " ");

int main(){
	ifstream infile;
	ofstream  outfile;
	promptuserforfile(infile , "input filename: ");
	string line;
	while (getline(infile, line)){
		cout<< line<<endl;
	}

	infile.close();
	return 0;
	
}


string promptuserforfile(ifstream & infile, string prompt){
	while (true){
		cout << prompt;
		string filename;
		getline(cin, filename);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		infile.clear();
		cout<<"Unable to open that file, try again :( "<<endl;
		/*if (prompt == ""){
			prompt == "input filename";
		}*/
	}

}









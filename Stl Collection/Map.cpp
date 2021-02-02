#include <iostream>
// #include"Map.h"
#include "HashingWithChaining.h"
using namespace std;

int main(int argc, char const *argv[])
{
	mymap<int> mapme;
	mapme.addValue("carrara", 5);
	mapme.addValue("cat", 1);
	cout<< mapme.getValue("carrara")<<endl;
	cout<< mapme.getValue("cat")<<endl;

}


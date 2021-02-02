#include <iostream>

using namespace std;

int divisorsSum(int num);

int main ()
{
	int number = 1;
	int found = 0;
	cout << "This program returns first 4 perfect numbers"<<endl;
	while (found < 4)
	{
		if (divisorsSum(number) == number)
		{
			cout << number << endl;
			found ++;
		}
		number ++;
	}

	return 0;
}


int divisorsSum(int num)
{
	int sum = 0;
	for (int i = 1 ; i < num; i++)
	{
		if ((num % i) == 0 )
		{
			sum += i;
		}
	}
	return sum;
}
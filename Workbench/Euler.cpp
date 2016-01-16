#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isPrime(int);

int main()
{
	unsigned long long int num = 0;
	char a;
	fstream myfile;
	myfile.open("C:\\Wusers\\Andre\\Desktop\\hooah.txt");

	while (!myfile.eof())
	{
		do
		{
			myfile >> a;
		} while (a == '\n');

		num += (int)a - (int)'0';

		cout << num << endl;
		system("pause");
	}

	cout << "Number is " << num << endl;
	myfile.close();
	system("pause");
	return 0;
}

bool isPrime(int x)
{
	if (x == 1)
		return false;
	for (int i = 2; i*i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}
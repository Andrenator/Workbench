#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int max(int, int);

int main()
{
	ifstream myfile;
	int myarray[100][100] = { 0 };
	int i;
	myfile.open("H:\\euler.txt");
	for (i = 0; !myfile.eof(); i++)
	{
		for (int counter2 = 0; counter2 <= i; counter2++)
		{
			myfile >> myarray[counter2][i];
		}
	}

	for (i--; i >= 0; i--)
	{
		for (int counter2 = 0; counter2 <= i; counter2++)
		{
			myarray[counter2][i] += max(myarray[counter2][i + 1], myarray[counter2 + 1][i + 1]);
		}
	}

	cout << myarray[0][0] << endl;

	getchar();
	myfile.close();
	return 0;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
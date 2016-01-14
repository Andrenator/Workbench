#include <iostream>
using namespace std;

int main()
{
	int myarray[300] = { 0 };
	myarray[299] = 1;
	int result = 0;

	for (int i = 1; i <= 100; i++)
	{
		for (int counter = 0; counter < 300; counter++)
			myarray[counter] *= i;
		for (int counter = 299; counter > 0; counter--)
		{
			myarray[counter - 1] += myarray[counter] / 10;
			myarray[counter] %= 10;
		}
	}

	for (int i = 0; i < 300; i++)
		result += myarray[i];
	cout << result << endl;

	return 0;
}
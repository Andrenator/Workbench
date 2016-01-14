#include <iostream>
using namespace std;

int intpow(int, int);

int main()
{
	unsigned int counter = 0;
	int myarray[6];
	for (unsigned int x = 2; x <= 354294; x++)
	{
		for (int i = 0; i < 6; i++)
			myarray[i] = 0;
		myarray[5] = x;
		for (int i = 5; i > 0; i--)
		{
			if (myarray[i] > 9)
			{
				myarray[i - 1] = myarray[i] / 10;
				myarray[i] %= 10;
			}
		}
		if (intpow(myarray[0], 5) + intpow(myarray[1], 5) + intpow(myarray[2], 5) + intpow(myarray[3], 5) + intpow(myarray[4], 5) + intpow(myarray[5], 5) == x)
		{
			cout << x << endl;
			counter += x;
		}
	}

	cout << "done! " << counter << endl;

	return 0;
}

int intpow(int a, int b)
{
	int temp = a;
	for (int i = 2; i <= b; i++)
		temp *= a;
	return temp;
}
#include <iostream>
using namespace std;

int d(int);

int main()
{
	int result = 0;
	for (int i = 2; i <= 10000; i++)
	{
		if (d(d(i)) == i && i != d(i))
		{
			result += i;
			cout << i << " ";
		}
	}

	cout << endl << result << endl;

	return 0;
}

int d(int x)
{
	int result = 0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
			result += i;
	}

	return result;
}
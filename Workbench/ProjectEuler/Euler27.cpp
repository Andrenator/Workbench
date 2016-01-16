#include <iostream>
using namespace std;

bool isprime(int);
int abbs(int);

int main()
{
	int a, b, consecutive = 0;
	for (int counter2 = -999; counter2 < 1000; counter2++)
	{			
		if (!isprime(counter2))
				continue;
		for (int counter = -999; counter < 1000; counter++)
		{
			cout << "checking " << counter << " and " << counter2 << "..." << endl;
			for (int counter3 = 0; ; counter3++)
			{
				if (counter3 > consecutive)
				{
					a = counter;
					b = counter2;
					consecutive = counter3;
				}
				if (!isprime(counter3*counter3 + counter*counter3 + counter2))
					break;
			}
		}
	}

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "consecutive: " << consecutive << endl;

	return 0;
}

bool isprime(int x)
{
	for (int counter = 2; counter*counter <= abbs(x); counter++)
	{
		if (abbs(x) % counter == 0)
			return false;
	}

	return true;
}

int abbs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}
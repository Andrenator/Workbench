#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned long long int num = 0;
	int pointer = 0;
	int loops = 1000;
	int digits[350] = { 0 };
	digits[349] = 1;

	for (int i = 0; i < loops; i++)
	{
		for (int x = 0; x < 350; x++)
			digits[x] *= 2;
		for (int x = 349; x > 0; x--)
		{
			//if (digits[x] > 9)
			{
				digits[x - 1] += digits[x] / 10;
				digits[x] %= 10;
			}
		}
	}

	for (int i = 0; i < 350; i++)
	{
		num += digits[i];
		if (digits[i] > 9)
			cout << "ERROR ";
	}

	cout << "Number: " << num << endl;
	return 0;
}
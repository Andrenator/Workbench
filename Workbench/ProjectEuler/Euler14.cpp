#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	unsigned long long int num = 0, temp;
	int count, x = 0;

	for (int i = 1; i < 1000000; i++)
	{
		temp = i;
		count = 1;
		while (temp != 1)
		{
			if (temp % 2 == 0)
				temp /= 2;
			else
				temp = temp * 3 + 1;

			count++;
		}

		if (count > x)
		{
			x = count;
			num = i;
		}

		if (i % 1000 == 0)
			cout << i <<endl;
	}

	cout << "Number: " << num << endl;
	return 0;
}
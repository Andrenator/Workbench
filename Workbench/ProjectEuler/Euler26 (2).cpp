#include <iostream>
#include <vector>
using namespace std;

int process(int);

int main()
{
	int result, length = 0;;
	for (int i = 1; i < 1000; i++)
	{
		cout << i << " has a value of " << process(i) << endl;
		if (process(i) > length)
		{
			result = i;
			length = process(i);
		}
	}
	cout << "result is " << result << " with a length of " << length;

	return 0;
}

int process(int x)
{
	vector<int> remainders (1000);
	long long unsigned int remainder = 1;
	for (int counter = 0; counter < 1000; counter++)
	{
		remainder *= 10;
		remainders[counter] = (remainder %= x);
		if (remainder == 0)
			return 0;
		for (int counter2 = counter - 1; counter2 >= 0; counter2--)
		{
			if (remainders[counter] == remainders[counter2])
			{
				return counter - counter2;
			}
		}
	}
	cout << "error on number " << x;
}
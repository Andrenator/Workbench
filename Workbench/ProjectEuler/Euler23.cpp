#include <iostream>
using namespace std;

bool abundance(int);

int main()
{
	bool numbers[28123];
	unsigned long long int result = 0;

	for (int i = 1; i <= 28123; i++)
	{
		numbers[i - 1] = abundance(i);
	}

	for (int i = 1; i <= 28123; i++)
	{
		for (int counter2 = 1; counter2 <= i; counter2++)
		{
			if (counter2 == i)
				result += i;
			if (numbers[counter2 - 1] && numbers[i - counter2 - 1])
				break;
		}
	}

	cout << result;

	return 0;
}

bool abundance(int x)
{
	int result = 0;

	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
			result += i;
	}

	if (result > x)
		return true;
	else
		return false;
}
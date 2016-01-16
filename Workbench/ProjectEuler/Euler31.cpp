#include <iostream>
using namespace std;

int count(int*);

int main()
{
	int coins[8] = { 0 };
	int total = 0;
	while (coins[7] < 2)
	{
		if (coins[1] > 100)
		{
			coins[1] = 0;
			coins[2]++;
		}
		if (coins[2] > 40)
		{
			coins[2] = 0;
			coins[3]++;
		}
		if (coins[3] > 20)
		{
			coins[3] = 0;
			coins[4]++;
		}
		if (coins[4] > 10)
		{
			coins[4] = 0;
			coins[5]++;
		}
		if (coins[5] > 4)
		{
			coins[5] = 0;
			coins[6]++;
		}
		if (coins[6] > 2)
		{
			coins[6] = 0;
			coins[7]++;
		}

		if (count(coins) <= 200)
			total++;
		coins[1]++;

	}
	cout << "total: " << total;

	return 0;
}

int count(int*ptr)
{
	int total = 0;
	total += ptr[0];
	total += ptr[1] * 2;
	total += ptr[2] * 5;
	total += ptr[3] * 10;
	total += ptr[4] * 20;
	total += ptr[5] * 50;
	total += ptr[6] * 100;
	total += ptr[7] * 200;
	return total;
}
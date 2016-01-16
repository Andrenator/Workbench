#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sumarray(int*, int);

int main()
{
	unsigned long long int num = 0, grid[21][21] = { 1 };

	grid[0][0] = 1;

	for (int y = 0; y <= 20; y++)
	{
		for (int x = 0; x <= 20; x++)
		{
			if (y > 0)
				grid[x][y] += grid[x][y - 1];
			if (x > 0)
				grid[x][y] += grid[x + 1][y];
		}
	}

	num = grid[20][20];

	cout << "Number: " << num << endl;
	return 0;
}

int sumarray(int*array, int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total += array[i];

	return total;
}
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int main()
{
	long long unsigned int x = 0, step = 1, delta = 2;
	while (step < MAX * MAX)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << step << endl;
			x += step;
			step += delta;
		}
		delta += 2;
	}

	x += MAX * MAX;

	cout << "step: " << step << endl;
	cout << "x: " << x << endl;
	return 0;
}
#include <iostream>
using namespace std;

void carry(int (*myarray)[32][32]);

int main()
{
	int a[32][32] = { 0 }, b[32][32] = { 0 }, c[32][32] = { 0 };
	int counter = 1;
	c[31][31] = 1;
	while (c[0][24] == 0)
	{
		for (int i = 0; i < 1024; i++)
		{
			a[i / 32][i % 32] = b[i / 32][i % 32];
			b[i / 32][i % 32] = c[i / 32][i % 32];
			c[i / 32][i % 32] = a[i / 32][i % 32] + b[i / 32][i % 32];
		}
		carry(&c);
		counter++;
	}
	cout << "counter = " << counter;

	return 0;
}

void carry(int (*myarray)[32][32])
{
	for (int i = 1023; i > 0; i--)
	{
		if ((*myarray)[i / 32][i % 32] > 9)
		{
			if (i % 32 == 0)
				(*myarray)[i / 32 - 1][31] += (*myarray)[i / 32][i % 32] / 10;
			else
				(*myarray)[i / 32][i % 32 - 1] += (*myarray)[i / 32][i % 32] / 10;
			(*myarray)[i / 32][i % 32] %= 10;
		}
	}
}
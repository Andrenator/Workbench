#include <iostream>
#include <vector>
using namespace std;

struct number
{
	int factor[100];
	int a, b;
	void initialize()
	{
		for (int i = 0; i < 100; i++)
			factor[i] = 0;
	}
};
void swapnums(number*, number*);

int main()
{
	vector<number> myarray;
	number test;
	int counter;

	for (int a = 2; a <= 100; a++)
	{
		for (int b = 2; b <= 100; b++)
		{
			test.initialize();
			test.a = a;
			test.b = b;
			counter = a;
			while (counter > 1)
			{
				for (int i = 2; i <= counter; i++)
				{
					if (counter % i == 0)
					{
						test.factor[i - 1]++;
						counter %= i;
						break;
					}
				}
			}
			for (int i = 0; i < 100; i++)
				test.factor[i] *= b;
			myarray.push_back(test);
		}
	}

	for (int i = 0; i < myarray.size() - 1; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (myarray[i].factor[j] < myarray[i + 1].factor[j])
			{
				swapnums(&myarray[i], &myarray[i + 1]);
				i = -1;
				break;
			}
			if (j == 99)
			{
				cout << myarray[i].a << "^" << myarray[i].b << " is the same as " << myarray[i + 1].a << "^" << myarray[i + 1].b << endl;
				myarray.erase(myarray.begin() + i);
			}
		}
	}

	cout << "numbers: " << myarray.size();
	return 0;
}

void swapnums(number* a, number* b)
{
	number temp;
	for (int i = 0; i < 100; i++)
	{
		temp.factor[i] = a->factor[i];
		a->factor[i] = b->factor[i];
		b->factor[i] = temp.factor[i];
	}
}
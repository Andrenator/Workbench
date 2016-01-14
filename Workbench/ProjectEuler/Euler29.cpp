#include <iostream>
#include <vector>
using namespace std;
#define LIMIT 100

struct exponent
{
	int a;
	int b;
};

int intpow(int, int);
void simplify(exponent*);
void swapexponents(exponent*, exponent*);

int main()
{
	vector<exponent> myarray;
	exponent temp;
	bool flag;

	for (int a = 2; a <= LIMIT; a++)
	{
		for (int b = 2; b <= LIMIT; b++)
		{
			temp.a = a;
			temp.b = b;
			simplify(&temp);
			myarray.push_back(temp);
		}
	}

	cout << myarray.size() << endl;
	
	for (long long int counter = 0; counter + 1 < myarray.size(); counter++)
	{
		if (myarray[counter].a > myarray[counter + 1].a)
		{
			swapexponents(&myarray[counter], &myarray[counter + 1]);
			if (counter > 1)
				counter-=2;
		}
		if (myarray[counter].a == myarray[counter + 1].a && myarray[counter].b > myarray[counter + 1].b)
		{
			swapexponents(&myarray[counter], &myarray[counter + 1]);
			if (counter > 1)
				counter-=2;
		}
		if (myarray[counter].a == myarray[counter + 1].a && myarray[counter].b == myarray[counter + 1].b)
		{
			myarray.erase(myarray.begin() + counter + 1);
			if (counter > 1)
				counter-=2;
		}
	}

	cout << myarray.size() << endl;

	return 0;
}



int intpow(int a, int b)
{
	int result = a;
	for (int i = 2; i <= b; i++)
	{
		result *= a;
	}
	return result;
}

void simplify(exponent* ptr)
{
	for (int i = 2; i*i <= ptr->a; i++)
	{
		for (int j = 7; j >= 2; j--)
		{
			if (intpow(i, j) == ptr->a)//  && ptr->b * j <= LIMIT)
			{
				ptr->a = i;
				ptr->b *= j;
			}
		}
	}
}

void swapexponents(exponent* first, exponent* second)
{
	exponent temp;
	temp.a = first->a;
	temp.b = first->b;
	first->a = second->a;
	first->b = second->b;
	second->a = temp.a;
	second->b = temp.b;
}
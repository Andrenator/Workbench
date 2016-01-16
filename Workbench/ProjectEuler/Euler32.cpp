#include <iostream>
using namespace std;

void permute(int*);
int validate(int*);

int main()
{
	int number[9] = { 1, 2, 3 , 4, 5, 6, 7, 8, 9 };
	long long int total = 0;
	do
	{
		permute(number);
		total += validate(number);
	} while (number[0] < number[1] && number[1] < number[2] && number[2] < number[3] && number[3] < number[4]
		&& number[4] < number[5] && number[5] < number[6] && number[6] < number[7] && number[7] < number[8]);
	cout << "total: " << total;

	return 0;
}

void permute(int*a)
{

}

int validate(int*a)
{
	int a, b;

	for (int lengtha = 1; lengtha < 9; lengtha++)
	{
		a = 0;
		b = 0;

		for (int lengthb = 1; lengthb < 9; lengthb++)
		{
			if (lengtha + lengthb >= 9)
				break;
			for (int i = 0; )
		}
	}
}
#include <iostream>
#include <vector>
using namespace std;

struct num
{
	int digit[9];
};
bool validate(num a)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (a.digit[i] == a.digit[j])
				return false;
		}
	}
	return true;
}

int main()
{
	vector<num> myarray;
	num temp;
}
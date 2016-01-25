#include <iostream>
#include <time.h>
#define DICE 2
using namespace std;

bool avgcheck(int* a)
{
	if (*(a) + *(a + 1) + *(a + 2) + *(a + 3) + *(a + 4) + *(a + 5) != (DICE*21 + 36*(DICE*DICE/2-DICE/2))/DICE)
		return false;
	else
		return true;
}
bool isdescending(int* a, int length)
{
	for (int i = 0; i < length -1; i++)
	{
		if (*(a + i) > *(a + i + 1))
			return false;
	}
	return true;
}
void lexicograph(int* a)
{

}

int main()
{
	int sides[DICE * 6];
	for (int i = 0; i < DICE * 6; i++)
		sides[i] = i + 1;

	for (; !isdescending(sides, DICE*6); lexicograph(sides))
	{

	}

	return 0;
}
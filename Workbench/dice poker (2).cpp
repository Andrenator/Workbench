#include <iostream>
#include <string>
#include <time.h>
#define HANDSIZE 7
#define LOOPS 1000000
#define COMBOCOUNT 14

using namespace std;

struct combo
{
	string name;
	int x;
	int expected;
};
void sortRolls(int*);
int outcomeCount(int*, int);
void displayRolls(int *);

int main()
{
	srand(time(NULL));
	combo combo[COMBOCOUNT];
	int comboFlag[COMBOCOUNT];
	int counter;
	int combos;
	float x;
	bool flag;

	combo[13].name = "5-2   ";		combo[13].expected = 25 + 4;
	combo[12].name = "4-3   ";		combo[12].expected = 16 + 9;
	combo[11].name = "4-2   ";		combo[11].expected = 16 + 4;
	combo[10].name = "3-3   ";		combo[10].expected = 9 + 9;
	combo[9].name = "3-2-2 ";		combo[9].expected = 9 + 4 + 4;
	combo[8].name = "3-2   ";		combo[8].expected = 9 + 4;
	combo[7].name = "2-2-2 ";		combo[7].expected = 4 + 4 + 4;
	combo[6].name = "2-2   ";		combo[6].expected = 4 + 4;
	combo[5].name = "7     ";		combo[5].expected = 49;
	combo[4].name = "6     ";		combo[4].expected = 36;
	combo[3].name = "5     ";		combo[3].expected = 25;
	combo[2].name = "4     ";		combo[2].expected = 16;
	combo[1].name = "3     ";		combo[1].expected = 9;
	combo[0].name = "2     ";		combo[0].expected = 4;

	for (counter = 0; counter < COMBOCOUNT; counter++)
	{
		combo[counter].x = 0;
	}
	
	int hand[7];
	for (int i = 0; i < LOOPS; i++)
	{
		for (counter = 0; counter < COMBOCOUNT; counter++)
		{
			comboFlag[counter] = 0;
		}
		combos = 0;
		
		for (counter = 0; counter < HANDSIZE; counter++)
		{
			hand[counter] = rand() % 6 + 1;
		}

		sortRolls(hand);

		for (counter = 1; counter <= 6; counter++)
		{
			if (outcomeCount(hand, counter) > 1 && outcomeCount(hand, counter) < 8)
				comboFlag[outcomeCount(hand, counter) - 2]++;
		}

		for (counter = 0; counter < COMBOCOUNT; counter++)
		{
			combos += comboFlag[counter];
		}

		for (counter = 0; counter < COMBOCOUNT; counter++)
		{
			if (combos == 1 && comboFlag[counter] == 1)
			{
				combo[counter].x++;
				if (counter == 5)
					displayRolls(hand);
			}
		}
			
		switch (combos)
		{
			case 1:
				break;
			case 2:
				if (comboFlag[0] == 2)
					combo[6].x++;
				if (comboFlag[0] == 1 && comboFlag[1] == 1)
					combo[8].x++;
				if (comboFlag[0] == 1 && comboFlag[2] == 1)
					combo[11].x++;
				if (comboFlag[0] == 1 && comboFlag[3] == 1)
					combo[13].x++;
				if (comboFlag[1] == 2)
					combo[10].x++;
				if (comboFlag[1] == 1 && comboFlag[2] == 1)
					combo[12].x++;
				break;
			case 3:
				if (comboFlag[0] == 3)
					combo[7].x++;
				if (comboFlag[0] == 2 && comboFlag[1] == 1)
					combo[9].x++;
				break;
			default:
				cout << "error!  " << combos << endl;
		}
	}

	do
	{
		flag = false;

		for (counter = 0; counter < COMBOCOUNT - 1; counter++)
		{
			if (combo[counter].x < combo[counter + 1].x)
			{
				x = combo[counter].x;
				combo[counter].x = combo[counter + 1].x;
				combo[counter + 1].x = x;
				flag = true;
			}
		}

	} while (flag);

	for (counter = 0; counter < COMBOCOUNT; counter++)
	{
		cout << combo[counter].name << ": " << (float)combo[counter].x / (LOOPS / 100) << "  :  " << combo[counter].expected << endl;
	}

	return 0;
}

void sortRolls(int *myPointer)
{
	int x;
	bool flag;

	do
	{
		flag = false;

		for (int counter = 0; counter < HANDSIZE - 1; counter++)
		{
			if (myPointer[counter] < myPointer[counter + 1])
			{
				x = myPointer[counter];
				myPointer[counter] = myPointer[counter + 1];
				myPointer[counter + 1] = x;
				flag = true;
			}
		}

	} while (flag);
}

int outcomeCount(int *myArray, int x)
{
	int total = 0;

	for (int counter = 0; counter < HANDSIZE; counter++)
	{
		if (myArray[counter] == x)
			total++;
	}

	return total;
}

void displayRolls(int *myArray)
{
	for (int counter = 0; counter < HANDSIZE; counter++)
	{
		cout << myArray[counter] << " ";
	}

	cout << endl;
}
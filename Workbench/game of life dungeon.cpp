#include <iostream>
#include <time.h>
#define LOOPS 1000
#define WIDTH 11
#define HEIGHT 11

using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
	//srand(time(NULL));
	int binaryMap[HEIGHT][WIDTH];
	bool flagMap[HEIGHT][WIDTH];
	float decimalMap[HEIGHT][WIDTH];
	point scan;
	scan.x = WIDTH / 2;
	scan.y = HEIGHT / 2;
	int direction = 1;

	for (int countery = 0; countery < HEIGHT; countery++)
	{
		for (int counterx = 0; counterx < WIDTH; counterx++)
		{
			binaryMap[countery][counterx] = 0;
			flagMap[countery][counterx] = false;
			decimalMap[countery][counterx] = 0;
		}
	}


	binaryMap[scan.y][scan.x] = 1;
	flagMap[scan.y][scan.x] = true;
	scan.x++;

	do
	{
		binaryMap[scan.y][scan.x] = 1;
		flagMap[scan.y][scan.x] = true;

		switch (direction)
		{
			case 1:
				if (flagMap[scan.y - 1][scan.x])
				{
					scan.x++;
				}
				else
				{
					direction = 4;
				}
				break;
			case 2:
				if (flagMap[scan.y][scan.x + 1])
				{
					scan.y++;
				}
				else
				{
					direction = 1;
				}
				break;
			case 3:
				if (flagMap[scan.y + 1][scan.x])
				{
					scan.x--;
				}
				else
				{
					direction = 2;
				}
				break;
			case 4:
				if (flagMap[scan.y][scan.x - 1])
				{
					scan.y--;
				}
				else
				{
					direction = 3;
				}
				break;
		}
	} while (scan.x > 1 && scan.y > 1 && scan.x < WIDTH - 1 && scan.y > HEIGHT - 1);

	for (int countery = 0; countery < HEIGHT; countery++)
	{
		for (int counterx = 0; counterx < WIDTH; counterx++)
		{
			cout << binaryMap[countery][counterx] << " ";
		}

		cout << endl;
	}


	return 0;
}
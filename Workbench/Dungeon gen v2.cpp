#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

#define HEIGHT 21
#define WIDTH 21
#define LOOPS 2000

struct point  //used for the origin and scanner points
{
	int x;
	int y;
};

int main()
{
	srand(time(NULL));					//set the random
	int mapTiles[HEIGHT][WIDTH];		// this is the actual map, dirt is 0 and empty space is 1
	point scan;							//the moving point
	int conwayScore;

	for (int countery = 0; countery < HEIGHT; countery++)		// sets every square to dirt
	{
		for (int counterx = 0; counterx < WIDTH; counterx++)
		{
			mapTiles[countery][counterx] = 0;
		}
	}

	mapTiles[HEIGHT/2][WIDTH/2] = 1;  //the center of the dungeon is always 1

	for (int i = 0; i < LOOPS; i++)
	{
		scan.x = rand() % (WIDTH - 2) + 1;
		scan.y = rand() % (HEIGHT - 2) + 1;

		conwayScore = 0;

		for (int theta = 0; theta < 360; theta += 90)
		{
			conwayScore += mapTiles[int(scan.y + sin(theta) + .5)][int(scan.x + cos(theta) + .5)];
		}

		{
			if (rand() % 3 == 0 && conwayScore < 4 && conwayScore)
				mapTiles[scan.y][scan.x] = 1;
		}
	}

	for (int countery = 0; countery < HEIGHT; countery++)
	{
		for (int counterx = 0; counterx < WIDTH; counterx++)
		{
			if (mapTiles[countery][counterx])
			{
				cout << " ";
			}
			else
			{
				cout << "0";
			}
		}

		cout << endl;
	}

	return 0;
}
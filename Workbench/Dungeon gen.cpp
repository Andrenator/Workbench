#include <iostream>
#include <time.h>

using namespace std;

#define HEIGHT 21
#define WIDTH 21

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
	point origin;						//the origin point, never moves.
	origin.y = scan.y = HEIGHT / 2;
	origin.x = scan.x = WIDTH / 2;
	int r = 1;

	for (int countery = 0; countery < HEIGHT; countery++)		// sets every square to dirt
	{
		for (int counterx = 0; counterx < WIDTH; counterx++)
		{
			mapTiles[countery][counterx] = 0;
		}
	}

	mapTiles[scan.y][scan.x] = 1;  //the center of the dungeon is always 1

	do
	{
		for (int direction = 1; direction <= 4; direction++)
		{
			switch (direction)
			{
				case 1:
					scan.x = origin.x + r;
					scan.y = origin.y - r;
					break;
				case 2:
					scan.x = origin.x - r;
					scan.y = origin.y - r;
					break;
				case 3:
					scan.x = origin.x - r;
					scan.y = origin.y + r;
					break;
				case 4:
					scan.x = origin.x + r;
					scan.y = origin.y + r;
					break;
			}
	
			for (int i = 0; i < 2 * r + 1; i++)
			{
				if (mapTiles[scan.y + 1][scan.x] || mapTiles[scan.y - 1][scan.x] || mapTiles[scan.y][scan.x - 1] || mapTiles[scan.y][scan.x + 1])
				{
					if (rand() % 3 != 0)
						mapTiles[scan.y][scan.x] = 1;
				}

				switch (direction)
				{
					case 1:
						scan.x--;
						break;
					case 2:
						scan.y++;
						break;
					case 3:
						scan.x++;
						break;
					case 4:
						scan.y--;
						break;
				}
			}
		}

		r++;
	} while (r < HEIGHT / 2 && r < WIDTH / 2);

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
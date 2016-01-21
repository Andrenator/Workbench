#include <iostream>
#define WIDTH 20  //the #define function basically replaces all instances of WIDTH with 20
#define HEIGHT 20
using namespace std;

int main()
{
	char myarray[WIDTH][HEIGHT];

	for (int i = 0; i < WIDTH; i++)  //this loop sets the north and south boundaries to water
	{
		myarray[i][0] = '~';
		myarray[i][HEIGHT - 1] = '~';
	}
	for (int i = 0; i < HEIGHT; i++)  //this loops sets the east and west boundaries to water
	{
		myarray[0][i] = '~';
		myarray[WIDTH - 1][i] = '~';
	}

	for (int i = 0; i < WIDTH*HEIGHT/5; i++)  //this loop goes through and sets about 1/5 of the squares to land.
		myarray[rand() % WIDTH][rand() % HEIGHT] = '#';

	for (int y = 0; y < HEIGHT; y++)  //this loop and nested loop outputs the map
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (myarray[x][y] == '#')
				cout << myarray[x][y];
			else
				cout << '~';
		}
		cout << endl;
	}

	return 0;
}

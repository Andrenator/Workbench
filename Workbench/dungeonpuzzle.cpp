#include <iostream>
#include <string>
using namespace std;

struct gem
{
	string color;
	float x, y;
};
void switchgems(gem* a, gem* b)
{
	gem c;
	c.color = a->color;
	a->color = b->color;
	b->color = c.color;
	c.x = a->x;
	a->x = b->x;
	b->x = c.x;
	c.y = a->y;
	a->y = b->y;
	b->y = c.y;
}

int main()
{
	gem myarray[40];
	for (int i = 0; i < 7; i++)
		myarray[i].color = "red";
	for (int i = 7; i < 14; i++)
		myarray[i].color = "blue";
	for (int i = 14; i < 21; i++)
		myarray[i].color = "green";
	for (int i = 21; i < 28; i++)
		myarray[i].color = "black";
	for (int i = 28; i < 35; i++)
		myarray[i].color = "white";
	for (int i = 35; i <= 40; i++)
		myarray[i].color = "gold";

	for (int i = 0; i < 40; i++)
		switchgems(&myarray[i], &myarray[i + 1 + rand() % (40 - i)]);

	return 0;
}
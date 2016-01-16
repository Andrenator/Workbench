//Andrenator
//12/01/2015
//Program uses number of points (POINTS) to create a polygon with the points equidistant from the origin.

#include <iostream>
using namespace std;
#define POINTS 5  //number of sides

struct point  //the container for a point, with an x value and y value
{
	double x;
	double y;
};
bool epsilon(double a, double b)
{
	if (a - b < .00001 && b - a < .00001)
		return true;
	else
		return false;
}
double square(double x)  //my own function for "^2"
{
	return x*x;
}
double root(double x)  //my own function for returning the square root of a number (just trust me)
{
	double temp = 0;
	double delta = x / 2;
	do
	{
		if (temp*temp > x)
			temp -= delta;
		else
			temp += delta;
		delta /= 2;
	} while (!epsilon(temp*temp, x));
	return temp;
}
double distance(point a, point b)  //(x1-x2)^2 + (y1-y2)^2 = d^2, returns d
{
	return root(square(a.x - b.x) + square(a.y - b.y));
}
point unit(double x, double y)
{
	double scale = root(square(x) + square(y));
	point answer;
	answer.x = x / scale;
	answer.y = y / scale;
	return answer;
}

int main()
{
	point current[POINTS];  //creates array of points for the current values
	point last[POINTS];  //creates the array for "reference" points; they update every loop
	point origin;  //the point at (0,0)
	origin.x = 0;
	origin.y = 0;

	double temp;  //I use this to store the length of the vector from the origin to each point

	for (int i = 0; i < POINTS; i++)  //Sets the initial coordinates at (0,1), (1,1), (2,1), ..., (n - 1, 1)
	{
		current[i].y = 1;
		current[i].x = i;
	}

	do  //main loop
	{
		for (int i = 0; i < POINTS; i++)  //this loop finds the distance from the origin and scales that vector down to 1
		{
			current[i] = unit(current[i].x, current[i].y);
		}

		for (int i = 0; i < POINTS; i++)  //this loop sets the reference points to be equal to the current points
		{
			last[i].x = current[i].x;
			last[i].y = current[i].y;
		}

		for (int i = 1; i < POINTS; i++)  //loop for moving the current points.  The outer loop cycles through current points.  Starts at 1 b/c I want the point at (0,1) to be constant
		{
			for (int j = 0; j < POINTS; j++)  //this inner loop cycles through the other points.  Each other point pushes on the current point based on distance
			{
				if (i != j)  //a point can't push on itself
				{
					current[i].x += unit(last[i].x - last[j].x, last[i].y - last[j].y).x / square(distance(last[i], last[j]));
					current[i].y += unit(last[i].x - last[j].x, last[i].y - last[j].y).y / square(distance(last[i], last[j]));
				}
			}
		}
		for (int i = 0; i < POINTS; i++)  //this loop outputs the points and their locations
			cout << "point " << i << ":  x: " << current[i].x << ", y: " << current[i].y << endl;
	} while (current[POINTS - 1].y / current[POINTS - 1].x - last[POINTS - 1].y / last[POINTS - 1].x > .0001);  //the main loop loops until the angle of "current" to origin and "reference" to origin are the same

	return 0;
}
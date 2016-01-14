#include <iostream>
#include <time.h>
using namespace std;
#define POINTS 6

struct point
{
	float x;
	float y;
	void init(float a, float b)
	{
		x = a;
		y = b;
	}
	point unit()
	{
		point temp;
		temp.init(x / sqrt(x*x + y*y), y / sqrt(x*x + y*y));
		return temp;
	}
	float angle()
	{
		float ang = 180 * atan2(y , x) / 3.1415926;
		if (ang >= 0)
			return ang;
		else return 360 + ang;
	}
};
float distance(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool comparefloat(float a, float b);

int main()
{
	point vec;
	point myarray[POINTS];
	point last[POINTS];
	for (int i = 0; i < POINTS; i++)
		myarray[i].init(i, 1);
	srand(time(NULL));

	do
	{
		for (int i = 0; i < POINTS; i++)
		{
			last[i].init(myarray[i].unit().x, myarray[i].unit().y);
			myarray[i].init(myarray[i].unit().x, myarray[i].unit().y);
		}

		for (int i = 1; i < POINTS; i++)
		{
			for (int j = 0; j < POINTS; j++)
			{
				if (i == j)
					continue;
				vec.init(last[i].x - last[j].x, last[i].y - last[j].y);
				myarray[i].x += vec.unit().x / (distance(last[i], last[j])*distance(last[i], last[j])*(1+rand()%10/10));
				myarray[i].y += vec.unit().y / (distance(last[i], last[j])*distance(last[i], last[j])*(1+rand()%10/10));
			}
		}

		cout << "Current point locus: (" << myarray[POINTS - 1].x << "," << myarray[POINTS - 1].y << "), angle " << myarray[POINTS - 1].angle() << endl;
		cout << "   Last point locus: (" << last[POINTS - 1].x << "," << last[POINTS - 1].y << "), angle " << last[POINTS - 1].angle() << endl;
	} while (!comparefloat(myarray[POINTS - 1].angle() - last[POINTS - 1].angle(), 0));

	for (int i = 0; i < POINTS; i++)
	{
		cout << "Last  " << i << ": (" << last[i].x << "," << last[i].y << ") "
			<< " at " << last[i].angle() << " degrees" << endl;
	}

	return 0;
}

bool comparefloat(float a, float b)
{
	if (a - b < .000001 && b - a < .000001)
		return true;
	else
		return false;
}
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream myfile;
	myfile.open("C:\\\\Users\\Andre\\Desktop\\krumpus.txt");
	int floor = 0;
	int steps = 0;
	char c;

	while (!myfile.eof())
	{
		if (!myfile.get(c))
			break;
		steps++;
		if (c == '(')
		{
			floor++;
		}
		if (c == ')')
		{
			floor--;
		}
		cout << c;
		if (floor == -1)
			break;
	}
	cout << endl << "Santa's on floor " << floor << " after " << steps << " steps" << endl;

	myfile.close();
	return 0;
}
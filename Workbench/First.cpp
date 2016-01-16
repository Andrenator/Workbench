#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	do
	{
		cout << endl;

		switch (rand() % 5)
		{
			case 0:
				cout << "don't kick, babie" << endl;
				break;
			case 1:
				cout << "don't KICK, babie" << endl;
				break;
			case 2:
				cout << "don't kick, BABIE" << endl;
				break;
			case 3:
				cout << "DON'T kick, babie" << endl;
				break;
			case 4:
				cout << "DON'T KICK, BABIE" << endl;
				break;
		}

		system("pause");

	} while (1);




	return 0;
}
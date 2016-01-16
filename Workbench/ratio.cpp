#include <iostream>
using namespace std;

int main()
{
	int smallArmy = 100;
	int bigArmy;
	int tempArmy;
	int casualties;
	float ratio = .5;

	for (bigArmy = 100; bigArmy <= 200; bigArmy++)
	{
		casualties = bigArmy*((float)smallArmy / bigArmy)*((float)smallArmy / bigArmy);
		tempArmy = bigArmy - casualties;
		//ratio = (float)(bigArmy - tempArmy)*()
		cout << "Small Army: " << smallArmy << "\tBig Army: " << bigArmy << ", final: " << tempArmy << ", Difference: " << bigArmy - tempArmy << endl;  
		cout << "\tBig army attack ratio: " << (float)smallArmy / bigArmy << ", Small army attack ratio: " << (float)casualties / smallArmy << endl;
	}

	system("pause");
	return 0;
}
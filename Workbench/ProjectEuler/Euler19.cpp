#include <iostream>
using namespace std;

int main()
{
	int totaldays = 2;
	int result = 0;
	for (int year = 1901; year <= 2000; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			if (totaldays % 7 == 0)
				result++;
			switch (month)
			{
				case 1:
					totaldays += 31;
					break;
				case 2:
					totaldays += 28;
					if (year % 4 == 0 && year != 1900)
						totaldays++;
					break;
				case 3:
					totaldays += 31;
					break;
				case 4:
					totaldays += 30;
					break;
				case 5:
					totaldays += 31;
					break;
				case 6:
					totaldays += 30;
					break;
				case 7:
					totaldays += 31;
					break;
				case 8:
					totaldays += 31;
					break;
				case 9:
					totaldays += 30;
					break;
				case 10:
					totaldays += 31;
					break;
				case 11:
					totaldays += 30;
					break;
				case 12:
					totaldays += 31;
					break;
			}
		}
	}

	cout << result << endl;
	return 0;
}
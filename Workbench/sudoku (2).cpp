#include <iostream>
#include <fstream>
using namespace std;

struct cell
{
	bool number[9];
};
void initializeCell(cell* square)  //sets all possibilities to true
{
	for (int i = 0; i < 9; i++)
		square->number[i] = true;
}
void setCell(cell* square, int x)  //input the number, 0-8
{
	for (int i = 0; i < 9; i++)
	{
		if (i == x)
			square->number[i] = true;
		else
			square->number[i] = false;
	}
}
int countCell(cell* square)
{
	int x = 0;
	for (int i = 0; i < 9; i++)
	{
		if (square->number[i])
			x++;
	}
	return x;
}
int valueCell(cell* square)  //returns 0-8 if the cell is known, or -1 if it's unknown
{
	if (countCell(square) == 1)
	{
		for (int i = 0; i < 9; i++)
		{
			if (square->number[i])
				return i;
		}
	}
	else
		return -1;
}

int main()
{
	fstream myfile;
	myfile.open("C://Users//Andre//Desktop//sudoku.txt");
	cell myArray[9][9];
	int x = 0;
	int y = 0;
	char c;
	bool flag;

	while (!myfile.eof())
	{
		if (!myfile.get(c))
			break;

		if (c == '\n')
		{
			y++;
			x = 0;
		}
		else if (c == ' ')
		{
			initializeCell(&(myArray[x][y]));
			x++;
		}
		else if ((int)c >=49 && (int)c <= 57)
		{
			setCell(&(myArray[x][y]), (int)c - 49);
			x++;
		}
		else
		{
			cout << "error, character " << (int)c << " not recognized" << endl;
		}
	}

	do
	{
		flag = false;

		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				if (countCell(&(myArray[i][j])) > 1)
					continue;
				for (int k = 0; k < 9; k++)  //horizontal lines
				{
					if (k == i)
						continue;
					if (myArray[k][j].number[valueCell(&(myArray[i][j]))])
					{
						myArray[k][j].number[valueCell(&(myArray[i][j]))] = false;
						flag = true;
					}
				}
				for (int k = 0; k < 9; k++)  //vertical lines
				{
					if (k == j)
						continue;
					if (myArray[i][k].number[valueCell(&(myArray[i][j]))])
					{
						myArray[i][k].number[valueCell(&(myArray[i][j]))] = false;
						flag = true;
					}
				}
				for (int k = 0; k < 9; k++)  // 3x3 squares
				{
					x = i - i % 3;
					y = j - j % 3;
					if (x + k % 3 == i && y + k / 3 == j)
						continue;
					if (myArray[x + k % 3][y + k / 3].number[valueCell(&(myArray[i][j]))])
					{
						myArray[x + k % 3][y + k / 3].number[valueCell(&(myArray[i][j]))] = false;
						flag = true;
					}
				}
			}
		}
	} while (flag);

	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			/*if (1 + valueCell(&(myArray[i][j])))
				cout << valueCell(&(myArray[i][j])) + 1 << " ";
			else
				cout << "# ";*/
			cout << countCell(&(myArray[i][j])) << " ";
		}
		cout << endl;
	}

	myfile.close();
	system("pause");
	return 0;
}
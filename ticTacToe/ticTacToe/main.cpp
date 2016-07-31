/*

 0 2 4
0*|*|*
 _|_|_
2*|*|*
 _|_|_
4*|*|*

*/
#include <iostream>
#include <cstdlib> 
using namespace std;

const int SIZE = 5;
void makeGrid(int & row, int & col, char grid[][SIZE], int used[][SIZE]);
void makeNumbers(char grid[][SIZE]);
void getMove(int & row, int & col, char grid[][SIZE], char letter, int used[][SIZE]);
bool checkWinnder(int & row, int & col, char grid[][SIZE], char letter, int used[][SIZE]);
void declare(char letter, char grid[][SIZE]);


int main()
{
	char x = 'x';
	char o = '0';

	int row = 0;
	int col = 0;
	
	int used[SIZE][SIZE] = { 0 };
	char grid[SIZE][SIZE] = { { '*', '|' , '*' , '|' , '*' },
							  { '_', '|' , '_' , '|' , '_' },
							  { '*', '|' , '*' , '|' , '*' },
							  { '_', '|' , '_' , '|' , '_' },
							  { '*', '|' , '*' , '|' , '*' } };

	
	
	while (col != 9 && row != 9)
	{
		getMove(row, col,grid,x,used);
		if (checkWinnder(row, col, grid, x, used))
		{
			declare(x,grid);
		}
		system("CLS");
		
		getMove(row, col, grid, o,used);
		if (checkWinnder(row, col, grid, o, used))
		{
			declare(o, grid);
		}
		system("CLS");
	}
	
	
	return 0;
}

void makeNumbers(char grid[][SIZE])
{
	cout << " 0 2 4\n";

	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			cout << i;
		else
			cout << " ";

		for (int j = 0; j < SIZE; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
}
void getMove(int & row, int & col, char grid[][SIZE], char letter, int used[][SIZE])
{
	int num = 0;
	while (num == 0)
	{
		makeNumbers(grid);
		cout << "Enter row: ";
		cin >> row;
		cout << "Enter col: ";
		cin >> col;

		if (used[row][col] == 1)
		{
			system("CLS");
		}
		else
			num = 1;
	}

	grid[row][col] = letter;
	used[row][col] = 1;

	
}
bool checkWinnder(int & row, int & col, char grid[][SIZE], char letter, int used[][SIZE])
{
	//across row
	int temp = 0;
	for (int i = 0; i < 3;i++)
	{
		for (int j = 0; j < 3;j++)
		{
			if ((grid[temp][0] == letter) && (grid[temp][2] == letter) && (grid[temp][4] == letter))
			{
				return 1;
			}
		}
		temp = temp + 2;
	}
	//down row
	temp = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((grid[0][temp] == letter) && (grid[2][temp] == letter) && (grid[4][temp] == letter))
			{
				return 1;
			}
		}
		temp = temp + 2;
	}
	//diaganolly
	if ((grid[0][0] == letter) && (grid[2][2] == letter) && (grid[4][4] == letter))
	{
		return 1;
	}
	if ((grid[0][4] == letter) && (grid[2][2] == letter) && (grid[4][0] == letter))
	{
		return 1;
	}
	return 0;
}
void declare(char letter, char grid[][SIZE])
{
	system("CLS");
	makeNumbers(grid);
	cout << letter << " is winner!\n";
	cout << "play again: ";
	cin >> letter;
}
void makeGrid(int & row, int & col, char grid[][SIZE], int used[][SIZE])
{
	row = 0;
	col = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[row][col] = '*';
			col += 2;
		}
		row += 2;
	}
}


#include "functions.h"

int main()
{
	int SIZE;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите количество ферзей N, которые надо расставить на доске NxN:  ";
	cin >> SIZE;
	cout << endl;
	if(SIZE < 4)
	{
		cout << "–ешений нет." << endl;
		return 0;
	}
	int** board = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		board[i] = new int [SIZE];
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
	setQueen(SIZE, board, 0, 0);
	return 0;
}
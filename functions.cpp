#include "functions.h"

int resultsCount = 0; //кол-во решений

//функция setQueen() пробует найти результаты решений
void setQueen(int SIZE, int** board, int curr_line, int curr_q) 	
{
	if(curr_q == SIZE)
    {
		cout << "Result #" << ++resultsCount << endl;
		showBoard(SIZE, board);
		return;
    }
	if(curr_line == SIZE)
	{
		return; 
	}
    for(int i = 0; i < SIZE; i++)
    {
        //здесь проверяем, что если поставим в board[curr_line][i] ферзя (единицу),
        //то он будет единственным в этой строке, столбце и диагоналях
        if(tryQueen(SIZE, board, curr_line, i, curr_q) == true)
        {
            board[curr_line][i] = 1;
			curr_q++;
            setQueen(SIZE, board, curr_line+1, curr_q);
            board[curr_line][i] = 0;
			curr_q--;
        }
    }
    return; 
}

//функция tryQueen() проверяет нет ли уже установленных ферзей
//по вертикали и диагоналям
bool tryQueen(int SIZE, int** board, int curr_line, int curr_column, int curr_q)
{
	if(curr_q == SIZE)
	{
		return false;
	}
    for(int i = 0; i < curr_line; i++)
    {
        if(board[i][curr_column] == 1)
        {
            return false;
        }
    }
    for(int i = 1; (i <= curr_line) && ( (curr_column - i) >= 0 ); i++)
    {
        if(board[curr_line-i][curr_column-i] == 1)
        {
            return false;
        }
    }
    for(int i = 1; (i <= curr_line) && ( (curr_column + i) < SIZE ); i++)
    {
        if(board[curr_line-i][curr_column+i] == 1)
        {
            return false;
        }
    }
    return true;
}

//функция showBoard() отображает доску
void showBoard(int SIZE, int** board)
{
    for(int curr_line = 0; curr_line < SIZE; curr_line++)
    {
        for(int curr_column = 0; curr_column < SIZE; curr_column++)
        {
			if(board[curr_line][curr_column] == 1)
			{
				cout << "Q ";
			}
			if(board[curr_line][curr_column] == 0)
			{
				cout << ". ";
			}
        }
        cout << endl;
    }
	cout << endl;
}
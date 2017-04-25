#include "functions.h"

int resultsCount = 0; //���-�� �������

//������� setQueen() ������� ����� ���������� �������
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
        //����� ���������, ��� ���� �������� � board[curr_line][i] ����� (�������),
        //�� �� ����� ������������ � ���� ������, ������� � ����������
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

//������� tryQueen() ��������� ��� �� ��� ������������� ������
//�� ��������� � ����������
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

//������� showBoard() ���������� �����
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
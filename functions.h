#include <iostream>

using namespace std;

void showBoard(int SIZE, int** board);
bool tryQueen(int SIZE, int** board, int curr_line, int curr_column, int curr_q_num);
void setQueen(int SIZE, int** board, int curr_line, int curr_q);
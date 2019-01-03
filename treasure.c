#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int board[6][6];
int time = 0;
int current[6][6];
int countOfpossessingTreasure = 0;
int countOfJudgedBox = 0;

int setRandom(int row, int column)
{
    double random = (double)rand() / (RAND_MAX + 1.0);
    double probability = (row + column) * 0.1;
    if (random < probability)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void proceed(row, column)
{
    if (row < 6)
    {
        current[row + 1][column] = 1;
    }
    else if (column < 6)
    {
        current[row][column + 1] = 1
    }
    // TODO: row=5, column=5の場合の処理
}

int setTreasureAtRandomPlace()
{
    int board[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int k = 0; k < 6; k++)
        {
            board[i][k] == setRandom(i, k);
        }
    }
}

void returnToStart()
{
}

void treasure()
{
    getEightByEightBoard();
}

int main()
{
}
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int board[6][6];
int time = 0;
int current[6][6];
int countOfpossessingTreasure = 0;
int countOfJudgedBox = 0;
int row = 0;
int column = 0;

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
void judgeIsThereTreasure(row, column)
{
    if (board[row][column] == 1)
    {
        countOfpossessingTreasure++;
    }

    // if (countOfpossessingTreasure > 1)
    // {
    //     returnToStart(row, column);
    // }
    // else
    // {
    //     proceed();
    // }
}

void proceed(row, column)
{
    if (row < 6)
    {
        row++;
        current[row][column] = 1;
        countOfJudgedBox++;

        proceed(row, column);
    }
    else if (column < 6)
    {
        column++;
        current[row][column] = 1;
        countOfJudgedBox++;
        proceed(row, column);
    }
    else
    {
        printf("掘りつくしました");
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

void returnToStart(row, column)
{
    int distance = row + column;
    row = 0, column = 0;
}

void treasure()
{
    current[0][0] = 1;
    for (int i = 0; int i = 6;)
}

int main()
{
}
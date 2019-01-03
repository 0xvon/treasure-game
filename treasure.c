#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// なるべくアルゴリズムがはっきり見えるようネストを深くして処理を細かく分ける -> テストできる
// mvvm構造

int board[6][6];
int passingTime = 0;
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
}

void canIContinue(row, column)
{
    if (countOfpossessingTreasure > 1)
    {
        returnToStart(row, column);
    }
    else
    {
        proceed(row, column);
    }
}

void proceed(row, column)
{
    passingTime++;

    if (row < 6)
    {
        row++;
        current[row][column] = 1;
        countOfJudgedBox++;
        judgeIsThereTreasure(row, column);
        canIContinue(row, column);
    }
    else if (column < 6)
    {
        column++;
        current[row][column] = 1;
        countOfJudgedBox++;
        judgeIsThereTreasure(row, column);
        canIContinue(row, column);
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
    time += countOfpossessingTreasure * distance;
}

void judgeWhetherDeadOrAlive()
{
    int isContinue;
    printf("経過時間t=%d, お宝の総数=%d, このまま続けますか?\n(続ける:1, 続けない:0)>>", passingTime, countOfpossessingTreasure);
    scanf("%d", &isContinue);
    if (isContinue == 1)
    {
        treasure();
    }
    else
    {
        printf("終了します");
    }
}

void treasure()
{
    current[0][0] = 1;
    proceed(0, 0);
    judgeWhetherDeadOrAlive();
}

int main()
{
    treasure();

    return 0;
}
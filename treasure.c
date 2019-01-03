#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int countOfJudgedBox = 0;
int passingTime = 0;
int current[6][6];
int map[6][6];
int countOfpossessingTreasure = 0;
int countOfpossessingTreasureForMe = 0;
// srand(time(NULL) * 12345);
// int row = 0;
// int column = 0;

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

void setTreasureAtRandomPlace()
{
    printf("---宝の地図---\n");
    for (int i = 0; i < 6; i++)
    {
        printf("|");
        for (int k = 0; k < 6; k++)
        {
            map[i][k] = setRandom(i, k);
            printf("%3d", map[i][k]);
            current[i][k] = 0;
        }
        printf("  |\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
}
void judgeIsThereTreasure(row, column)
{
    if (map[row][column] == 1)
    {
        countOfpossessingTreasureForMe++;
    }
}

void returnToStart(row, column)
{
    int distance = row + column;
    passingTime += (countOfpossessingTreasureForMe * distance);
    countOfpossessingTreasure += countOfpossessingTreasureForMe;
    countOfpossessingTreasureForMe = 0;
}

int canIContinue()
{
    if (countOfpossessingTreasureForMe > 1)
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
    passingTime++;

    if (row < 5)
    {
        row++;
        current[row][column] = 1;
        countOfJudgedBox++;
        judgeIsThereTreasure(row, column);
        if (canIContinue() == 1)
        {
            returnToStart(row, column);
        }
        else
        {
            proceed(row, column);
        }
    }
    else if (column < 5)
    {
        column++;
        current[row][column] = 1;
        countOfJudgedBox++;
        judgeIsThereTreasure(row, column);
        if (canIContinue() == 1)
        {
            returnToStart(row, column);
        }
        else
        {
            proceed(row, column);
        }
    }
    else
    {
        printf("掘りつくしました\n");
    }
    // TODO: row=5, column=5の場合の処理
}

int judgeWhetherDeadOrAlive()
{
    int isContinue;
    printf("経過時間t=%d, お宝の総数=%d, このまま続けますか?\n(続ける:1, 続けない:0)>>", passingTime, countOfpossessingTreasure);
    scanf("%d", &isContinue);
    if (isContinue == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void treasure()
{
    current[0][0] = 1;
    setTreasureAtRandomPlace();
    proceed(0, 0);
    if (judgeWhetherDeadOrAlive() == 1)
    {
        treasure();
    }
}

int main()
{
    treasure();

    return 0;
}
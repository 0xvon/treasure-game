#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 開拓数
int countOfJudgedBox = 0;
// 経過時間
int passingTime = 0;
// 設定時間
int settingTime = 90;
// 現在地・開拓位置
int current[6][6];
// ボード・お宝の有無
int map[6][6];
// 総数
int countOfpossessingTreasure = 0;
// 所有数
int countOfpossessingTreasureForMe = 0;
int sum = 0;
int countOfTreasure = 0;

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
    // srand(time(NULL) * 12345);
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

void timeup()
{
    countOfpossessingTreasure += countOfpossessingTreasureForMe;
    printf("時間切れです\n");
    printf("経過時間t=%d, お宝の総数=%d\n", passingTime, countOfpossessingTreasure);
    printf("終了します。また来てね！\n");
    countOfTreasure++;
    sum += countOfpossessingTreasure;
}

void returnToStart(row, column)
{
    int distance = row + column;
    passingTime += (countOfpossessingTreasureForMe * distance);
    countOfpossessingTreasure += countOfpossessingTreasureForMe;
    countOfpossessingTreasureForMe = 0;
    if (settingTime <= passingTime)
    {
        timeup();
    }
}

int canIContinue()
{
    if (countOfpossessingTreasureForMe > 1)
    {
        return 0;
    }
    else
    {
        return 1;
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
        if (settingTime <= passingTime)
        {
            timeup();
        }
        else if (canIContinue() == 0)
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
        if (settingTime <= passingTime)
        {
            timeup();
        }
        else if (canIContinue() == 0)
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
    // int isContinue;
    // printf("経過時間t=%d, お宝の総数=%d, このまま続けますか?\n(続ける:1, 続けない:0)>>", passingTime, countOfpossessingTreasure);
    // scanf("%d", &isContinue);
    // if (isContinue == 1)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
    if (passingTime < 90)
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
    proceed(0, 0);
    if (judgeWhetherDeadOrAlive() == 1)
    {
        treasure();
    }
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        setTreasureAtRandomPlace();
        treasure();
        passingTime = 0;
        countOfpossessingTreasure = 0;
        countOfpossessingTreasureForMe = 0;
    }

    double average = (double)sum / countOfTreasure;
    printf("\n\n平均獲得数: %lf\n\n", average);
    return 0;
}
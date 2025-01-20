#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <omp.h>
#include <math.h>

#include "define.h"
#include "simulate.h"

int main(void)
{
    char *data_file;
    FILE *fp;

    time_t start_time, end_time;
    time_t timer;
    struct tm *local;
    int year, month, day, hour, minute, second;

    timer = time(NULL);
    local = localtime(&timer);

    year = local->tm_year + 1900;
    month = local->tm_mon + 1;
    day = local->tm_mday;
    hour = local->tm_hour;
    minute = local->tm_min;
    second = local->tm_sec;

    printf("プログラム実行開始時刻：%d年%d月%d日 %d時%d分%d秒\n", year, month, day, hour, minute, second);

    start_time = time(NULL);

    data_file = "./result/probability.txt";
    fp = fopen(data_file, "w");
    fclose(fp);

    for (int i = 1; i <= max_n; i++)
    {
        double sum = 0.0;
        for (int k = 0; k < roop_count; k++)
        {
            srand(seed + k);

            double node_distance[i + 1];
            reset_node_distance(node_distance, i + 1);
        }
    }

    return 0;
}
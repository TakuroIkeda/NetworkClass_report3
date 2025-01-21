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

    // プログラム開始時刻を取得
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

    // 結果を保存するファイルを作成
    data_file = "./result/probability.txt";
    fp = fopen(data_file, "w");
    fclose(fp);

    // ノード数を1からmax_nまで増やしながらシミュレーションを実行
    for (int i = 1; i <= max_n; i++) // 添え字iは1からmax_nまで
    {
        int success_count = 0;
        for (int k = 0; k < roop_count; k++) // 添え字kは0からroop_count-1まで
        {
            srand(seed + k);

            double node[i + 1];
            double node_distance[i];

            set_node_positions(node, i + 1);
            sort_nodes(node, i + 1); // 新しい関数の呼び出しを追加
            calculate_node_distances(node, node_distance, i + 1);

            success_count += check_distance(node_distance, node, i);
        }
        output_probability(success_count, i);
    }

    end_time = time(NULL);

    // 実行時間を表示
    printf("実行計測時間：%lf min\n", (end_time - start_time) / 60.0);

    // プログラム終了時刻を取得
    timer = time(NULL);
    local = localtime(&timer);

    year = local->tm_year + 1900;
    month = local->tm_mon + 1;
    day = local->tm_mday;
    hour = local->tm_hour;
    minute = local->tm_min;
    second = local->tm_sec;

    printf("プログラム実行終了時刻：%d年%d月%d日 %d時%d分%d秒\n", year, month, day, hour, minute, second);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <omp.h>
#include <math.h>

#include "define.h"
#include "simulate.h"

// ノード間の距離をリセットする関数
void reset_node_distance(double *node_distance, int n)
{
    for (int i = 0; i < n; i++)
    {
        node_distance[i] = 0.0;
    }
}

// ノード間の距離を設定する関数
void set_distance(double *node_distance, int n)
{
    for (int i = 0; i < n; i++)
    {
        node_distance[i] = ((double)rand() / (double)RAND_MAX) * t;
    }
}

// ノードの位置を設定する関数
void set_node_positions(double *node, int n)
{
    for (int i = 0; i < n; i++)
    {
        node[i] = ((double)rand() / (double)RAND_MAX) * t;
    }
}

// ノード間の距離を計算する関数
void calculate_node_distances(double *node, double *node_distance, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        node_distance[i] = fabs(node[i + 1] - node[i]);
    }
}

// ノード間の距離が許容範囲内かチェックする関数
int check_distance(double *node_distance, double *node, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (node_distance[i] > d)
        {
            return 0;
        }
    }
    if (node[0] > d || (t - node[n - 1]) > d)
    {
        return 0;
    }
    return 1;
}

// 成功確率を出力する関数
void output_probability(int success_count, int i)
{
    char *data_file;
    FILE *fp;

    data_file = "./result/probability.txt";
    fp = fopen(data_file, "a");

    double calculate_probability = 0.0;
    for (int h = 0; h <= i + 1; h++)
    {
        double sigma = 0.0;
        sigma = pow(-1, h) * combination(i + 1, h);
        double max = 0.0;
        max = 1 - ((double)h * d / t);
        if (max < 0)
        {
            sigma *= 0;
        }
        else
        {
            sigma *= pow(max, i);
        }
        calculate_probability += sigma;
    }

    if (calculate_probability < 0)
    {
        calculate_probability = 0;
    }

    fprintf(fp, "%d\t%f\t%f\n", i, (double)success_count / (double)roop_count, calculate_probability);

    fclose(fp);
}

// ノードをソートする関数
void sort_nodes(double *node, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (node[j] > node[j + 1])
            {
                double temp = node[j];
                node[j] = node[j + 1];
                node[j + 1] = temp;
            }
        }
    }
}

// コンビネーションを計算する関数
unsigned long long combination(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    if (k > n)
        return 0;

    unsigned long long result = 1;
    for (int i = 1; i <= k; i++)
    {
        result *= n - (k - i);
        result /= i;
    }
    return result;
}
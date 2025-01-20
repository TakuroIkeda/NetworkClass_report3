#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <omp.h>
#include <math.h>

#include "define.h"
#include "simulate.h"

void reset_node_distance(double *node_distance, int n)
{
    for (int i = 0; i < n; i++)
    {
        node_distance[i] = 0.0;
    }
}

void set_distance(double *node_distance, int n)
{
    for (int i = 0; i < n; i++)
    {
        node_distance[i] = ((double)rand() / (double)RAND_MAX) * t;
    }
}

void set_node_positions(double *node, int n)
{
    for (int i = 0; i < n; i++)
    {
        node[i] = ((double)rand() / (double)RAND_MAX) * t;
    }
}

void calculate_node_distances(double *node, double *node_distance, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        node_distance[i] = fabs(node[i + 1] - node[i]);
    }
}

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

void output_probability(int success_count, int i)
{
    char *data_file;
    FILE *fp;

    data_file = "./result/probability.txt";
    fp = fopen(data_file, "a");

    fprintf(fp, "%d\t%f\n", i, (double)success_count / (double)roop_count);

    fclose(fp);
}

void sort_nodes(double *node, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (node[j] > node[j + 1]) {
                double temp = node[j];
                node[j] = node[j + 1];
                node[j + 1] = temp;
            }
        }
    }
}
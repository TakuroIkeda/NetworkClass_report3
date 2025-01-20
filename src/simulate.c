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
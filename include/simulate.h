#ifndef SIMULATE_H
#define SIMULATE_H

#include <define.h>

void reset_node_distance(double *node_distance, int n);

void set_distance(double *node_distance, int n);

int check_distance(double *node_distance, double *node, int n);

void output_probability(int success_count, int i);

void set_node_positions(double *node, int n);

void calculate_node_distances(double *node, double *node_distance, int n);

void sort_nodes(double *node, int n);

#endif
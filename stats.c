#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "stats.h"
#include "search.h"

int numberOfVertices(char name[])
{
	int a, b, c;
	int i;
	for (i = 0; i < MAXSIZE2; i++) {
		location[i] = -1;
	}
	freopen(name, "r", stdin);
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		if (location[a] == -1) {
			location[a] = num_point;
			num_point++;
		}
		if (location[b] == -1) {
			location[b] = num_point;
			num_point++;
		}
	}
	fclose(stdin);
	return num_point;
}

int numberOfEdges(char name[])
{
	int a, b, c;
	int sum = 0;
	freopen(name, "r", stdin);
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		sum++;
	}
	fclose(stdin);
	return sum;
}

float closenessCentrality(char name[], int node)
{
	creat_list(name);
	BFS(node);

	float total_dist = 0;
	float total_edges = 0;
	
	for (int i = 0; i < num_point; i++) {
		if (dist[i] != INF && dist[i] != 0) {
			total_dist += dist[i];
			total_edges++;
		}
	}

	return total_edges / total_dist;
}
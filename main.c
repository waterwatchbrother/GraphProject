#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "stats.h"
#include "search.h"

int main(int argc, char* argv[])
{
	if (argv[1][1] == 'h' || argv[1][2] == 'h') {
		printf("./search-cli -g/--graph FILE_PATH -s/--stats STATS_PARAMS: Output information of graph\n");
		printf("STATS_PARAMS can be: edges, vertices and closeness node(just like closeness 146)\n");
		printf("./search-cli -g/--graph FILE_PATH -sp/--shortestpath SEARCH_PARAMS -u STARTING_POINT -v TARGET_POINT: Calculate the shortest path from STARTING_POINT to TARGET_POINT using SEARCH_PARAMS\n");
		printf("SEARCH_PARAMS can be: DFS, BFS and Dijkstra.\n");
		printf("./search-cli -j: Print a picture of Mr.garlic.\n");
	}
	else if (argv[1][1] == 'j') {
		picture();
	}
	else if (argv[1][1] == 'g' || argv[1][2] == 'g') {
		if (argv[3][2] == 'p' || argv[3][3] == 'h') {
			printf("%s\n", shortestPath(atoi(argv[6]), atoi(argv[8]), argv[4], argv[2]));
			if (argv[4][0] == 'D' && argv[4][1] == 'F') {
				printf("cost:%d\n", cost_sh);
			}
			else {
				printf("cost:%d\n", dist[location[atoi(argv[8])]]);
			}
		}
		else {
			if (argv[4][0] == 'e') {
				printf("number of edges:%d\n", numberOfEdges(argv[2]));
			}
			else if (argv[4][0] == 'v') {
				printf("number of vertices:%d\n", numberOfVertices(argv[2]));
			}
			else {
				printf("closeness:%f\n", closenessCentrality(argv[2], atoi(argv[5])));
			}
		}
	}
	else {
		printf("No Command! You can input \"search-cli -h/--help\" to get help.\n");
	}
	Adj* p, * q;
	for (int i = 0; i < num_point; i++) {
		p = G[i].next;
		if (p == NULL) {
			continue;
		}
		q = p->next;
		while (q != NULL) {
			free(p);
			p = q;
			q = q->next;
		}
		free(p);
	}
	return 0;
}
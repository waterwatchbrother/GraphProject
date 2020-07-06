#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "search.h"

void DFS(int cost, int i, int t)
{
	sh_path[num_sh] = i;
	num_sh++;
	if (i == t) {
		cost_sh = cost;
		flag = 1;
		return;
	}
	Adj *p = G[location[i]].next;
	while (p != NULL) {
		if (visited[location[p->code]] == 0) {
			visited[location[p->code]] = 1;
			DFS(cost + p->weight, p->code, t);
			if (flag == 1) {
				return;
			}
		}
		p = p->next;
	}
	num_sh--;
}

void BFS(int start)
{
	int i;
	int tmp;
	Adj *p;
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	
	init(Q);
	for (i = 0; i < num_point; i++) {
		dist[i] = INF;
		sh_path[i] = start;
	}

	dist[location[start]] = 0;

	enqu(Q, start);
	while (!empty_qu(Q)) {
		tmp = dequ(Q);
		p = G[location[tmp]].next;
		while (p != NULL) {
			if (dist[location[p->code]] > dist[location[tmp]] + p->weight) {
				dist[location[p->code]] = dist[location[tmp]] + p->weight;
				sh_path[location[p->code]] = tmp;
				enqu(Q, p->code);
			}
			p = p->next;
		}
	}
	free(Q);
}

int get_weight(int start, int target)
{
	if (start == target) {
		return 0;
	}
	Adj *p = G[location[start]].next;
	while (p != NULL) {
		if (p->code == target) {
			return p->weight;
		}
		p = p->next;
	}
	return INF;
}

void Dijkstra(int start, int target)
{
	int i;
	int j;
	int t;
	int min;
	int tmp;

	for (i = 0; i < num_point; i++) {
		dist[i] = get_weight(start, G[i].code);
		sh_path[i] = start;
	}

	t = start;
	Adj *p;
	for (i = 0; i < num_point; i++) {
		if (visited[location[target]] == 1) {
			return;
		}
		min = INF;
		for (j = 0; j < num_point; j++) {
			if (visited[j] == 0 && dist[j] < min) {
				min = dist[j];
				t = j;
			}
		}

		visited[t] = 1;

		p = G[t].next;
		while (p != NULL) {
			tmp = min + p->weight;
			if (visited[location[p->code]] == 0 && dist[location[p->code]] > tmp) {
				dist[location[p->code]] = tmp;
				sh_path[location[p->code]] = G[t].code;
			}
			p = p->next;
		}
	}
}

char* shortestPath(int u, int v, char algorithm[], char name[])
{
	int i;
	creat_list(name);
	char *a = "->";
	char tmp[20];
	for (i = 0; i < MAXSIZE1; i++) {
		path[i] = '\0';
	}
	if (algorithm[0] == 'D' && algorithm[1] == 'F') {
		DFS(0, u, v);
		if (flag == 0) {
			printf("No path from %d to %d.\n", u, v);
			exit(0);
		}
		for (i = 0; i < num_sh; i++) {
			sprintf(tmp, "%d", sh_path[i]);
			self_strcat(path, tmp);
			if (i != num_sh - 1) {
				self_strcat(path, a);
			}
		}
	} else {
		if (algorithm[0] == 'B') {
			BFS(u);
		} else {
			Dijkstra(u, v);
		}
		if (dist[location[v]] == INF) {
			printf("No path from %d to %d.\n", u, v);
			exit(0);
		}
		int  j;
		for (i = 0; i < MAXSIZE1; i++) {
			for (j = 0; j < 20; j++) {
				sh_point[i][j] = '\0';
			}
		}
		sprintf(tmp, "%d", v);
		self_strcat(sh_point[0], tmp);
		i = v;
		j = 1;
		while (i != u) {
			sprintf(tmp, "%d", sh_path[location[i]]);
			self_strcat(sh_point[j], tmp);
			i = sh_path[location[i]];
			j++;
		}
		j--;
		for (j = j; j >= 0; j--) {
			self_strcat(path, sh_point[j]);
			if (j != 0) {
				self_strcat(path, a);
			}
		}
	}
	return path;
}

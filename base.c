#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "stats.h"
#include "search.h"

void creat_list(char name[])
{
	int i;
	int point1;
	int point2;
	int weight;
	Adj* s;
	for (i = 0; i < MAXSIZE1; i++) {
		G[i].next = NULL;
	}
	for (i = 0; i < MAXSIZE2; i++) {
		location[i] = -1;
	}
	freopen(name, "r", stdin);
	while (scanf("%d %d %d", &point1, &point2, &weight) != EOF) {
		if (location[point1] == -1) {
			G[num_point].code = point1;
			location[point1] = num_point;
			num_point++;
		}
		s = (Adj*)malloc(sizeof(Adj));
		s->code = point2;
		s->weight = weight;
		s->next = G[location[point1]].next;
		G[location[point1]].next = s;
		if (location[point2] == -1) {
			G[num_point].code = point2;
			location[point2] = num_point;
			num_point++;
		}
	}
	fclose(stdin);
}

void init(Queue* Q)
{
	Q->rear = -1;
	Q->front = -1;
}

void enqu(Queue* Q, int code)
{
	Q->rear++;
	Q->data[Q->rear] = code;
}

int dequ(Queue* Q)
{
	Q->front++;
	return Q->data[Q->front];
}

int empty_qu(Queue* Q)
{
	if (Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void picture()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@00..0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@00..0000\.00@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@\\@@@@@@@@@0.,0@@@@@@@@0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@.|@@@@@@@0.,0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@.||..0@@0..0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@,.,@@@''@@@00.   00@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@ .  . . @@@@. .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@.        @@ .  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@.          @    .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@.          @    .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@.           .      .@@@@@@@@@@@@@@@__@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@.                     .@@@@@@@@@@@@/  \@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@.                         .@@@@@@@@@/  | \@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@.          __        __         .@@@@/  /@\ \@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@.          /  \      /  \           ./  /@@@\  \@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@.           . \__/      \__/            .  @@@@ \  \@@@@@@@@@\n");
	printf("@@@@@@@@@@@.           .                            .@@@@@@     @@@@@@@@@\n");
	printf("@@@@@@@@@@@@.          .                            .@@@@@@       @@@@@@@\n");
	printf("@@@@@@@@@@@/  .           .                         .@@@@@@@@@    @@@@@@@\n");
	printf("@@@@@@@@@@/ \           .   \________/           /@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@/  /@@@\.           .                   .@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@/  |@@@@@\.           .               ./@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@/  /@@@@| .           .            .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@/  /@@@@@@|.           .         .\   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@       @@@@@@|  /@.           .      .@@@\  |@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@     @@@@@@/  /@.           .      .@@@@\  \.@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@/  /@@@@@@@@@@@@@@@@@@@@@@@@@@@\  \.@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@/  /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|  |.@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@|  |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\ \@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@______/  |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|  |_____@@@@@@@@@@@@@@\n");
	printf("@@@@@@@|         |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|        |@@@@@@@@@@@@@\n");
	printf("@@@@@@@@\_______|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@________|@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

char* self_strcat(char* str, char* str2)
{
	char *str1 = str;
	while (*str1 != '\0') {
		str1++;
	}
	while (*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str;
}
/*
int main()
{
	int  u;
	int  v;
	char name[150];
	scanf("%s", name);
	//scanf("%d", &u);
	//printf("closeness centrality:%f\n",closenessCentrality(name, u));
	scanf("%d %d", &u, &v);
	//printf("%d %d", numberOfVertices(name), numberOfEdges(name));
	char way[10];
	scanf("%s", way);
	//creat_list(name);
	printf("%s\n", shortestPath(u, v, way, name));
	printf("cost:%d\n", dist[location[v]]);
	system("pause");
	//BFS(u);
	//printf("cost:%d\n", dist[location[v]]);
	/*visited[location[u]] = 1;
	Dijkstra(u, v);
	int i = v;
	printf("%d<-", v);
	while (i != u) {
		if (sh_path[location[i]] != u) {
			printf("%d<-", sh_path[location[i]]);
		}
		else {
			printf("%d\n", sh_path[location[i]]);
		}
		i = sh_path[location[i]];
	}
	printf("cost:%d\n", dist[location[v]]);
	/*DFS(0, 2, 34372);
	for (int i = 0; i < num_sh; i++) {
		if (i == num_sh - 1) {
			printf("%d\n", sh_path[i]);
		}
		else {
			printf("%d->", sh_path[i]);
		}
	}
	printf("cost:%d", cost_sh);
	Adj* p, *q;
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
}*/
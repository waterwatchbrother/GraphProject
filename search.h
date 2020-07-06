#ifndef __SEARCH_H__
#define __SEARCH_H__

void DFS(int cost, int i, int t);
void BFS(int start);
int get_weight(int start, int target);
void Dijkstra(int start, int target);
char* shortestPath(int u, int v, char algorithm[], char name[]);

#endif
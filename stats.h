#ifndef __STATS_H__
#define __STATS_H__

int numberOfEdges(char name[]);
int numberOfVertices(char name[]);
//float freemanNetworkCentrality(char name[]);
float closenessCentrality(char name[], int node);

#endif
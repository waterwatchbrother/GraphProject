#ifndef __BASE_H__
#define __BASE_H__

#define MAXSIZE1 2800000
#define MAXSIZE2 10000000
#define INF 0x3f3f3f3f

typedef struct AdjPoint {
	int code;
	int weight;
	struct AdjPoint* next;
} Adj;

typedef struct {
	int  code;
	Adj* next;
} Graph;

typedef struct {
	int  rear;
	int  front;
	int data[MAXSIZE1];
} Queue;

Graph G[MAXSIZE1];
int location[MAXSIZE2];
int num_point;
int visited[MAXSIZE1];
int sh_path[MAXSIZE1];
int dist[MAXSIZE1];
int num_sh;
int cost_sh;
int flag;
char path[MAXSIZE1];
char sh_point[MAXSIZE1][20];

void creat_list(char name[]);
void init(Queue* Q);
void enqu(Queue* Q, int code);
int dequ(Queue* Q);
int empty_qu(Queue* Q);
void picture();
char* self_strcat(char* str1, char* str2);

#endif

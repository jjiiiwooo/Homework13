#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 10000000

typedef struct GraphType {
	int n; //정점의 개수 
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];
//int path[MAX_VERTICES][MAX_VERTICES];


                      //start // end
void floyd(GraphType* g, int i, int j)
{
	int  k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];

	// k = 거쳐가는 노드 
	for (k = 0; k < g->n; k++) {
		//i = 출발 노드 
		for (i = 0; i < g->n; j++)
			//j = 도착 노드 
			for (j = 0; j < g->n; j++)
				if (A[i][k] + A[i][k] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
				}
	}
	printf("%d", A[i][j]);

}

int main(void) {

	int start, end;

	GraphType g = { 11,
		{{0,3,INF,INF,INF,11,12,INF,INF,INF},
		{3,0,5,4,1,7,8,INF,INF,INF},
		{INF,5,0,2,INF,INF,6,5,INF,INF},
		{INF,4,2,0,13,INF,INF,14,INF,16},
		{INF,1,INF,13,0,9,INF,INF,18,17},
		{11,7,INF,INF,9,0,INF,INF,INF,INF},
		{12,8,6,INF,INF,INF,0,13,INF,INF},
		{INF,INF,5,14,INF,INF,13,0,INF,15},
		{INF,INF,INF,INF,18,INF,INF,INF,0,10},
		{INF,INF,INF,16,17,INF,INF,15,10,0} }
	};

	printf("Floyd-Warshall Algorithm\n");
	printf("Start Node:\n");
	scanf_s("%d", &start);

	printf("End Node:\n");
	scanf_s("%d", &end);

	printf("Shortest Distance:\n");
	floyd(&g, start, end);
	
}


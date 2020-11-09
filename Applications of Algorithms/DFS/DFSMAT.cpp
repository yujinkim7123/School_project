#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define Q_SIZE 20

typedef struct {
	int vertexNum; // 정점의 개수
	int** adjMatrix; // 인접행렬
}Graph;

int* visited;

void AddEdge(Graph * graph, int start, int end) {

	graph->adjMatrix[start][end] = 1;
	graph->adjMatrix[end][start] = 1;

}

void printGraph(Graph* graph) {

	for (int i = 1; i <= graph->vertexNum; i++) {
		for (int j = 1; j <= graph->vertexNum; j++)
			printf("%d ", graph->adjMatrix[i][j]);
		printf("\n");
	}

}


Graph* NewGraph(int vNum) {

	Graph*graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexNum = vNum;
	graph->adjMatrix = (int**)malloc(sizeof(int*) * (vNum + 1));
	for (int i = 0; i <= vNum; i++) {
		graph->adjMatrix[i] = (int*)malloc(sizeof(int) * (vNum + 1));
		memset(graph->adjMatrix[i], 0, sizeof(int) * (vNum + 1));
	}
	visited = (int*)malloc(sizeof(int) * (vNum + 1));
	return graph;

}

void aDFS_Mat(Graph* g, int v) {

	visited[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= g->vertexNum; i++) {
		if (g->adjMatrix[v][i] == true && visited[i] == false) {
			aDFS_Mat(g, i);
			
		}
	}
 }


void DFS_Mat(Graph* g) {

	for (int i = 1; i <= g->vertexNum; i++)
	{
	   visited[i] = false;
	}

	for (int i = 1; i <= g->vertexNum; i++) {
		if (visited[i] == false)
			aDFS_Mat(g, i);
	}
}




int main() {
	Graph* g = NewGraph(8);
	AddEdge(g, 1, 2);
	AddEdge(g, 1, 3);
	AddEdge(g, 2, 4);
	AddEdge(g, 2, 5);
	AddEdge(g, 3, 5);
	AddEdge(g, 3, 7);
	AddEdge(g, 3, 8);
	AddEdge(g, 4, 5);
	AddEdge(g, 5, 6);
	AddEdge(g, 7, 8);
	printGraph(g);
	printf("\nDFS: ");
	DFS_Mat(g);
}

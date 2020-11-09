#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define Q_SIZE 20

typedef struct {
	int vertexNum; // 정점의 개수
	int** adjMatrix; // 인접행렬
}Graph;

typedef struct
{   int queue[Q_SIZE];
	int front, rear;
}QueueType;

int* visited;

void AddEdge(Graph * graph, int start, int end) {
	graph->adjMatrix[start][end] = 1;
	graph->adjMatrix[end][start] = 1;
}void printGraph(Graph* graph) {
	for (int i = 1; i <= graph->vertexNum; i++) {
		for (int j = 1; j <= graph->vertexNum; j++)
			printf("%d ", graph->adjMatrix[i][j]);
		printf("\n");
	}
}

int isEmpty(QueueType* Q) {
	if
		(Q->front == Q->rear) {
		return 1;
	}
	else
		return 0;
}int isFull(QueueType* Q) {
	if ((Q->rear + 1) % Q_SIZE == Q->front % Q_SIZE) {
		return 1;
	}
	else return 0;
}


Graph* NewGraph(int vNum) {
	Graph*graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexNum = vNum;
	graph->adjMatrix = (int**)malloc(sizeof(int*) * (vNum+1));
	for (int i = 0; i <= vNum; i++) {
		graph->adjMatrix[i] = (int*)malloc(sizeof(int) * (vNum+1));
		memset(graph->adjMatrix[i], 0, sizeof(int) * (vNum+1));
	}
	visited = (int*)malloc(sizeof(int) * (vNum+1));
	return graph;
}


int deQueue(QueueType* Q) {
	if (isEmpty(Q))
		return -1;
	else {
		Q->front = (Q->front + 1) % Q_SIZE;
		return Q->queue[Q->front];
	}
}
void enQueue(QueueType* Q, int item) {
	if (isFull(Q)) return;
	else {
		Q->rear = (Q->rear + 1) % Q_SIZE;
		Q->queue[Q->rear] = item;
	}
}

QueueType * createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}


void BFS_Mat(Graph* g, int s) {
	QueueType* BFS_Q = createQueue();
	
	for (int i = s; i <= g->vertexNum; i++)
		visited[i] = 0;

	visited[s] = true;
	enQueue(BFS_Q, s);

	while (!isEmpty(BFS_Q)) {
		int u;
		u = deQueue(BFS_Q);
		printf("%d ", u);
		for (int i = s; i <= g->vertexNum; i++) {
			if (g->adjMatrix[u][i] == true && visited[i] == false) {
				visited[i] = true;
				enQueue(BFS_Q, i);
			}
		}
	}
	


	free(BFS_Q);
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
	printf("\nBFS: ");
    BFS_Mat(g, 1);
}
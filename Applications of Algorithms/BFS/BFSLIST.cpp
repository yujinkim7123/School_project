#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 20

typedef struct node {
	int vertex; // 정점의 번호
	struct node* next;
} Node;

typedef struct {
	int vertexNum; // 정점의 개수
	Node**adjList; // 인접리스트
} Graph;

typedef struct
{
	int queue[Q_SIZE];
	int front, rear;
}QueueType;

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

int deQueue(QueueType* Q) {
	if (isEmpty(Q))
		return -1;
	else {
		Q->front = (Q->front + 1) % Q_SIZE;
		return Q->queue[Q->front];
	}
}
void enQueue(QueueType * Q, int item) {
	if (isFull(Q)) return;
	else {
		Q->rear = (Q->rear + 1) % Q_SIZE;
		Q->queue[Q->rear] = item;
	}
}

QueueType* createQueue() {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
void AddEdge(Graph*g, int start, int end) {
Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = end;
	newNode->next = g->adjList[start];
	g-> adjList[start] = newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = start;
	newNode->next =g-> adjList[end];
	g-> adjList[end] = newNode;
}

void printGraph(Graph* graph) {
	Node* p;
	for(int i = 1; i <= graph->vertexNum; i++) {
		p = graph-> adjList[i];
		printf("%d: ",i);
		while (p != NULL) {
			printf("%d ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}

int* visited;
Graph* NewGraph(int vNum) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertexNum = vNum;
	graph->adjList = (Node * *)malloc(sizeof(Node*) * (vNum + 1));
	for (int i = 0; i <= vNum; i++)
		graph->adjList[i] = NULL;

	visited = (int*)malloc(sizeof(int) * (vNum + 1));
	
	return graph;
}
void BFS_List(Graph * g, int s) {
	QueueType* BFS_Q = createQueue();

	for (int i = s; i <= g->vertexNum; i++)
		visited[i] = 0;

	visited[s] = true;
	enQueue(BFS_Q, s);

	while (!isEmpty(BFS_Q)) {
		int u;
		u = deQueue(BFS_Q);
		printf("%d ", u);
		int num;
		node *NEXT;
		NEXT = g->adjList[u];
		for (int i = s; NEXT != NULL; i++) {
			num = NEXT->vertex;
			if (visited[num] == false) {
				visited[num] = true;
				enQueue(BFS_Q, num);
			}
			NEXT = NEXT->next;
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
	printf
	("\nBFS: ");
	BFS_List(g, 1);
}
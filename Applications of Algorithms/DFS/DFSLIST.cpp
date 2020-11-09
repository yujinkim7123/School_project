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

void AddEdge(Graph*g, int start, int end) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = end;
	newNode->next = g->adjList[start];
	g->adjList[start] = newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = start;
	newNode->next = g->adjList[end];
	g->adjList[end] = newNode;
}

void printGraph(Graph* graph) {
	Node* p;
	for (int i = 1; i <= graph->vertexNum; i++) {
		p = graph->adjList[i];
		printf("%d: ", i);
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


void aDFS_List(Graph *g, int v) 
{
	visited[v] = true;
	printf("%d ", v);
	node *NEXT; int num = 0;
	NEXT = g->adjList[v];
	for (int i = 1; NEXT != NULL; i++) {
		num = NEXT->vertex;
		if (visited[num] == false) {
			visited[num] = true;
			aDFS_List(g, num);
		}
		NEXT = NEXT->next;
	}
	
}
	void DFS_List(Graph *g) 
	{
		for (int i = 1; i <= g->vertexNum; i++)
		{
			visited[i] = false;
		}
		for (int i = 1; i <= g->vertexNum; i++) {
			if (visited[i] == false)
				aDFS_List(g, i);
		}
	}

int main() {
	Graph *g = NewGraph(8);
			
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
	DFS_List(g);
		}

#include <iostream> 
#include <vector> 
using namespace std;

int n, m; //n : vertex(정점)의 개수, m : edge(간선)의 개수 
int s, e; //s : start(시작정점), e : end(끝정점) 

vector<vector<int>> adjArray; //vector-vector를 선언
vector<bool> visited;


void AddEdge(int start, int end) { 
	adjArray[start].push_back(end); 
	adjArray[end].push_back(start); 
}
void printGraph() {
	for (int i = 1; i <= n; i++) {
		cout << i << ":  "; 
		for (int j = 0; j < adjArray[i].size(); j++) 
			cout << adjArray[i][j] << "  ";
		cout << endl;
	}
}

void aDFS_List(vector<vector<int>> g, int v)
{
	visited[v] = true;
    printf("%d ", v);
	int num;
	for (int i = 0;  i < g[v].size();  i++) {
		
		num = g[v][i];
	
		if (visited[num] == false) {
			visited[num] = true;
			aDFS_List(g, num);

		}
	}
}
void DFS_List(vector<vector<int>> g)
{
	
	for (int i = 1; i <= n; i++)
	{
		
		visited[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false)

			aDFS_List(g, i);
	}
}

int main() {
	cin >> n >> m;

	adjArray.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		AddEdge(s, e);
	}

	printGraph();
	printf("\nDFS: ");

	DFS_List(adjArray);

}


#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

int n, m; //n : vertex(����)�� ����, m : edge(����)�� ���� 
int s, e; //s : start(��������), e : end(������) 

vector<vector<int>> adjArray; //vector-vector�� ����
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
	for (int i = 0; i < g[v].size(); i++) {

		num = adjArray[v][i];

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

void BFS_List(vector<vector<int>> g, int s) {
	queue<int> BFS_Q;

	for (int i = s; i <= n; i++)
		visited[i] = 0;

	visited[s] = true;
	BFS_Q.push(s);

	while (!BFS_Q.empty()) {
		int u;
		u = BFS_Q.front();
		BFS_Q.pop();
		printf("%d ", u);
		int num;
		for (int i = 0; i < g[u].size(); i++) {

			num = g[u][i];

			if (visited[num] == false) {
				visited[num] = true;
				BFS_Q.push(num);
			}
		}
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
	printf("\nBFS: ");

	BFS_List(adjArray, 1);

}

  
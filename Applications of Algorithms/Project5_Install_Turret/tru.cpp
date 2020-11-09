#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

int n, m; //n : vertex(정점)의 개수, m : edge(간선)의 개수 
int s, e; //s : start(시작정점), e : end(끝정점) 

vector<vector<int>> adjArray; //vector-vector를 선언
vector<bool> visited;
vector<int> TUR;


void AddEdge(int start, int end) {

	adjArray[start].push_back(end);

}

int  turret;

void aDFS_List(vector<vector<int>> g, int v)
{
	queue<int> BFS_Q;
   
	visited[v] = true;
	BFS_Q.push(v);
	turret++;
	while (!BFS_Q.empty()) {
		int u;
		u = BFS_Q.front();
		BFS_Q.pop();
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
int DFS_List(vector<vector<int>> g)
{
	turret = 0;

	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false)

			aDFS_List(g, i);

	}

	return turret;
}



int main() {
	int T;

	cin >> T;


	for (int i = 0; i < T; i++) {
	
		cin >> n >> m;

		adjArray.resize(n + 1);
		visited.resize(n + 1);

		for (int j = 0; j < m; j++)
		{
			cin >> s >> e;
			AddEdge(s, e);
		}

		TUR.push_back(DFS_List(adjArray));
		adjArray.clear();
		visited.clear();
	 }

   
	for (int i = 0; i < TUR.size(); i++) {

		printf("%d\n", TUR[i]);

	}
	
}

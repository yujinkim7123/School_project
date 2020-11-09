#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std;

#define INF INT_MAX

typedef struct { int vertex; int weight; } Node;

int n, m; int s, e, w;

vector<vector<Node>> adjArray;
vector<bool> selected;
vector<int> d;
vector<int> pre;

void Make_Set(int x) { pre[x] = x; }

void Dij(int s) {

	for (int i = 1; i <= n; i++)
		Make_Set(i);

	int numSelectedNode = 0;
	int u;

	d[s] = 0; 
	
	unsigned int min;
	
	while (numSelectedNode < n) {
		
		min = INF;

		for (int j = 1; j <= n; j++) {
			if (selected[j] == false && min > d[j])
			{

				min = d[j];
				u = j;
			}
		}

		selected[u] = true;
		numSelectedNode++;

		for (int j = 0; j < adjArray[u].size(); j++) {
			int v = adjArray[u][j].vertex;
			int w = adjArray[u][j].weight;

	       if(selected[v] == false && d[u] + w < d[v]){
				d[v] = w + d[u]; 
				pre[v] = u;
			}
		}
	}
}


int main() {
	cin >> n >> m;
	adjArray.resize(n + 1);
	selected.resize(n + 1, false);
	d.resize(n + 1, INF);
	pre.resize(n + 1, -1);

	Node node;

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		node.vertex = e;
		node.weight = w;
		adjArray[s].push_back(node);
	}

	Dij(1);

	cout << "[Dijkstra] Shorttest Path from Vertex 1" << endl;
	   stack<int> s;
		for (int i = 1; i <= n; i++) {

			cout << i << ": ";
			int x = i;
			s.push(x);

			for (int j = 0; pre[x] != x; j++) {

				s.push(pre[x]);
				x = pre[x];
			}


			for (int k = 0; s.empty() != 1; k++) {
				cout << s.top() << " ";
				s.pop();
			}

			cout << "(" << "distance: " << d[i] << ")" << endl;

		}

	

}

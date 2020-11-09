#include <iostream> 
#include <vector> 
#include <queue> 
#include<string>
using namespace std;

#define INF INT_MAX
typedef struct { int vertex; int weight; } Node;
bool operator>(Node a, Node b) { return (a.weight > b.weight); }
priority_queue<Node, vector<Node>, greater<Node>> minHeap;
int n, m; 
vector<vector<Node>> adjArray;
vector<bool> selected;
vector<int> d;
vector<int> pre;
vector<int> cost;

void Prim(int s) {
	int numSelectedNode = 0;
	Node node;
	d[s] = 0; 
	node.vertex = s;
	node.weight = 0;

	minHeap.push(node);

	while (numSelectedNode < n) {

		int u = minHeap.top().vertex;

		minHeap.pop();

		if (selected[u] == true)
			continue;
		
		selected[u] = true;

		numSelectedNode++;

		for (int j = 0; j < adjArray[u].size(); j++) {
			int v = adjArray[u][j].vertex;
			int w = adjArray[u][j].weight;
			if (selected[v] == false && w < d[v])
			{
				d[v] = w; pre[v] = u;
				node.vertex = v;
				node.weight = w;
				minHeap.push(node);

			}
		}
	}
}


int main() {
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cin.ignore();
		adjArray.resize(n + 1);
		selected.resize(n + 1, false);
		d.resize(n + 1, INF);
		pre.resize(n + 1, -1);

		Node node;
		string sew;

		for (int i = 0; i < n; i++) {

			getline(cin, sew);

			string str;
			int nu = 0;
			for (int j = 0; sew[j] != '\0'; j++) {

				if (48 <= sew.at(j) && sew.at(j) <= 57) {
					char str1 = sew.at(j);
					str = str + str1;
				}
				else {
					int rel = 0;

					rel = stoi(str);

					nu++;
					node.vertex = nu;
					node.weight = rel;
					adjArray[i + 1].push_back(node);

					str.clear();
				}

			}

			int rel = 0;
			rel = stoi(str);
			nu++;
			node.vertex = nu;
			node.weight = rel;
			adjArray[i + 1].push_back(node);
			str.clear();

			cin.clear();
		}
		
		Prim(1);

		int cost1 = 0;
		for (int i = 1; i <= n; i++)
			cost1 += d[i];

		cost.push_back(cost1);

		adjArray.clear();
		selected.clear();
		d.clear();
		pre.clear();
		priority_queue<Node, vector<Node>, greater<Node>> empty;
		swap(minHeap, empty);

		
	}

	for (int i = 0; i < cost.size(); i++)
		cout << cost[i] << endl;

}
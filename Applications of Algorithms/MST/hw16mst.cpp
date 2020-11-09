#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

#define INF INT_MAX
typedef struct { int vertex; int weight; } Node;
typedef struct { int start; int end; int weight; } Edge;

bool operator > (Edge a, Edge b) { 
	return (a.weight > b.weight); 
}

bool operator>(Node a, Node b) 
{ 
	return (a.weight > b.weight);
}


priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
priority_queue<Node, vector<Node>, greater<Node>> minHeap2;

int n, m;
int s, e, w;
vector<int> p;
vector<int> ranks;
vector<Edge> result;

vector<vector<Node>> adjArray;
vector<bool> selected;
vector<int> d;
vector<int> pre;


void Make_Set(int x) { p[x] = x; ranks[x] = 0; }
int Find_Set(int x) {
	if (p[x] != x) p[x] = Find_Set(p[x]);
	return p[x];
}
void Union(int x, int y) {
	int x1 = Find_Set(x); int y1 = Find_Set(y);
	if (ranks[x1] > ranks[y1]) p[y1] = x1;
	else {
		p[x1] = y1; if (ranks[x1] == ranks[y1])
			ranks[y1] = ranks[y1] + 1;
	}
}

void Kruskal() {
	for (int i = 1; i <= n; i++)
		Make_Set(i);

	while (result.size() < n - 1) {
		int start = minHeap.top().start;
		int end = minHeap.top().end;

		if (Find_Set(start) != Find_Set(end))
		{
			Union(start, end);
			result.push_back(minHeap.top());
		}
		minHeap.pop();
	}
}

void Prim(int s) {
	int numSelectedNode = 0;
	Node node;
	d[s] = 0; node.vertex = s;
	node.weight = 0;
	minHeap2.push(node);
	while (numSelectedNode < n) {
		int u = minHeap2.top().vertex;
		minHeap2.pop();
		if (selected[u] == true)
			continue;
		selected[u] = true;
		numSelectedNode++;
		cout << u << "," << pre[u] << "(" << d[u] << ")" << endl;

		for (int j = 0; j < adjArray[u].size(); j++) {
			int v = adjArray[u][j].vertex;
			int w = adjArray[u][j].weight;
			if (selected[v] == false && w < d[v])
			{
				d[v] = w; pre[v] = u;
				node.vertex = v;
				node.weight = w;
				minHeap2.push(node);

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
	p.resize(n + 1);
	ranks.resize(n + 1);
	Node node;
	Edge edge;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		node.vertex = e;
		node.weight = w;
		adjArray[s].push_back(node);
		node.vertex = s;
		node.weight = w;
		adjArray[e].push_back(node);
		edge.start = s;
		edge.end = e;
		edge.weight = w;
		minHeap.push(edge);
	}
	Prim(1);
	int cost1 = 0;
	for (int i = 1; i <= n; i++)
		cost1 += d[i];
	cout << "Total Cost: " << cost1 << endl;
	Kruskal();
	int cost2 = 0;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].start << ',' << result[i].end << '(' << result[i].weight << ')' << endl;
		cost2 += result[i].weight;
	}
	cout << "Total Cost: " << cost2;




}
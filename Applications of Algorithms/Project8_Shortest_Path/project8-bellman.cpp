#include <iostream> 
#include <vector> 
#include <stack>
using namespace std;

#define INF INT_MAX

typedef struct { 

	int start; 
	int end; 
	int weight; 
    
} eage;

int n, m; 
int s, e, w;
vector<eage> ea;
vector<int> d;
vector<int> pre;
bool cycle = false;

void Make_Set(int x) { pre[x] = x; }

void Bell(int s) {
	
	for (int i = 1; i <= n; i++)
		Make_Set(i);

	d[s] = 0; 	

	for(int j = 0; j < n; j++){
		
		for(int i = 0; i < m; i++){

			int u = ea[i].start;
			int now = ea[i].end;
			int we = ea[i].weight;
			
			if (d[u] != INF && (d[u] + we) < d[now])
			{
				d[now] = d[u] + we; 
				pre[now] = u;

				if (j == n - 1) {
					cycle = true;
				}

			}

		}
	}
}


int main() {
	cin >> n >> m;
	
	d.resize(n + 1, INF);
	pre.resize(n + 1, -1);
	ea.resize(m);

	eage ee;

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		ee.start = s;
		ee.end = e;
		ee.weight = w;
		ea[i] = ee;
	}

	Bell(1);
	
	stack<int> s;
	cout << "[Bellman-Ford] Shorttest Path from Vertex 1" << endl;
	if (cycle != true) {
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

}

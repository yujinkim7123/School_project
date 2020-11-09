#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector> 
#include <queue> 
#include<string>
using namespace std;

int m;
vector<vector<int>> adjArray; //vector-vector를 선언 
vector<int> inDeg; // 진입간선 수 
queue<int> q; // 진입간선이 0인 정점을 저장하는 큐 
vector<int> work;
vector<int> rel;
vector<int> rell;



void AddEdge(int start, int end)
{
	adjArray[start].push_back(end);
}


void topologicalSort1() {

	for (int i = 1; i <= m; i++) {
		if (inDeg[i] == 0) {
			// 진입간선이 0이면 q에 enqueue 
			q.push(i);
			rel[i] = work[i];
		}
	}
	
	while (q.empty() == 0 ) {
		int u = q.front();

		q.pop();

		for (int j = 0; j < adjArray[u].size(); j++)

		{

			int v = adjArray[u][j];
			inDeg[v]--;

			rel[v] = rel[u] + work[v];

			if (inDeg[v] == 0)
				q.push(v);

		}
	}
}

int main() {
	int T;
	string n;

	cin >> T;


	for (int i = 0; i < T; i++)

	{
		cin >> m;
		cin.ignore();

		adjArray.resize(m + 1);
		inDeg.resize(m + 1, 0);
		work.resize(m + 1, 0);
		rel.resize(m + 1, 0);

		for (int k = 0; k < m; k++) {

			getline(cin, n);

			int i = 0;
			string str;
			
			for (int j = 0; n[j] != '\0'; j++) {

				int rel = 0;

				if (48 <= n.at(j) && n.at(j) <= 57) {
					char str1 = n.at(j);
					str = str + str1;
				}


				else{			
					rel = stoi(str);
				
					if (rel != 0) {
						if (i == 0)
							work[k + 1] = rel;

						else {
							
							AddEdge(rel, k + 1);
							inDeg[k + 1]++;
						}
					}
					i++;
					str.clear();
				}
			}
			cin.clear();
		}

		topologicalSort1();

		for (int j = 1; j < rel.size(); j++)

			rell.push_back(rel[j]);

		adjArray.clear();
		inDeg.clear();
		work.clear();
		rel.clear();
	}

	
	for (int j = 1; j < rell.size(); j++) {
		cout << rell[j] << " ";
		cout << endl;
	}

	rel.clear();
	

}
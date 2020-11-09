#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std;
int n, m; 
int s, e;
vector<vector<int>> adjArray;
vector<bool> visited;
stack<int> R;

void AddEdge(int start, int end) { 
	adjArray[start].push_back(end); 
}


char IoT_Class[][30] = { 
"IoT����", "���ʼ���", 
"C���α׷���", "������Ű���", "��ȸ��", 
"��������ȸ��", "�ڷᱸ��", "�˰���", 
"�Ӻ����ý��۱���", "��ǻ�ͳ�Ʈ��ũ", 
"IoT�÷���", "�ü��", "����ũ�����μ���", "ĸ���������" };


void DFS_TS(int v) { 

	visited[v] = true;

	for (int i = 0; i < adjArray[v].size(); i++) {
		int u;
		u = adjArray[v][i];
		if (visited[u] == false) {
			DFS_TS(u);
		}
	}

	R.push(v);

}
void topologicalSort2() {  

	for (int i = 1; i <= n; i++) {

		visited[i] = false;
	
	}

	for (int i = 1; i <= n; i++) {

		if (visited[i] == false) {
			DFS_TS(i);
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
	
	topologicalSort2();

	while (R.size())
	{ 
	cout << IoT_Class[R.top() - 1] << " "; 
	R.pop(); 
	if (R.size() != 0) cout << " --> ";
	}

}

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
#include <algorithm>
#include<set>
using namespace std;

int concat(const vector<int>& lengths) {
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < lengths.size(); i++) {
		pq.push(lengths[i]);
	}
	int ret = 0;
	while (pq.size() > 1) {
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		ret += (min1 + min2);
	}
	return ret;
}


int main(void) {
	int cases;
	int j = 0;
	cin >> cases;
	vector<int> arr1(cases);
	while (cases--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		arr1[j++] = concat(arr);
	}

	for (int i = 0; i < j; i++)
		cout << arr1[i] << endl;


	return 0;
}

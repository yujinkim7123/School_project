#include<iostream>
using namespace std;

int main() {
	int *p = new int[5];
	float average = 0;
	cout << "���� 5�� �Է�>>";
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
		average += p[i];
	}
	average = average / 5;
	cout << "��� " << average;

	delete[] p;
}
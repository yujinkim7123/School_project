#include <iostream>
#include <string>
using namespace std;

int main() {
	char a[100];
	int i;
	int j = 0;
	cin.getline(a, 100, '\n');
	for (i = 0; a[i] != 0; i++) {
		if (a[i]=='x') {
			j++;
		}
	}
	cout << "x의 개수는" << " " << j;

}
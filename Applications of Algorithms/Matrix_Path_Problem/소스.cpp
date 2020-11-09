#include<iostream>
#include <algorithm>
#include<ctime>
using namespace std;

int** m;
int** L;

int mat(int i, int j) {
	if (i == 1 && j == 1) {
		return m[i][j];
	}
	else if (i == 1) {
		return mat(i, j - 1) + m[i][j];
	}
	else if (j == 1) {
		return mat(i - 1, j) + m[i][j];;
	}
	else {
		return min(mat(i - 1, j), mat(i, j - 1)) + m[i][j];;
	}
}


int mat1(int i, int j) {

	if (L[i][j] != -1)
		return L[i][j];

	if (i == 1 && j == 1)
		L[i][j] = m[i][j];

	else if (i == 1)
		L[i][j] = mat1(i, j - 1) + m[i][j];

	else if (j == 1)
		L[i][j] = mat1(i - 1, j) + m[i][j];

	else
		L[i][j] = min(mat1(i - 1, j), mat1(i, j - 1)) + m[i][j];

	return L[i][j];

}

int mat2(int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1)
				L[i][j] = m[1][1];
			else if (i == 1)
				L[i][j] = m[i][j] + L[i][j - 1];
			else if (j == 1)
				L[i][j] = m[i][j] + L[i - 1][j];
			else
				L[i][j] = m[i][j] + min(L[i - 1][j], L[i][j - 1]);
		}
	}

	return L[n][n];

}


int main() {

	srand((unsigned int)time(NULL));

	int length = 0;
	int n = 0;

	while (n < 3) {

		cin >> length;

		m = new int* [length + 1];
		L = new int* [length + 1];

		for (int i = 1; i <= length; i++) {
			m[i] = new int[length + 1];
			L[i] = new int[length + 1];
		}


		for (int i = 1; i <= length; i++) {
			for (int j = 1; j <= length; j++) {
				m[i][j] = rand();
				L[i][j] = -1;
				cout << m[i][j] << "\t" << " ";

			}
			cout << endl;

		}

		clock_t start, end;
		int result;

		start = clock();
		result = mat(length, length);
		end = clock();

		cout.setf(ios::fixed);
		cout.precision(5);
		cout << "Recursive: " << result << "(time: " << (float)(end - start) / CLOCKS_PER_SEC << ")  ";

		start = clock();
		result = mat1(length, length);
		end = clock();


		cout.setf(ios::fixed);
		cout.precision(5);      // 시간설정
		cout << "Memoization: " << result << "(time: " << (float)(end - start) / CLOCKS_PER_SEC << ") ";



		for (int i = 1; i <= length; i++) {
			for (int j = 1; j <= length; j++) {
				L[i][j] = -1;
			}
		}

		start = clock();
		result = mat2(length);
		end = clock();

		cout.setf(ios::fixed);
		cout.precision(5);
		cout << "DP: " << result << "(time: " << (float)(end - start) / CLOCKS_PER_SEC << ")" << endl;

		delete m;
		delete L;


		n++;
	}

}
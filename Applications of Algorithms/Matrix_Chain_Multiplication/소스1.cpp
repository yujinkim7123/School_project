#include <iostream>
#include <iomanip> 
#include<string>// 출력 형식 조작
using namespace std;

#define Max 100

int P[Max][Max];

void order(int i, int j)

{
	int k;
	if (i == j)
		cout << "A" << i;

	else

	{
		k = P[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}

void minmult(int n, int d[])

{
	int i, j, k, diagonal, temp1, temp2;
	int M[Max][Max];
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
		{
			M[i][j] = 0;
			P[i][j] = 0;
		}

	for (diagonal = 1; diagonal <= n - 1; diagonal++)
	{
		for (i = 1; i <= n - diagonal; i++)
		{
			j = i + diagonal;
			temp1 = 99999; // 초기 비교값을 99999로 둔다
			for (k = i; k <= j - 1; k++)
			{
				temp2 = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (temp1 > temp2)       // 최소값이 temp1에 계속 갱신됨
				{
					temp1 = temp2;
					P[i][j] = k;    // 최소를 갖게하는 k값									//
				}
			}
			M[i][j] = temp1;       // 최소값을 M행렬에 쓴다
		}
	}
	int result = M[1][n];
	cout << result << endl;
	order(1, n);     
	

}

void main()
{
	int d[Max];
	int n, result;

	cin >> n;
	cin.ignore();
	string sew;
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
			d[nu] = rel;
			nu++;

			str.clear();
		}
		cin.clear();
	}

	int rel = 0;
	rel = stoi(str);
	d[nu] = rel;

	cin.clear();

	minmult(n, d);       
}


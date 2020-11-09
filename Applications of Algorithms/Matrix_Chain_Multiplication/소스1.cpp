#include <iostream>
#include <iomanip> 
#include<string>// ��� ���� ����
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
			temp1 = 99999; // �ʱ� �񱳰��� 99999�� �д�
			for (k = i; k <= j - 1; k++)
			{
				temp2 = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (temp1 > temp2)       // �ּҰ��� temp1�� ��� ���ŵ�
				{
					temp1 = temp2;
					P[i][j] = k;    // �ּҸ� �����ϴ� k��									//
				}
			}
			M[i][j] = temp1;       // �ּҰ��� M��Ŀ� ����
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


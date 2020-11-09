#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int **number;
int B[100001];

void divide(int B[], int n) {

	int sum = 0;
	int count = 0;
	int j = 0;
	for (int i = n-1; i >=0; i--) {
		j++;
	  if (j % 3 == 0) {
			sum = sum + B[i + 1] + B[i + 2];
			count++;
		}
	}
	j = 0;
	j = n - (count * 3) - 1;
	
	for (int i = j; i>=0 ; i--)
		sum = sum + B[i];

	printf("%d\n", sum);

}

void radixSort(int **number, int *B, int n , int T , int k) {
	int C[10];
	int mod = 10;
	int dev = 1;
	int num;
	int D[100001];

	for (int i = 1; i <= n; i++) {
		B[i-1] = number[T][i];
		D[i-1] = number[T][i];
	}

	for (int h = 0; h < k; h++, mod *= 10, dev *= 10) {
		for (int i = 0; i < 10; i++) {
			C[i] = 0;
		}
		for (int j = 0; j < n; j++) {
			num = (B[j] % mod) / dev;
			C[num]++;
		}
	
		for (int i = 1; i < 10; i++) {
			C[i] = C[i] + C[i - 1];
			
		}
	
		for (int j = (n - 1); j >= 0; j--) {
			num = (B[j] % mod) / dev;
			int index = C[num];
			D[index - 1] = B[j];
			C[num]--;
		}

		for (int i = 0; i < n; i++) {
			B[i] = D[i];
		}

	}

	divide(B, n);

}



int main() {

	FILE *fp = fopen("input.txt", "r");

	if (fp == NULL) {
		printf("file open error.\n");
		return -1;
	}
	
	int T;
	int n;

	   fscanf(fp, "%d\n", &T);
	    number = (int**)malloc(sizeof(int)*T);

		for (int i = 0; i < T; i++) {

			fscanf(fp, "%d\n", &n);

			number[i] = (int*)malloc(sizeof(int) * n + 1);
			number[i][0] = n;

			for (int j = 1; j < (n + 1); j++) {

				fscanf(fp, "%d ", &number[i][j]);

			}

		}
		

		for (int i = 0; i < T; i++) {

			radixSort(number, B , number[i][0], i, 6);

		}

	
}
 
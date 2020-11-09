#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define N 100000

int partition(int A[], int p, int r) {
	int x = A[r], i = p - 1;
	int temp;
	for (int j = p; j < r; j++) {
		if (A[j] <= x)
		{
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	temp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = temp;

	return i + 1;
}

int select(int A[], int p, int r, int i) {
	int q, k;
	if (p == r)
		return A[p];
	q = partition(A, p, r);
	k = q - p + 1;
	if (i < k)
		return select(A, p, q - 1, i);
	else if (i == k)
		return A[q];
	else
		return select(A, q + 1, r, i - k);
}

int linearSelect(int A[], int p, int r, int i) {

	int len = r - 0 + 1;

	if (len == 1 && i == 0) return A[0];

	if (len <= 5) {
		int max, k = 4;
		int data[5];
		for (int last = r; last > p; last--) {
			max = 0;
			for (int j = p; j < last; j++) {
				if (A[max] < A[j])
					max = j;
			}
			data[k--] = A[max];
		}
		return data[i - 1]; //0으로 하면 -1 안해도 될걸
	}

	int group_count = len / 5;
	int *medians;
	int **group;

	medians = (int*)malloc(sizeof(int)*group_count);

	for (int i = 0; i < group_count; i++)
	{
		if (5 * i + 5 <= len) {
			int *w = A + (5 * i);

			for (int j = 0; j < 3; j++) {
				int min = j;
				for (int k = j + 1; k < 5; k++) {
					if (w[k] < w[min])
						min = k;
				}
				int num;
				num = w[j];
				w[j] = w[min];
				w[min] = num;
			}
			medians[i] = w[2];
		}

		else {
			medians[i] = A[5 * i];
		}

	}

	int pivot = linearSelect(medians, 0, group_count - 1, group_count/2);
	
	delete[] medians;

	for (int i = 0; i < len; i++) {
		if (A[i] == pivot) {
			int num;
			num = A[i];
			A[i] = A[len-1];
			A[len-1] = num;
			break;
		}
	}
	
	int num = 0;
	for (int i = 0; i < len - 1; i++) {
		if (A[i] < pivot) {
			int num1;
			num1 = A[i];
			A[i] = A[num];
			A[num] = num1;
			num++;
		}
	}

	int num1;
	num1 = A[len -1];
	A[len - 1] = A[num];
	A[num] = num1;


	if (num ==  i) {
		return pivot;
	}

	else if (num > i) {
		return select(A, p, num-1, i);
	}
	else
	{
		return select(A, num+1, r, i - num);
	}
}

int main() {

	int input1[N], input2[N];

	srand((unsigned)time(NULL));

	for (int i = 0; i <= 10; i++) {
		input1[i] = input2[i] = rand();
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", input1[i]);
	}

	printf("\nAverage Linear Selection: %d", select(input1, 0, 9, 3));
	printf(" Worst Linear Selection: %d", linearSelect(input2, 0, 9, 3));

	printf("\n\n");
	clock_t start1, start2, end1, end2;
	double result1, result2;
	for (int i = 0; i < 5; i++) {

		for (int i = 0; i < 100000; i++) {
			input1[i] = input2[i] = rand();
		}

		start1 = clock();
		select(input1, 0, 99999, 50000);
		end1 = clock();
		result1 = (double)(end1 - start1);

		start2 = clock();
		linearSelect(input2, 0, 99999, 50000);
		end2 = clock();
		result2 = (double)(end2 - start2);

		printf("Average Linear Selection: %fsec Worst Linear Selection: %fsec\n", result1 / CLOCKS_PER_SEC, result2 / CLOCKS_PER_SEC);


	}
}
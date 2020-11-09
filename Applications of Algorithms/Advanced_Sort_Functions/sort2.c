#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int temp[100000];

void merge(int A[], int p, int q, int r) {
	int i, j, t;
	i = p; j = q + 1; t = 0;

	while ((i <= q) & (j <= r)) {
		if (A[i] <= A[j])
			temp[t++] = A[i++];
		else
			temp[t++] = A[j++];

	}

	while (i <= q)
		temp[t++] = A[i++];

	while (j <= r)
		temp[t++] = A[j++];

	i = p; t = 0;
	while (i <= r)
		A[i++] = temp[t++];
}

void mergeSort(int A[], int p, int r) {
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

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

void quickSort(int A[], int p, int r)
{
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);

	}

}

int main() {
	int mergeInput[100000] , quickInput[100000];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		mergeInput[i] = quickInput[i] = rand();
	}

	mergeSort(mergeInput, 0, 9);

	printf("Merge Sort: ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", mergeInput[i]);
		}
		printf("\n");
		

	quickSort(quickInput, 0, 9);
    
	printf("Quick Sort: ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", quickInput[i]);
		}
		printf("\n");

		clock_t start1, start2, end1, end2;
		double result1, result2;
		for (int i = 0; i < 5; i++) {

			for (int i = 0; i < 100000; i++) {
				mergeInput[i] = quickInput[i] = rand();
			}

			start1 = clock();
			mergeSort(mergeInput, 0, 99999);
			end1 = clock();
			result1 = (double)(end1 - start1);

			start2 = clock();
			mergeSort(mergeInput, 0, 99999);
			end2 = clock();
			result2 = (double)(end2 - start2);

			printf("Merge Sort: %fsec Quick Sort: %fsec\n", result1 / CLOCKS_PER_SEC, result2 / CLOCKS_PER_SEC);


		}
		

}


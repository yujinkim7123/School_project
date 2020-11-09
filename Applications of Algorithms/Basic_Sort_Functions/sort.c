#include<stdio.h>

#define N 10


void selectionSort(int data[], int n) {
	
	int max;
	int temp;
	for (int last = n -1; last > 0; last--) {
		max = 0;
		for (int i = 1; i <= last; i++) {
			if (data[max] < data[i])
				max = i;


 		}
		temp = data[max];
		data[max] = data[last];
		data[last] = temp;

	}
}


void bubbleSort(int data[], int n) {
	int temp;
	for (int last = n - 1; last > 0; last--) {
		for (int j = 0; j < last; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

}

void insertionSort(int data[], int n) {
	int loc = 0;
	int newitem;
	for (int i = 1; i < n ; i++) {
		
		loc = i - 1;
		newitem = data[i];

		while (( data[loc] > newitem ) & i > 0) {
			data[loc + 1] = data[loc];
			loc--;
		}
		data[loc + 1] = newitem;
	}
}

int main() {
	int arr1[N] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	   selectionSort(arr1, N);
	   printf("selectionSort: ");
	   for (int i = 0; i < N; i++)
		   printf("%d ", arr1[i]);
	       printf("\n");
	 int arr2[N] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	    bubbleSort(arr2, N);
		printf("bubbleSort: ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr2[i]);
	    printf("\n");
	int arr3[N] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	insertionSort(arr3, N);
	printf("insertionSort: ");
	   for (int i = 0; i < N; i++)
	    	printf("%d ", arr3[i]);

}
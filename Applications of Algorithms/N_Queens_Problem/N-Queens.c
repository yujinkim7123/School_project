#include<stdio.h>
#define N 8

int cols[N + 1];


int abs(int number) {
	if (number < 0)
		return -number;
	else
		return number;
}

int promising(int h) {
	for (int i = 1; i < h; i++) {
		if (cols[i] == cols[h])
			return 0;
		else if (h - i == abs(cols[h] - cols[i]))
			return 0;
	}
	return 1;
}

int queens(int h) {
	if (!promising(h))
		return 0;

	if (h == N)
		return 1;

	for (int i = 1; i <= N; i++) {
		cols[h + 1] = i;
		if (queens(h + 1))
		{
			printf("(%d, %d)\n", (N - h) , cols[(N - h)]);
			return 1;
		}
	}
	return 0;
}


int main() {
	if (queens(0) == 1)
		printf("Succees\n");
}
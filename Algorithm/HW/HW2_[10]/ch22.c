/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>
#include <stdlib.h>

void reverse(char A[], char B[]) {
	int i, len, j = 0;
	for (i = 0; A[i] != '\0'; i++) {
	}

	for (len = i - 1; len >= 0; len--) {
		B[j] = A[len];
		j++;
	}
	B[j] = '\0';
	printf("%s\n", B);
}

int main() {
	char A[100];
	char B[100];

	printf("���ڿ��� �Է��Ͻÿ�");
	fflush(stdout);
	scanf("%s", A);

	reverse(A, B);

	printf("%s\n", B);

}

/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>

int main() {
	char A[5][100];
	int i;
	for(i =0; i < 5; i++){
	printf("���ڸ� �Է��Ͻÿ�");
	fflush(stdout);
	scanf("%s", A[i]);
	}

for(i =0; i <5; i++)
  printf("%s\n", A[i]);
}

/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>

int main() {
	float A[10][6];
	int i;
	printf("10명의 학생에 정보를 학번 국어 영어 수학 순으로 넣어주세요\n");
	for (i = 0; i < 10; i++) {
		printf("%d 번쨰 학생\n", i+1);
		fflush(stdout);
		scanf("%f %f %f %f", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
	}
	for (i = 0; i < 10; i++) {
		A[i][4] = A[i][1] + A[i][2] + A[i][3];
		A[i][5] = A[i][4] / 3;
	}
	printf("\t순번\t국어\t영어\t수학\t총점\t평균\n");
	printf(
			"**************************************************************************************\n");

	for (i = 0; i < 10; i++) {

		printf("\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.2f\n", A[i][0], A[i][1],
				A[i][2], A[i][3], A[i][4], A[i][5]);
	}
}

/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>

int main() {
	int A[] = { 19, 2, 25, 92, 36, 45 };
	int i;
	int x, y = 0;
	double ave, dis = 0;

	printf("저장 숫자 출력:");
	i = 0;
	while (i < 6) {
		printf("%d ", A[i]);
		ave = A[i] + ave;
		if (A[i] < x) {
			x = A[i];
		}
		if (A[i] > y)
			y = A[i];
		i++;
	}
	printf("\n");

	ave = ave / 6;

	i = 0;

	while (i < 6) {
		dis += ((A[i] - ave) * (A[i] - ave));
		i++;
	}

	dis = dis / 6;

	printf("평균 : %.2f 분산 : %.2f 최댓값:  %d 최솟값: %d", ave, dis, y, x);

}


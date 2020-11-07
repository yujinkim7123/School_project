/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>

void num(int *p, int *q) {
	int i;

	i = *p;
	*p = *q;
	*q = i;
printf("p의 값은 %d q의 값은%d\n", *p, *q);
}

int main() {
	int p, q;

	printf("입력하시오");
	fflush(stdout);
	scanf("%d %d", &p, &q);

	num(&p, &q);
	printf("p의 값은 %d q의 값은%d\n", p , q);

}


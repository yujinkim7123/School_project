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
printf("p�� ���� %d q�� ����%d\n", *p, *q);
}

int main() {
	int p, q;

	printf("�Է��Ͻÿ�");
	fflush(stdout);
	scanf("%d %d", &p, &q);

	num(&p, &q);
	printf("p�� ���� %d q�� ����%d\n", p , q);

}


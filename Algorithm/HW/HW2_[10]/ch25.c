/*
 * stal.c
 *
 *  Created on: 2018. 3. 13.
 *      Author: ��õ����б�1
 */
#include <stdio.h>

int fun (int n)
{

	if(n == 1)
		return 1;

	else if(n == 0)
		return 0;

	else
	return	(fun(n-2) +fun(n-1));


}


int main (void){
	int n;
	printf("���ڸ� �Է��Ͻÿ�");
	fflush(stdout);
	scanf("%d", &n);

	printf("%d", fun(n));

}

#include<stdio.h>
#include<stdlib.h>

int main() {
	int T = 0;

	printf("���̽��� �� �Է�: \n");
	scanf("%d", T); 

	int **arr =  malloc (sizeof(int *) * T);
	
	for (int i = 0; i < T; i++) {
		printf("%d ��� �� �Է��� �ּ���" , i);
		scanf("%d", arr[i][0]);
		for (int j = 0; j < arr[i][0]; j++) {
			printf("�Է��� ��� �� ��ŭ �����Ը� ��������");
			scanf("%d", arr[i][j]);
 
		}

	}







}
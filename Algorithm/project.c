#include<stdio.h>
#include<stdlib.h>

int main() {
	int T = 0;

	printf("케이스의 수 입력: \n");
	scanf("%d", T); 

	int **arr =  malloc (sizeof(int *) * T);
	
	for (int i = 0; i < T; i++) {
		printf("%d 사람 수 입력해 주세요" , i);
		scanf("%d", arr[i][0]);
		for (int j = 0; j < arr[i][0]; j++) {
			printf("입력한 사람 수 만큼 몸무게를 넣으세요");
			scanf("%d", arr[i][j]);
 
		}

	}







}
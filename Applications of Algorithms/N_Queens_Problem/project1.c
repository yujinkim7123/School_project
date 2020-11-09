#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>

int **number;
int flag[15] = { 0, };
int counter = 0;

void powerset(int h , int **data, int T) {
	int a = 0, b = 0, c = 0;
	
	if (data[T][0] == h) {
		for (int i = 0; i < data[T][0]; i++)
		{
			if (flag[i] == 1)
			{
				a = a + data[T][i + 1] ;
               
			}
			else if (flag[i] == 2)
			{
				b = b + data[T][i + 1];

			}
			else if (flag[i] == 3)
			{
				c = c + data[T][i + 1];
			}

		}
		if ((a == b) && (a == c)) {
			counter++;
		}

		return;
	}

	flag[h] = 1;
	powerset(h + 1 ,data, T);
	flag[h] = 2;
	powerset(h + 1, data, T);
	flag[h] = 3;
	powerset(h + 1, data, T);
	flag[h] = 4;
	powerset(h + 1, data, T);
}


int main() {

	int T, N;

	printf("케이스의 수 입력: \n");
	scanf("%d", &T);
	rewind(stdin);
	number = (int**)malloc(sizeof(int)*T);

	for (int i = 0; i < T; i++) {
		
		printf("학생의 수 입력: \n");
		scanf("%d", &N);	
		rewind(stdin);

		number[i] = (int*)malloc(sizeof(int) * 16);
		number[i][0] = N;

		char change[10] = { 0, };
		char str[200];
		int num[15] = { 0, };

		printf("학생의 몸무게 입력: \n");
		scanf("%[^\n]s", str);
		rewind(stdin);

		int j = 0, k = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == ' ') {
				change[j] = '\0';
				num[k++] = atoi(change);
				j = 0;
			}
			else
				change[j++] = str[i];
		  }
		change[j] = '\0';
		num[k] = atoi(change);

		k = 0;
		for (int j = 1; j < N + 1; j++) {
      	number[i][j] = num[k++];
		}
	}

	rewind(stdin);
	for (int i = 0; i < T; i++) {
	    counter = 0;
		powerset(0,  number, i);
		printf("%d \n", counter);
	};

	free(number);

}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct Person {
	char name[20];
	int number;
	int score;
};

struct Person p[9];
struct Person p2[9];

void countingsort(struct Person *p, struct Person *p2, int n) {
	int C[101];
	for (int i = 0; i < 101; i++)
		C[i] = 0;
	for (int j = 0; j < n; j++) {
		C[p[j].score]++;
	}
	for (int i = 1; i < 101; i++) {
		C[i] = C[i] + C[i - 1];
	}
	for (int j = n - 1; j >= 0; j--) {
		int index = C[p[j].score];
		p2[index - 1].score = p[j].score;
		p2[index - 1].number = p[j].number;
		strcpy(p2[index - 1].name, p[j].name);
		C[p[j].score]--;
	}
}


int main() {

	FILE *fp = fopen("input.txt", "r");

	if (fp == NULL) {
		printf("file open error.\n");
		return -1;
	}

	for (int i = 0; i < 9; i++) {

		fscanf(fp, "%s %d %d\n", &p[i].name, &p[i].number, &p[i].score);

	}

	countingsort(p, p2, 9);

	int j = 0;
	for (int i = 0; i < 9; i++) {

		printf("[%d] name: %-10s\tid: %d\tscore:%d \n", ++j, p2[i].name, p2[i].number, p2[i].score);

	}

	fclose(fp);

}
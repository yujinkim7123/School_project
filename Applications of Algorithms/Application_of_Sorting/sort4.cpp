#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct Person {
	char name[20];
	int number;
	int score;
};

struct Person p[9];

void heapify(struct Person *p, int i, int n)
{
	int left;
	int right;
	int smaller;

	left = (2 * i);
	right = ((2 * i) + 1);

	if (right <= n) {
		if (p[left - 1].score < p[right - 1].score)
			smaller = left;
		else
			smaller = right;
	}

	else if (left <= n) {

		smaller = left;

	}

	else
		return;

	if (p[smaller - 1].score < p[i - 1].score) {
		struct Person p1;

		strcpy(p1.name, p[smaller - 1].name);
		p1.number = p[smaller - 1].number;
		p1.score = p[smaller - 1].score;

		strcpy(p[smaller - 1].name, p[i - 1].name);
		p[smaller - 1].number = p[i - 1].number;
		p[smaller - 1].score = p[i - 1].score;

		strcpy(p[i - 1].name, p1.name);
		p[i - 1].number = p1.number;
		p[i - 1].score = p1.score;

		heapify(p, smaller, n);
	}

}

void buildheap(struct Person *p, int n) {
	
	for (int i = (n/2); i > 0; i--) {
		
		heapify(p, i, n);

        }
}

void heap(struct Person *p, int n) {

	buildheap(p, n);

	for (int i = n; i > 1; i--) {

		struct Person p1;

		strcpy(p1.name, p[0].name);
		p1.number = p[0].number;
		p1.score = p[0].score;

		strcpy(p[0].name, p[i - 1].name);
		p[0].number = p[i - 1].number;
		p[0].score = p[i - 1].score;


		strcpy(p[i - 1].name, p1.name);
		p[i - 1].number = p1.number;
		p[i - 1].score = p1.score;


		heapify(p, 1, i - 1);
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

	heap(p, 9);

	int j = 0;
	for (int i = 8; i >= 0; i--) {
		
		printf("[%d] name: %-10s\tid: %d\tscore:%d \n" , ++j, p[i].name, p[i].number, p[i].score);
		
   }

	fclose(fp);

}
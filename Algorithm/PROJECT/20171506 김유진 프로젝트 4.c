/*
 * HW.c
 *
 *  Created on: 2018. 6. 10.
 *      Author: kim yu jin
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define cQ_SIZE 100

typedef struct {
	int id;
	int tEvent;
	int tService;
} Event;
typedef Event element;

typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
} QueueType;

int tSimulation;
double probEvent;
int tMaxService;
int totalWaitTime;
int nEvents;
int nServedEvents;

double unitRand() {
	return (rand() / (double) RAND_MAX);
}

QueueType *createQueue() {
	QueueType *cQ;
	cQ = (QueueType *) malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int isEmpty(QueueType *cQ) {
	if (cQ->front == cQ->rear)
		return 1;
	else
		return 0;
}
int isFull(QueueType *cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front % cQ_SIZE)
		return 1;
	else
		return 0;
}

void enQueue(QueueType *cQ, element item) {
	if (isFull(cQ)) {
		printf("Queue is full!!!\n");
		exit(1);
	} else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}
element deQueue(QueueType *cQ) {
	if (isEmpty(cQ))
		exit(1);
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front]; // ����ü�� �ּҰ� �ƴ϶� ����ü ��ü�� �Ѱ��ִ� ���̴�.
	}
}

void insertEvent(QueueType *cQ, int eventTime) {
	element A;
	A.id = ++nEvents;
	A.tEvent = eventTime;
	A.tService = (rand() % tMaxService);

	enQueue(cQ, A);
}

void main() {
	QueueType *Q1 = createQueue();
	Event a; // ����ü ��ü�� �ּҰ� �ƴϴ�.
	int serviceTime = 0;
	int sec;

	srand((unsigned int) time(NULL));

	totalWaitTime = 0;
	nEvents = 0;
	nServedEvents = 0;

	printf("�ùķ��̼� �� �ִ� �ð� (����:��) = ");
	fflush(stdout);
	scanf("%d", &tSimulation);
	printf("�����ð�(1��)�� �̺�Ʈ�� �߻��� Ȯ�� (��:0.1) = ");
	fflush(stdout);
	scanf("%lf", &probEvent);
	printf("�� �̺�Ʈ�� ���� �ִ� ó�� �ð� (����:��) = ");
	fflush(stdout);
	scanf("%d", &tMaxService);
	printf("============================================================\n");

	for (sec = 0; sec <= tSimulation; sec++) {
		printf("����ð� : %d \n", sec);
		if (unitRand() < probEvent) {
			insertEvent(Q1, sec);
			a = Q1->queue[Q1->rear];
			printf("�̺�Ʈ  %d �߻� (ó���ð�: %d)\n ", a.id, a.tService);
		}
		if (serviceTime <= 0 && isEmpty(Q1) == 0) {
			nServedEvents++;
			a = deQueue(Q1); // ����ü ��ü�� �޾ƿ��� ���̴�.�ּҰ� �ƴϴ�.
			serviceTime = a.tService;
			totalWaitTime +=(sec - (a.tEvent));
			printf("�̺�Ʈ %d ó������ (���ð� : %d )\n", a.id, (sec - (a.tEvent)));
		}

		if (serviceTime > 0)
			serviceTime--;
	}

	printf("SimulAation Report! \n");
    printf("ó���� �̺�Ʈ �� \t = %d \n", nServedEvents);
    printf("���� ��� �ð�\t = %d ��\n",totalWaitTime);
    printf("�̺�Ʈ �� ��մ��ð�\t = %.2f ��\n", (float)(totalWaitTime/nServedEvents));
    printf("���� ��� �̺�Ʈ �� \t = %d \n", nEvents - nServedEvents);
}

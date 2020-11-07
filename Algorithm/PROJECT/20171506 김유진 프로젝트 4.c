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
		return cQ->queue[cQ->front]; // 구조체의 주소가 아니라 구조체 자체를 넘겨주는 것이다.
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
	Event a; // 구조체 자체임 주소가 아니다.
	int serviceTime = 0;
	int sec;

	srand((unsigned int) time(NULL));

	totalWaitTime = 0;
	nEvents = 0;
	nServedEvents = 0;

	printf("시뮬레이션 할 최대 시간 (단위:초) = ");
	fflush(stdout);
	scanf("%d", &tSimulation);
	printf("단위시간(1초)에 이벤트가 발생할 확률 (예:0.1) = ");
	fflush(stdout);
	scanf("%lf", &probEvent);
	printf("한 이벤트에 대한 최대 처리 시간 (단위:초) = ");
	fflush(stdout);
	scanf("%d", &tMaxService);
	printf("============================================================\n");

	for (sec = 0; sec <= tSimulation; sec++) {
		printf("현재시간 : %d \n", sec);
		if (unitRand() < probEvent) {
			insertEvent(Q1, sec);
			a = Q1->queue[Q1->rear];
			printf("이벤트  %d 발생 (처리시간: %d)\n ", a.id, a.tService);
		}
		if (serviceTime <= 0 && isEmpty(Q1) == 0) {
			nServedEvents++;
			a = deQueue(Q1); // 구조체 자체를 받아오는 것이다.주소가 아니다.
			serviceTime = a.tService;
			totalWaitTime +=(sec - (a.tEvent));
			printf("이벤트 %d 처리시작 (대기시간 : %d )\n", a.id, (sec - (a.tEvent)));
		}

		if (serviceTime > 0)
			serviceTime--;
	}

	printf("SimulAation Report! \n");
    printf("처리된 이벤트 수 \t = %d \n", nServedEvents);
    printf("전제 대기 시간\t = %d 초\n",totalWaitTime);
    printf("이벤트 당 평균대기시간\t = %.2f 초\n", (float)(totalWaitTime/nServedEvents));
    printf("현재 대기 이벤트 수 \t = %d \n", nEvents - nServedEvents);
}

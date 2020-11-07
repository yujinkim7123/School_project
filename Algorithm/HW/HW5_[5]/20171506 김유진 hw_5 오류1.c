/*
 * list.c
 *
 *  Created on: 2018. 4. 10.
 *      Author: kim yu ji
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list {
	char data[4];
	struct list* link;
} listnode;

listnode* head;

void print(listnode* head) {
	listnode *p;
	p = head;
	printf("head = (");

		do {
			printf("%s", p->data);
			p = p->link;
			if (p != head)
				printf(",");
		} while (p != head);

	printf(") \n");
}

void insert1(listnode * head, char *x) {
	listnode* new, *temp;
	new = (listnode*) malloc(sizeof(listnode));
	strcpy(new->data, x);
	if (head == NULL) {
		head = new;
		new->link = new;
	}

	else {
		temp = head;
		while (temp->link != head) {
			temp = temp->link;
		}
		new->link = temp->link;
		temp->link = new;
		head = new;
	}
}

/*void insert2(listnode * head, listnode* pre, char *x) {
	listnode*new;
	new = (listnode *) malloc(sizeof(listnode));
	strcpy(new->data, x);
	if (head == NULL) {
		head = new;
		new->link = new;
	}/* else if(pre == NULL){
		pre = head;
		while(pre->link != head){
		pre = pre->link;
		}
		new->link = pre->link;
		head = new;
		pre->link = new;
	}
	else {
		new->link = pre->link;
		pre->link = new;
	}

}*/
int main(void) {
	listnode *p;
	head = NULL;

	printf("(1) 원형 연결 리스트 생성하기! \n");
	print(head);
	/*printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
	insert2(head, NULL, "월");
	print(head);
*/
}

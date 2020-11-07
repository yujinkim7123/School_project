#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list {
	char data[4];
	struct list* link;
} listnode;

listnode * head;

void print(listnode* head) {
	listnode *p;
	p = head;
	printf("head = (");
	if (head != NULL) {
		do {
			printf("%s", p->data);
			p = p->link;
			if (p != head)
				printf(",");
		} while (p != head);
	}
	printf(") \n");
}

listnode* insert1(listnode* head, char *x) {
	listnode* new, *temp;
	new = (listnode*) malloc(sizeof(listnode));
	strcpy(new->data, x);
	if (head == NULL) {
		head = new;
		new->link = new;
	} else {
		temp = head;
		while (temp->link != head) {
			temp = temp->link;
		}
		new->link = temp->link;
		temp->link = new;
		head = new;
	}
	return head;
}

listnode* insert2(listnode * head, listnode* pre, char *x) {
	listnode *new;
	new = (listnode *) malloc(sizeof(listnode));
	strcpy(new->data, x);
	if (head == NULL) {
		head = new;
		new->link = new;
	} else {
		new->link = pre->link;
		pre->link = new;
	}
	return head;

}
listnode* search(listnode* head, char *x) {
	listnode * temp;
	temp = head;
while (temp != NULL){
		if (strcmp(temp->data, x) == 0)
			return temp;
		else
			temp = temp->link;
	}
return temp;
}

int main(void) {
	listnode *p;
	head = NULL;
	printf("(1) 원형 연결 리스트 생성하기! \n");
	print(head);
	head = insert1(head, "화"); //오류확인을 위해 넣은 코드
	printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
	head = insert2(head, NULL, "월");
	print(head);
	printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = search(head, "월");
	insert2(head, p, "수");
	print(head);
	printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = search(head, "토");
	insert2(head, p, "금");
	print(head);

}

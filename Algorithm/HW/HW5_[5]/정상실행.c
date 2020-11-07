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
listnode* search(listnode* head, char *x) {
	listnode * temp;
	temp = head;
	if (temp == NULL)
		return temp;
	do {
		if (strcmp(temp->data, x) == 0)
			return temp;
		else
			temp = temp->link;
	} while (temp != head);
	return NULL;
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
		new->link = head;
		temp->link = new;
		head = new;
	}
	return NULL;
}

listnode* insert2(listnode * head, listnode* pre, char *x) {
	listnode *new;
	new = (listnode *) malloc(sizeof(listnode));
	strcpy(new->data, x);
	if (head == NULL) {
		head = new;
		new->link = new;
	} else if (pre == NULL) {
		pre = head;
		while (pre->link != head) {
			pre = pre->link;
		}
		new->link = pre->link;
		pre->link = new;
		head = new;
	} else {
		new->link = pre->link;
		pre->link = new;
	}
	return head;

}

listnode* delete(listnode* head, listnode* old) {
	listnode* pre;
	if(head == NULL)return head;
	if(old == NULL)return head;

	if(head == old){
		if(head->link == head){
			free(old);
			head = NULL;
		}
		else{
			pre = head;
			while(pre->link !=head){
				pre= pre->link;
			}

			pre->link = old->link;
			head = old->link;
		}
	}
	else{
		pre = head;
		while(pre->link !=head){
			if(pre->link == old){
				pre->link = old->link;
				free(old);
				return head;
			}
			pre= pre->link;
		}
	}

	return head;
}
int main(void) {
	listnode *p;
	head = NULL;
	printf("(1) 원형 연결 리스트 생성하기! \n");
	print(head);
	printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
	head = insert2(head, NULL, "월");
	print(head);
	printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = search(head, "월");
	head = insert2(head, p, "수");
	print(head);
	printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = search(head, "토");
	head = insert2(head, p, "금");
	print(head);

	printf("(5) 원형 연결 리스트에서 [금] 노드 삭제하기! \n");
	p = search(head, "금");
	head = delete(head, p);
	print(head);
	printf("(6) 원형 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = search(head, "수");
	delete(head, p);
	print(head);
	printf("(7) 원형 연결 리스트에서 [월] 노드 삭제하기! \n");
	p = search(head, "월");
	head = delete(head, p);
	print(head);

}

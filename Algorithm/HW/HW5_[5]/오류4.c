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

void delete(listnode* head, listnode* old){
	listnode* pre;
	if(head == NULL) return;
	if(head->link == NULL){
		free(head);
		head = NULL;
		return;
	}
	else if(old == NULL) return;
	else{
		pre = head;
		while(pre->link != old){
			pre = pre->link;
		}
		pre->link = old->link;
		if(old == head){
			head = old->link;
			free(old);
		}
	}



}
int main(void) {
	listnode *p;
	head = NULL;
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	print(head);
	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�! \n");
	head = insert2(head, NULL, "��");
	print(head);
	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	head = insert2(head, p, "��");
	print(head);
	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	head = insert2(head, p, "��");
	print(head);

	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	delete(head, p);
	print(head);
	printf("(6) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	delete(head, p);
	print(head);
	printf("(7) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	delete(head, p);
	print(head);

}

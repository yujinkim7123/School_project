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
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	print(head);
	head = insert1(head, "ȭ"); //����Ȯ���� ���� ���� �ڵ�
	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�! \n");
	head = insert2(head, NULL, "��");
	print(head);
	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	insert2(head, p, "��");
	print(head);
	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = search(head, "��");
	insert2(head, p, "��");
	print(head);

}

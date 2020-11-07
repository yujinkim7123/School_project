/*
 * hello1.c
 *
 *  Created on: 2018. 3. 31.
 *      Author: kim yu jin
 */
/*
 * hell0.c
 *
 *  Created on: 2018. 3. 28.
 *      Author: kim yu ji*/
/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>
#include <string.h>

#define MAX_IOT_LIST_SIZE 50

typedef struct {
	char name[20];
	int id;
} Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE];
int length = 0;

Namecard make_Namecard(char name[], int id) {
	Namecard newCard;
	strcpy(newCard.name, name);
	newCard.id = id;
	return newCard;
}

void init(void) {
	length = 0;
}
int is_full(void) {
	if (length >= MAX_IOT_LIST_SIZE + 1) {
		return 1;
	} else
		return 0;
}
void insert(int pos, Namecard item) {
	int i = 0;
	if (is_full() != 1 && pos <= length && pos >= 0) {
		for (i = length; i > pos; i--) {
			iot_list[i] = iot_list[i - 1];
		}

		iot_list[pos] = item; //�Ƹ� �� ����ü�� �ּҸ� �ǳ��ִ� �ſ��� ������ ���̴�.
		length++;
	} else
		printf("���� ��ġ ���� �Ǵ� ��ȭ ���� ����\n");

}
void delete(int pos) {
	int i = 0;
	if (pos < length && pos >= 0) {
		for (i = pos; i < length; i++) {
			iot_list[i] = iot_list[i + 1];
		}
		length--;
	} else
		printf("���� ���� ���� �Ǵ� ���� ��ġ ����\n");
}

Namecard get_entry(int pos) {
	Namecard pos1;
	if(pos < length && pos >= 0)
	{
		pos1 = iot_list[pos];
	}

		return pos1;

}

int is_empty(void) {
	if (length != MAX_IOT_LIST_SIZE + 1) {
		return 1;
	} else
		return 0;
}

int find(Namecard item) {
	int i, x = -1;
	int y = 0, j;

	for (i = 0; i < length; i++) {
		if (iot_list[i].id == item.id) {
			for (j = 0; iot_list[i].name[j] != '\0'; j++) {
				if (iot_list[i].name[j] != item.name[j]) {
					y = 1;
					break;
				}
			}
			if (iot_list[i].name[j] == '\0' && item.name[j] == '\0' && y == 0) {
				x = i;
			}

		}
	}
	return x;

}
void replace(int pos, Namecard item) {
	if (pos < length && pos >= 0) {
		iot_list[pos] = item;
	} else
		printf("��ü ��ġ ����\n");
}
int size(void) {
	if (length == 0)
		return length;

	else
		return length;
}
void sort_list(void) {
	int i, j;
	Namecard newcar;
	for (i = 0; i < length; i++) {
		for (j = 0; j < length - 1; j++) {
			if (iot_list[i].id > iot_list[j + 1].id) {
				newcar = iot_list[j + 1];
				iot_list[j + 1] = iot_list[j];
				iot_list[j] = newcar;
			}
		}
	}
}

void print_list(char *msg) {
	int i;
	printf("%s: ", msg);
	for (i = 0; i < length; i++) {
		printf("( %s, %d )", iot_list[i].name, iot_list[i].id);

	}
	printf("\n\n");
}

int main() {
	init();
	print_list("Init\n");

	insert(0, make_Namecard("��μ�", 20171526));
	insert(0, make_Namecard("�ִ���", 20171539));
	insert(1, make_Namecard("�̵���", 20171531));
	insert(size(), make_Namecard("�Ǽ�ö", 20171537));
	insert(3, make_Namecard("����", 20171512));
	insert(size(), make_Namecard("������", 20171533));
	insert(10, make_Namecard("�����", 20171536));
	print_list("Insert");

	replace(size() - 1, make_Namecard("������", 20171505));
	replace(4, make_Namecard("ȫ�⿵", 20171520));
	replace(20, make_Namecard("����ö", 20171524));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	sort_list();
	print_list("Sort");
	printf("%s is found at %d\n", "�̵���", find(make_Namecard("�̵���", 20171531)));
	printf("%s is found at %d\n", "���缮", find(make_Namecard("���缮", 20161234)));
}

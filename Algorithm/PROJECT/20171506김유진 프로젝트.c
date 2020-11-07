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

		iot_list[pos] = item; //아마 그 구조체에 주소를 건너주는 거여서 가능한 것이다.
		length++;
	} else
		printf("삽입 위치 오류 또는 포화 상태 오류\n");

}
void delete(int pos) {
	int i = 0;
	if (pos < length && pos >= 0) {
		for (i = pos; i < length; i++) {
			iot_list[i] = iot_list[i + 1];
		}
		length--;
	} else
		printf("공백 상태 오류 또는 삭제 위치 오류\n");
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
		printf("교체 위치 오류\n");
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

	insert(0, make_Namecard("김민수", 20171526));
	insert(0, make_Namecard("최대한", 20171539));
	insert(1, make_Namecard("이동현", 20171531));
	insert(size(), make_Namecard("권순철", 20171537));
	insert(3, make_Namecard("이현", 20171512));
	insert(size(), make_Namecard("박찬종", 20171533));
	insert(10, make_Namecard("김용희", 20171536));
	print_list("Insert");

	replace(size() - 1, make_Namecard("김현민", 20171505));
	replace(4, make_Namecard("홍기영", 20171520));
	replace(20, make_Namecard("문영철", 20171524));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	sort_list();
	print_list("Sort");
	printf("%s is found at %d\n", "이동현", find(make_Namecard("이동현", 20171531)));
	printf("%s is found at %d\n", "윤재석", find(make_Namecard("윤재석", 20161234)));
}

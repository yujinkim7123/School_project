#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#define MAX_NAME_LEN 20 
#define HASH_TABLE_SIZE 8
#define MAX_STUDENT_SIZE 9
typedef struct {
	int id;
	char name[MAX_NAME_LEN];
} Student;
typedef struct node
{
	Student person;
	struct node* next;
} Node;
Node* HashTable[HASH_TABLE_SIZE];

void insert(int key, Student A) {
	int h;
	h = key % HASH_TABLE_SIZE;
	Node* newNode = (Node*)malloc(sizeof(Node));
	//if (newNode != NULL) {
		strcpy_s(newNode->person.name, A.name);
		newNode->person.id = A.id;
		if (HashTable[h] == NULL) {

			HashTable[h] = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = HashTable[h];
			HashTable[h] = newNode;
		}
//	}
}
void delet(int key) {
	int h;
	h = key % HASH_TABLE_SIZE;
	Node* NEXT = HashTable[h];
	if (NEXT->person.id == key) {
		HashTable[h] = NEXT->next;
	   }

	for (int i = 0; NEXT->next != NULL; i++) {
		if (NEXT->next->person.id == key) {
			NEXT->next = NEXT->next->next;
			return;
		}
		NEXT = NEXT->next;
	}
}

Student* search(int key) {
	int h;
	h = key % HASH_TABLE_SIZE;
	Node* NEXT = HashTable[h];
	for (int i = 0; NEXT != NULL; i++) {
		if (NEXT->person.id == key) {

			return &(NEXT->person);
		}
		NEXT = NEXT->next;
	}
	return NULL;
}
void printHashTable() {

	Node* NEXT;

	printf("Hash Table\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		
		printf("ID(%d): ", i);
		
		NEXT = HashTable[i];

		for (int j = 0; NEXT != NULL; j++) {
            
			printf("(%d, %s)", NEXT->person.id, NEXT->person.name);
			
			NEXT = NEXT->next;
			
			if (NEXT != NULL) {
				printf("->");
			}

		}

		printf("\n");
	}


}
int main() {
	Student* ptr;
	Student data[MAX_STUDENT_SIZE] =
	{
	{20171496, "EunsolAn"},
	{20171498, "JiwooChoi"},
	{20171506, "YoojinKim"},
	{20171507, "ChanggiLee"},
	{20171513, "YoojinChoi"},
	{20171514, "EuiyeonCho"},
	{20171515, "SeungwooBaek"},
	{20171518, "IsuJung"},
	{20171540, "SanghoonSong"}
	};
	for (int i = 0; i < MAX_STUDENT_SIZE; i++)
		insert(data[i].id, data[i]);

	ptr = search(20180345);
	if (ptr != NULL)
		printf("ID: %d\tNAME: %s\n", ptr->id, ptr->name);
	ptr = search(20171513);
	if (ptr != NULL)
		printf("ID: %d\tNAME: %s\n", ptr->id, ptr->name);
    delet(20171540);

	printHashTable();
}
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"

//typedef struct _Info {
//	int id;
//	char name[20];
//}Info;
int flag = 0;

void printInfo(List *list) {
	printf("ID : %d , Name: %s\n", list->cur->data->id, list->cur->data->name);
}

Info * n_days_later(List list , char name[20], int days) {
	Info * data = NULL;
	int i;
	if (LFirst(&list, &data)) {
		if (!strcmp(data->name, name)) {
			for(i = 0 ; i< days; i++)
				LNext(&list, &data);
			return data;
		}
		else {
			for (i = 0; i < LCount(&list) - 1; i++) {
				if (LNext(&list, &data)) {
					if (!strcmp(data->name, name)) {
						for (i = 0; i < days; i++)
							LNext(&list, &data);
						return data;
					}
				}
			}
		}
	}
	return NULL;
}

int main(void) {
	int i;
	Info *people;
	int numOfNode;
	List list;
	ListInit(&list);

	people = (Info *)malloc(sizeof(Info));
	people->id = 1;
	strcpy(people->name, "�赵��");
	LInsert(&list, people);

	people = (Info *)malloc(sizeof(Info));
	people->id = 2;
	strcpy(people->name, "��ġ��");
	LInsert(&list, people);

	people = (Info *)malloc(sizeof(Info));
	people->id = 3;
	strcpy(people->name, "������");
	LInsert(&list, people);

	people = (Info *)malloc(sizeof(Info));
	people->id = 4;
	strcpy(people->name, "�ֿ�ĥ");
	LInsert(&list, people);

	numOfNode = LCount(&list);

	//printf("%d\n", numOfNode);

	if (LFirst(&list, &people)) {
		printInfo(&list);
		for (i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &people))
				printInfo(&list);
		}
	
	}

	printf("21���� ������ : ");
	
	people = n_days_later(list, "�赵��",21);
	if (people != NULL)
		printf("ID : %d, Name : %s\n", people->id, people->name);
	else
		printf("�߸� �Է�!!\n");

	/*if (LFirst(&list, &people)) {
		free(people);

		for (i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &people)) {
				free(people);
			}
		}
	}*/                     //<- ����

	
	return 0;
}
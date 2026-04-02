#include <stdio.h>
#include <string.h>

#define MAXSIZE 6
typedef int DataType;

typedef struct {
	DataType data[MAXSIZE];
	int length;
} SeqList;

void InitList(SeqList *L);
void CreateList(SeqList *L, DataType arr[], int n);
void AppendList(SeqList *L, DataType data);

void ShowList(SeqList *L);
int  Length(SeqList *L);
int  IsFull(SeqList *L) ;
int  IsEmpty(SeqList *L);

int main() {
	DataType arr[6] = {1, 2, 3, 4, 5, 6};
	SeqList L;
	InitList(&L);
	// ShowList(&L);
	CreateList(&L, arr, 6);
	ShowList(&L);
	AppendList(&L, 7);
		AppendList(&L, 8);
	ShowList(&L);
	return 0;
}

void InitList(SeqList *L) {
	L->length = 0;
}

int  Length(SeqList *L) {
	return L->length;
}

int  IsFull(SeqList *L) {
	return L->length == MAXSIZE;
}

int  IsEmpty(SeqList *L) {
	return L->length == 0;
}

void ShowList(SeqList *L) {
	if (IsEmpty(L)) {
		printf("list is empty!\n");
		return;
	}

	for (int i = 0; i < L->length; i++) {
		printf("%d\t",	L->data[i]);
	}
	printf("\n");
}
void CreateList(SeqList *L, DataType arr[], int n) {
	if (IsFull(L)) {
		printf("list is full!\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		L->data[i] = arr[i];
	}
	L->length = n;
}
void AppendList(SeqList *L, DataType data) {
	L->data[L->length] = data;
	L->length++;
}


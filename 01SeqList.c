#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
typedef int DataType;

typedef struct {
	DataType data[MAXSIZE];
	int length;
} SeqList;

void InitList(SeqList *L);
void CreateList(SeqList *L,DataType arr[]);
void ShowList(SeqList *L);
int  Length(SeqList *L);
int  IsFull(SeqList *L) ;
int  IsEmpty(SeqList *L);

int main() {
	DataType arr[6] = {1,2,3,4,5,6};
	SeqList L;
	InitList(&L);
	ShowList(&L);
	CreateList(&L,arr);
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

void ShowList(SeqList *L){
	if(IsEmpty(L)){
		printf("空表\n");
		return;
	}
}
void CreateList(SeqList *L,DataType arr[]){
	
}

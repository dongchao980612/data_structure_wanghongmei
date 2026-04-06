#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

#define OK  0
#define ERR -1

typedef struct DNode {
	int data;
	struct DNode *prior;  // 前驱
	struct DNode *next;   // 后继
} DNode, *DLinkList;

DLinkList InitDList();
void ShowDLinkList(DLinkList L );
void CreateDLinkList_tail(DLinkList L, DataType arr[], int n);

int LengthDLinkList(DLinkList  L);

int InsertDLinkList(DLinkList L, int pos, DataType data);
int DeleteDLinkList(DLinkList L, int pos, DataType *data);

int CheckNull(DLinkList L);



int main() {
	DataType arr[5] = {1, 2, 3, 4, 5};
	int pos = -1;
	int res = -1;
	DataType x = 0;

	DLinkList  L = NULL;
	printf("当前双链表的数据为：");
	ShowDLinkList(L);

	// 初始化
	L = InitDList();
	CreateDLinkList_tail(L, arr, 5);
	printf("当前双链表的数据为：");
	ShowDLinkList(L);
	printf("当前双链表的长度为：%d\n", LengthDLinkList(L));

	// 插入
	pos = 1;
	x=999;
	InsertDLinkList(L, pos, x);
	printf("当前双链表的数据为：");
	ShowDLinkList(L);
	printf("当前双链表的长度为：%d\n", LengthDLinkList(L));
	
	
	// 删除
	pos = 1;
	res = DeleteDLinkList(L, pos, &x);
	
	if (res != ERR) {
		printf("删除第%d个的元素是%d\n", pos, x);
		printf("当前双链表的数据为：");
		ShowDLinkList(L);
	}
	
	
	return 0;
}

int LengthDLinkList(DLinkList  L){
	if (CheckNull(L)) {
		return 0;
	}
	int cnt = 0;
	
	for (DNode *p = L->next; p != NULL; p = p->next) {
		cnt++;
	}
	
	return cnt;
	
}


int CheckNull(DLinkList L) {
	if (L == NULL) {
		printf("链表未初始化\n");
		return ERR; // 表示未初始化
	}
	
	return OK;     // 表示已初始化
}

void ShowDLinkList(DLinkList L ) {
	if (CheckNull(L)) {
		return;
	}
	
	for (DNode *p = L->next; p != NULL; p = p->next ) {
		printf("%d<->", p->data);
	}
	
	printf("NULL \n");
}

DLinkList InitDList() {
	DLinkList head = (DNode*)malloc(sizeof(DNode));
	
	if (CheckNull(head)) {
		return NULL;
	}
	
	
	head->next = NULL;
	return head;
}

void CreateDLinkList_tail(DLinkList L, DataType arr[], int n){
	if (CheckNull(L)) {
		return;
	}
	
	DNode* tail = L;
	for (int i = 0; i < n; i++) {
		DNode* newNode = (DNode*)malloc(sizeof(DNode));
		CheckNull(newNode);
		newNode->data = arr[i];
		newNode->next = NULL;
		tail->next = newNode;
		newNode->prior=tail;
		tail = newNode;
	}
	
	tail->next = NULL;
	
}

int InsertDLinkList(DLinkList L, int pos, DataType data){
	if (CheckNull(L)) {
		return ERR;
	}
	
	int count = 0;
	DNode *p = L;
	
	if (pos > LengthDLinkList(L) +1 || pos <= 0) {
		printf("[%s] 下标越界\n", __func__);
		return	 ERR	;
	}
	
	for (;  count < pos - 1; p = p->next, count++);
	
	
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	newNode->prior=p;
	newNode->next=p->next;
	newNode->data=data;
	p->next->prior=newNode;
	p->next=newNode;
	return OK;
}
int DeleteDLinkList(DLinkList L, int pos, DataType *data){
	if (CheckNull(L)) {
		return ERR;
	}
	
	int count = 0;
	DNode *p = L;
	
	if (pos > LengthDLinkList(L) || pos <= 0) {
		printf("[%s] 下标越界\n", __func__);
		return	 ERR	;
	}
	
	for (; count < pos-1; p = p->next, count++);
	
	DNode *q = p->next;
	*data = q->data;
	
	// 处理pos为最后一个元素，指针报错
	if (p->next->next != NULL) {
		p->next->next->prior = p;
	}
	p->next = p->next->next;
	
	free(q);
	return OK;
}

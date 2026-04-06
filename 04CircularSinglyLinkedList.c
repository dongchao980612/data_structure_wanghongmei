#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

#define OK  0
#define ERR -1

typedef struct Node {
	int data;
	struct Node *next;
} Node, *CLinkList;

CLinkList InitCLinkList();
void CreateCLinkList_tail(CLinkList L, DataType arr[], int n);
void ShowCLinkList(CLinkList L);
int LengthCLinkList(CLinkList L);
int LocateCLinkList(CLinkList L, DataType data);
int GetLinkCList(CLinkList L, int pos, DataType* data);
int InsertCLinkList(CLinkList L, int pos, DataType data);
int DeleteCLinkList(CLinkList L, int pos, DataType *data);
void DestroyCLinkList(CLinkList* L);

int CheckNull(CLinkList L);

int main() {

	DataType arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int pos = -1;
	int res = -1;
	DataType x = 0;

	CLinkList  L = NULL;
	printf("当前单链表的数据为：");
	ShowCLinkList(L);

	// 初始化
	L = InitCLinkList();
	CreateCLinkList_tail(L, arr, 9);
	printf("当前双链表的数据为：");
	ShowCLinkList(L);
	// ("当前双链表的长度为：%d\n", LengthDLinkList(L));

	return 0;
}

CLinkList InitCLinkList() {
	CLinkList head = (Node*)malloc(sizeof(Node));

	if (CheckNull(head)) {
		return NULL;
	}

	//  头节点的next直向自己
	head->next = head;
	return head;
}
void CreateCLinkList_tail(CLinkList L, DataType arr[], int n) {
	if (CheckNull(L)) {
		return;
	}

	Node* tail = L;
	for (int i = 0; i < n; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		CheckNull(newNode);
		newNode->data = arr[i];
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}

	tail->next = L;
}
void ShowCLinkList(CLinkList L) {
	if (CheckNull(L)) {
		return;
	}

	for (Node *p = L->next; p != L; p = p->next ) {
		printf("%d->", p->data);
	}

	printf("->%d\n",L->next->data);
}
int LengthCLinkList(CLinkList L) {

}
int LocateCLinkList(CLinkList L, DataType data) {

}
int GetLinkCList(CLinkList L, int pos, DataType* data) {

}
int InsertCLinkList(CLinkList L, int pos, DataType data) {

}
int DeleteCLinkList(CLinkList L, int pos, DataType *data) {

}
void DestroyCLinkList(CLinkList* L) {

}

int CheckNull(CLinkList L) {
	if (L == NULL) {
		printf("链表未初始化\n");
		return ERR; // 表示未初始化
	}

	return OK;     // 表示已初始化
}

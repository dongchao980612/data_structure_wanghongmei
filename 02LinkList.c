#include <stdio.h>
#include <stdlib.h>  // 标准头文件

typedef int DataType;

#define OK  0
#define ERR -1

typedef struct Node {
	DataType data;
	struct Node* next;
} Node;

Node* InitList();
void CreateList_tail(Node *L, DataType arr[], int n);
void ShowList(Node *L);
int LengthList(Node *L);
int LocateList(Node* L, DataType data);
int GetList(Node *L, int pos, DataType* data);
int InsertList(Node *L, int pos, DataType data);
int DeleteList(Node *L, int pos, DataType *data);
int IsEmpty(Node *L);
void DestroyList(Node* L);

int main() {
	DataType arr[5] = {1, 2, 3, 4, 5};
	Node*  L = NULL;
	int pos = -1;
	int res = -1;
	DataType x = 0;

	L = InitList();
	CreateList_tail(L, arr, 5);
	printf("当前单链表的数据为：");
	ShowList(L);

	InsertList(L, 1, 8);
	printf("插入后：");
	ShowList(L);

	printf("当前单链表的长度为：%d\n", LengthList(L));

	// 按值查找
	x = 3;
	pos = LocateList(L, x);
	if (pos != ERR) {
		printf("元素%d的位置是%d\n", x, pos);
	} else {
		printf("未找到元素%d\n", x);
	}

	// 按位查找
	pos = 3;
	res = GetList(L, pos, &x);
	if (res != ERR) {
		printf("第%d位的元素是%d\n", pos, x);
	}

	// 删除
	pos = 3;
	res = DeleteList(L, pos, &x);
	if (res != ERR) {
		printf("删除第%d个的元素是%d\n", pos, x);
		ShowList(L);
	}

	// 销毁
	DestroyList(L);
	L=NULL;
	printf("当前单链表的数据为：");
	ShowList(L);
	return 0;
}

// 初始化
Node* InitList() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("内存分配失败\n");
		return NULL;
	}
	head->next = NULL;
	return head;
}

// 尾插法（已修复BUG）
void CreateList_tail(Node *L, DataType arr[], int n) {
	if (L == NULL) {
		printf("链表未初始化\n");
		return;
	}
	Node* tail = L;
	for (int i = 0; i < n; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = arr[i];
		newNode->next = NULL;  
		tail->next = newNode;
		tail = newNode;
	}
	tail->next = NULL;
}

// 判断空
int IsEmpty(Node *L) {
	return L->next == NULL;
}

// 打印
void ShowList(Node *L) {
	if (L == NULL) {
		printf("链表未初始化\n");
		return;
	}
	for (Node *p = L->next; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

// 长度
int LengthList(Node *L) {
	if (L == NULL) return ERR;
	int cnt = 0;
	for (Node *p = L->next; p != NULL; p = p->next) {
		cnt++;
	}
	return cnt;
}

// 按值查找
int LocateList(Node* L, DataType data) {
	if (L == NULL) return ERR;
	int count = 0;
	for (Node *p = L->next; p != NULL; p = p->next, count++) {
		if (p->data == data) return count + 1;
	}
	return ERR;
}

// 按位查找
int GetList(Node *L, int pos, DataType* data) {
	if (L == NULL || pos < 1) return ERR;
	Node *p = L->next;
	int count = 1;
	for (; p != NULL && count < pos; p = p->next, count++);
	if (p == NULL) return ERR;
	*data = p->data;
	return OK;
}

// 插入
int InsertList(Node *L, int pos, DataType data) {
	if (L == NULL || pos < 1) return ERR;

	int count = 0;
	Node *p = L;
	for (; p != NULL && count < pos - 1; p = p->next, count++);

	if (p == NULL) return ERR;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	return OK;
}

// 删除（已修复BUG）
int DeleteList(Node *L, int pos, DataType *data) {
	if (L == NULL || pos < 1) return ERR;

	int count = 0;
	Node *p = L;
	for (; p != NULL && count < pos - 1; p = p->next, count++);

	if (p == NULL || p->next == NULL) return ERR;

	Node *q = p->next;
	*data = q->data;
	p->next = q->next;
	free(q);
	return OK;
}

void DestroyList(Node* L) {
	Node *p, *q;
	for (p = L; p != NULL; p = q) {
		q = p->next;  // 先保存下一个
		free(p);      // 再释放当前
	}
}

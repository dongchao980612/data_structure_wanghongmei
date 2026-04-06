#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

#define OK  0
#define ERR -1


typedef struct LNode {
	DataType data;          // 数据域
	struct LNode *next;     // 指针域
} Node, *LinkList;

LinkList InitLinkList();
void CreateLinkList_tail(LinkList L, DataType arr[], int n);
void ShowLinkList(LinkList L);
int LengthLinkList(LinkList L);
int LocateLinkList(LinkList L, DataType data);
int GetLinkList(LinkList L, int pos, DataType* data);
int InsertLinkList(LinkList L, int pos, DataType data);
int DeleteLinkList(LinkList L, int pos, DataType *data);
void DestroyLinkList(LinkList* L);

int IsEmpty(LinkList L);
int CheckNull(LinkList L);


int main() {
	DataType arr[5] = {1, 2, 3, 4, 5};
	int pos = -1;
	int res = -1;
	DataType x = 0;

	LinkList  L = NULL;
	printf("当前单链表的数据为：");
	// ShowLinkList(L);

	// 初始化
	L = InitLinkList();
	ShowLinkList(L);
	
	CreateLinkList_tail(L, arr, 5);
	printf("当前单链表的数据为：");
	ShowLinkList(L);
	printf("当前单链表的长度为：%d\n", LengthLinkList(L));

	// 插入
	pos = 1;
	x=999;
	InsertLinkList(L, pos, x);
	printf("当前单链表的数据为：");
	ShowLinkList(L);
	printf("当前单链表的长度为：%d\n", LengthLinkList(L));

	// 按值查找
	x = 2;
	pos = LocateLinkList(L, x);

	if (pos != ERR) {
		printf("元素%d的位置是%d\n", x, pos);
	} else {
		printf("未找到元素%d\n", x);
	}


	// 按位查找
	pos = 6;
	res = GetLinkList(L, pos, &x);

	if (res != ERR) {
		printf("第%d位的元素是%d\n", pos, x);
	}

	// 删除
	pos = 1;
	res = DeleteLinkList(L, pos, &x);

	if (res != ERR) {
		printf("删除第%d个的元素是%d\n", pos, x);
		printf("当前单链表的数据为：");
		ShowLinkList(L);
	}

	// 销毁
	DestroyLinkList(&L);
	printf("当前单链表的数据为：");
	ShowLinkList(L);

	return 0;
}

// 初始化
LinkList InitLinkList() {
	LinkList head = (Node*)malloc(sizeof(Node));
	
	if (CheckNull(head)) {
		return NULL;
	}

	head->next = NULL;
	return head;
}

// 尾插法
void CreateLinkList_tail(LinkList L, DataType arr[], int n) {
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

	tail->next = NULL;
}

// 判断空
int IsEmpty(LinkList L) {
	return L->next == NULL;
}

// 打印
void ShowLinkList(LinkList L) {
	if (CheckNull(L)) {
		return;
	}
	if (IsEmpty(L)) {
		printf("链表空，[%s]失败\n", __func__);
		return;
	}
	for (Node *p = L->next; p != NULL; p = p->next ) {
		printf("%d->", p->data);
	}

	printf("NULL \n");
}

// 长度
int LengthLinkList(LinkList L) {
	if (CheckNull(L)) {
		return 0;
	}

	int cnt = 0;

	for (Node *p = L->next; p != NULL; p = p->next) {
		cnt++;
	}

	return cnt;
}

// 按值查找
int LocateLinkList(LinkList L, DataType data) {
	if (CheckNull(L)) {
		return ERR;
	}

	int count = 0;

	for (Node *p = L->next; p != NULL; p = p->next, count++) {
		if (p->data == data) {
			return count + 1;
		}
	}

	return ERR;
}

// 按位查找
int GetLinkList(LinkList L, int pos, DataType* data) {
	if (CheckNull(L)) {
		return ERR;
	}

	Node *p = L->next;
	int count = 1;

	if (pos > LengthLinkList(L) || pos <= 0) {
		printf("[%s] 下标越界\n", __func__);
		return	 ERR	;
	}

	for (; count < pos; p = p->next, count++);

	*data = p->data;
	return OK;
}

// 插入
int InsertLinkList(LinkList L, int pos, DataType data) {
	if (CheckNull(L)) {
		return ERR;
	}

	int count = 0;
	Node *p = L;

	if (pos > LengthLinkList(L) +1 || pos <= 0) {
		printf("[%s] 下标越界\n", __func__);
		return	 ERR	;
	}

	for (;  count < pos - 1; p = p->next, count++);


	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	return OK;
}

// 删除
int DeleteLinkList(LinkList L, int pos, DataType *data) {
	if (CheckNull(L)) {
		return ERR;
	}

	int count = 0;
	Node *p = L;

	if (pos > LengthLinkList(L) || pos <= 0) {
		printf("[%s] 下标越界\n", __func__);
		return	 ERR	;
	}

	for (; count < pos - 1; p = p->next, count++);


	Node *q = p->next;
	*data = q->data;
	p->next = q->next;
	free(q);
	return OK;
}

void DestroyLinkList(LinkList* L) {
	Node *tail, *q;

	for (tail = *L; tail != NULL; tail = q) {
		q = tail->next;  // 先保存下一个
		free(tail);      // 再释放当前
	}

	*L = NULL; // 自动置空！
}
int CheckNull(LinkList L) {
	if (L == NULL) {
		printf("链表未初始化\n");
		return ERR; // 表示未初始化
	}

	return OK;     // 表示已初始化
}

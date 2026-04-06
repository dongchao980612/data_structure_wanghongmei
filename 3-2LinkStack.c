#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 5
typedef int DataType;

#define OK  0
#define ERR -1

typedef struct Node {
	DataType data;
	struct Node* next;
} Node, *LinkStack;

int IsEmpty(LinkStack S);
LinkStack InitLinkStack();
int PushStack(LinkStack S, DataType x);
int PopStack(LinkStack S, DataType *x);
int GetTop(LinkStack S, DataType *x);
void ShowLinkStack(LinkStack S);
void DestoryLinkStack(LinkStack *S);
int CheckNull(LinkStack L);

int main() {
	LinkStack S;
	DataType x = -1;
	int res = -1;
	S = InitLinkStack();

	PushStack(S, 10);
	PushStack(S, 15);
	ShowLinkStack(S);

	res = GetTop(S, &x);
	if (res == OK) {
		printf("栈顶元素是：%d\n", x);
		ShowLinkStack(S);
	}

	res = PopStack(S, &x);
	if (res == OK) {
		printf("出栈元素是：%d\n", x);
		ShowLinkStack(S);
	}

	PushStack(S, 20);

	if (IsEmpty(S)) {
		printf("栈空\n");
	} else {
		printf("栈非空\n");
		ShowLinkStack(S);
	}
	
	DestoryLinkStack(&S);
	ShowLinkStack(S);
	
	return 0;
}

int IsEmpty(LinkStack S) {
	return S->next == NULL;
}

LinkStack InitLinkStack() {
	LinkStack top = (Node*)malloc(sizeof(Node));
	top->next = NULL;
	return top;
}

int PushStack(LinkStack S, DataType x) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (CheckNull(newNode)) {
		return ERR;
	}
	newNode->data = x;
	newNode->next = S->next;
	S->next = newNode;
	return OK;
}

int PopStack(LinkStack S, DataType *x) {
	if (IsEmpty(S)) {
		printf("栈空，[%s]失败\n", __func__);
		return ERR;
	}
	Node *p = S->next;
	*x = p->data;
	S->next = p->next;
	free(p);        // 修复内存泄漏
	return OK;
}

int GetTop(LinkStack S, DataType *x) {
	if (IsEmpty(S)) {
		printf("栈空，[%s]失败\n", __func__);
		return ERR;
	}
	*x = S->next->data;
	return OK;
}

void ShowLinkStack(LinkStack S) {
	if (CheckNull(S)) {
		return;
	}


	if (IsEmpty(S)) {
		printf("栈空，[%s]失败\n", __func__);
		return;
	}

	Node *tail = S->next;
	for (; tail != NULL; tail = tail->next) {
		printf("%d->", tail->data);
	}
	printf("|\n");
}

void DestoryLinkStack(LinkStack *S) {
	Node *tail = *S;  // 指向头结点
	Node *q;       // 用来保存下一个节点

	// 逐个释放所有节点
	for (; tail != NULL; tail = q) {
		q = tail->next;
		free(tail);
		tail = q;
	}


	*S = NULL;  // 关键：让主函数的栈指针变成空
}

int CheckNull(LinkStack S) {
	if (S == NULL) {
		printf("链栈未初始化\n");
		return ERR;
	}

	return OK;     // 表示已初始化
}

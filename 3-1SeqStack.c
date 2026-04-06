#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 5
typedef int DataType;

#define OK  0
#define ERR -1


typedef struct Node {
	DataType data[STACKSIZE];
	int top;
} SeqStack;

int IsEmpty(SeqStack* S);
int IsFull(SeqStack* S);
void InitSeqStack(SeqStack* S);
int PushStack(SeqStack* S, DataType x) ;
int PopStack(SeqStack* S, DataType *x) ;
int GetTop(SeqStack* S, DataType *x) ;
void ShowSeqStack(SeqStack* S) ;

int main() {
	SeqStack S;
	DataType x = -1;
	int res = -1;
	InitSeqStack(&S);
	// ShowSeqStack(&S);

	PushStack(&S, 10);
	PushStack(&S, 15);
	ShowSeqStack(&S);


	res = GetTop(&S, &x);
	if (res == OK) {
		printf("栈顶元素是：%d\n", x);
		ShowSeqStack(&S);
	}

	res = PopStack(&S, &x);
	if (res == OK) {
		printf("出栈元素是：%d\n", x);
		ShowSeqStack(&S);
	}

	PushStack(&S, 20);

	if (IsEmpty(&S)) {
		printf("栈空\n");
	} else {
		printf("栈非空\n");
		ShowSeqStack(&S);
	}

	return 0;
}

int IsEmpty(SeqStack* S) {
	return S->top == -1;
}

int IsFull(SeqStack* S) {
	return S->top == STACKSIZE - 1;
}

void InitSeqStack(SeqStack* S) {
	S->top = -1;
}
int PushStack(SeqStack* S, DataType x) {
	if (IsFull(S)) {
		printf("栈满，[%s]失败\n", __func__);
		return ERR;
	}
	S->top++;
	S->data[S->top] = x;

	return OK;
}
int PopStack(SeqStack* S, DataType *x) {
	if (IsEmpty(S)) {
		printf("栈空，[%s]失败\n", __func__);
		return ERR;
	}
	*x = S->data[S->top];
	S->top--;

	return OK;
}
int GetTop(SeqStack* S, DataType *x) {
	if (IsEmpty(S)) {
		printf("栈空，[%s]失败\n", __func__);
		return ERR;
	}

	*x = S->data[S->top];

	return OK;
}

void ShowSeqStack(SeqStack* S) {
	if (IsEmpty(S)) {
		printf("栈空，[%s]失败\n", __func__);
		return;
	}

	for (int i = S->top; i >= 0; i--) {
		printf("%d->", S->data[i]);
	}
	printf("|\n");
}

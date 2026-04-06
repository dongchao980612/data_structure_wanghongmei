#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
typedef char DataType;

#define OK  0
#define ERR -1

#define LEFTOVER 2
#define RIGHROVER -2

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

int Match(char *str);

int main() {
	char str[100];
	scanf("%s", str);
	
	int res = Match(str);
	
	switch (res) {
		case OK:
			printf("括号匹配成功！\n");
			break;
		case LEFTOVER:
			printf("左括号多余！\n");
			break;
		case RIGHROVER:
			printf("右括号多余！\n");
			break;
		default:
			printf("字符串有误！\n");
			break;
	}

}
// 括号匹配函数：成功返回1，失败返回0
int Match(char *str) {
	SeqStack S;
	InitSeqStack(&S);  // 1. 初始化栈
	char ch;           // 临时变量，接收出栈元素

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			// 左括号：入栈
			PushStack(&S, str[i]);
		}
		else if (str[i] == ')') {
			// 右括号：出栈
			if (IsEmpty(&S)) {
				return RIGHROVER;
			}
			PopStack(&S, &ch); // 用临时变量ch接收，不要改str！
		}

	}

	// 最终判断：栈空 = 完全匹配
	if (IsEmpty(&S)) {
		return OK;
	} else {
		return LEFTOVER;
	}
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

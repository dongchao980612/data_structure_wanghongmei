#include <stdio.h>

#define MAXSIZE 10
typedef int DataType;

// 定义操作状态
#define OK  0
#define ERR -1

// 定义结构体
typedef struct SeqList {
	DataType data[MAXSIZE];
	int length;
} SeqList;

// 函数声明
void InitList(SeqList *L);
void CreateList(SeqList *L, DataType arr[], int n);
int LocateList(SeqList* L, DataType data);
int GetList(SeqList *L, int pos, DataType* data);
int InsertList(SeqList *L, int pos, DataType data);
int DeleteList(SeqList *L, int pos, DataType *data);
void ShowList(SeqList *L);
int LengthList(SeqList *L);
int IsFull(SeqList *L);
int IsEmpty(SeqList *L);

int main() {
	DataType arr[5] = {1, 2, 3, 4, 5};
	DataType x = 0;
	int pos = -1;
	int res = -1;

	SeqList L;
	InitList(&L);
	CreateList(&L, arr, 5);

	printf("当前线性表的数据为：");
	ShowList(&L);

	InsertList(&L, 2, 8);
	printf("当前线性表插入数据后为：");
	ShowList(&L);

	printf("当前线性表的长度为：%d\n", LengthList(&L));

	// 按值查找
	x = 3;
	pos = LocateList(&L, x);
	if (pos != ERR) {
		printf("元素%d的位置是%d\n", x, pos);
	} else {
		printf("未找到元素%d所在位置\n", x);
	}

	// 按位查找
	pos = 3;
	res = GetList(&L, pos, &x);
	if (res != ERR) {
		printf("第%d位的元素是%d\n", pos, x);
	} else {
		printf("未找到第%d位的元素\n", pos);
	}

	// 删除
	pos = 3;
	res = DeleteList(&L, pos, &x);
	if (res != ERR) {
		printf("删除第%d个的元素是%d\n", pos, x);
		ShowList(&L);
	} else {
		printf("删除第%d位的元素失败\n", pos);
	}

	return 0;
}

// 初始化
void InitList(SeqList *L) {
	if (L == NULL) return;
	L->length = 0;
}

// 长度
int LengthList(SeqList *L) {
	if (L == NULL) return 0;
	return L->length;
}

// 判断满
int IsFull(SeqList *L) {
	if (L == NULL) {
		return 0;
	}
	return L->length == MAXSIZE;
}

// 判断空
int IsEmpty(SeqList *L) {
	if (L == NULL) {
		return 0;
	}
	return L->length == 0;
}

// 打印
void ShowList(SeqList *L) {
	if (IsEmpty(L)) {
		printf("顺序表是空的!\n");
		return;
	}
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

// 创建
void CreateList(SeqList *L, DataType arr[], int n) {
	if (L == NULL || arr == NULL || n <= 0 || n > MAXSIZE) {
		printf("创建失败：参数非法\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		L->data[i] = arr[i];
	}
	L->length = n;
}


int LocateList(SeqList* L, DataType data) {
	if (L == NULL) return ERR;
	for (int i = 0; i < L->length; i++) {
		if (data == L->data[i]) {
			return i + 1;
		}
	}
	return ERR;
}

// 按位查找
int GetList(SeqList *L, int pos, DataType* data) {
	if (L == NULL || data == NULL) return ERR;
	if (pos < 1 || pos > L->length) {
		printf("查找位置非法！\n");
		return ERR;
	}
	*data = L->data[pos - 1];
	return OK;
}

// 插入
int InsertList(SeqList *L, int pos, DataType data) {
	if (L == NULL) return ERR;
	if (IsFull(L)) {
		printf("表已满，插入失败\n");
		return ERR;
	}
	if (pos < 1 || pos > L->length + 1) {
		printf("位置错误，插入失败\n");
		return ERR;
	}
	for (int i = L->length; i >= pos; i--) {
		L->data[i] = L->data[i - 1];
	}
	L->data[pos - 1] = data;
	L->length++;
	return OK;
}

// 删除
int DeleteList(SeqList *L, int pos, DataType* data) {
	if (L == NULL || data == NULL) {
		return ERR;
	}
	if (IsEmpty(L)) {
		printf("表空，删除失败\n");
		return ERR;
	}
	if (pos < 1 || pos > L->length) {
		printf("位置错误，删除失败\n");
		return ERR;
	}
	*data = L->data[pos - 1];
	for (int i = pos - 1; i < L->length - 1; i++) {
		L->data[i] = L->data[i + 1];
	}
	L->length--;
	return OK;
}


#include <stdio.h>

int EulerCircuit(int mat[4][4], int n);
int get_degree(int mat[4], int n);
int isOdd(int n);

int main() {

	int mat[4][4] = {{0, 1, 2, 2}, {1, 0, 1, 1}, {2, 1, 0, 0}, {2, 1, 0, 0}};

	int num = EulerCircuit(mat, 4);

	if (num >= 2) {
		printf("有%d个地方通奇数桥，不存在欧拉回路", num);
	} else {
		printf("存在欧拉回路");
	}

	return 0;
}
int get_degree(int mat[4], int n) {
	int degree = 0;

	for (int i = 0; i <= n; i++) {
		degree += mat[i];
	}

	return degree;
}
int isOdd(int n) {
	return n % 2 != 0;
}
int EulerCircuit(int mat[4][4], int n) {
	int count = 0;

	for (int i = 0; i <= n; i++) {
		int degree = get_degree(mat[i], 4);

		if (isOdd(degree)) {
			count++;
		}
	}

	return count;
}

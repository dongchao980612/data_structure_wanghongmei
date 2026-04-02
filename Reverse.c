#include <stdio.h>
#include <string.h>

void swap(char* ch1, char* ch2) {
	char ch = *ch1;
	*ch1 = *ch2;
	*ch2 = ch;
}

void reverse(char seq[], int start, int end) {
	for (int i = start, j = end; i <= j; i++, j--) {
		swap(&seq[i], &seq[j]);
	}
}
int main() {
	char seq[] = "abcdefgh";
	puts(seq);
	
	int i = 3;
	int n = strlen(seq);

	reverse(seq, 0, i - 1);
	reverse(seq, i, n - 1);
	reverse(seq, 0, n - 1);

	puts(seq);

	return 0;
}

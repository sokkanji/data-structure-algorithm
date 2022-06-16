#include <stdio.h>

int fiboSearch(int a[], int key, int n) {
	int fibo[] = { 0, 1, 1, 3, 5, 8, 13, 21, 34, 55 };
	int pos, index = 0, k = 0;

	while (fibo[k] < n) k++;
	while (k > 0) {
		pos = index + fibo[--k];
		if (pos >= n || key < a[pos]);
		else if (key > a[pos]) {
			index = pos;
			k--;
		}
		else return pos;
	}
	return -1;
}

int main(void) {
	int a[] = {2, 7, 10, 12, 14, 18, 21, 33, 34, 48};
	int n = sizeof(a) / sizeof(int);
	int index, key=0;

	index = fiboSearch(a, key, n);
	if (index == -1) printf("없음!");
	else printf("%d를 %d에서 찾음!\n", key, index);

	return 0;
}
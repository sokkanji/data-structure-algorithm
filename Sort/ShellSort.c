#include <stdio.h>

void ShellSort(int a[], int n) {
	int i, j, t;
	int temp;

	for (t = n / 2; t >= 1; t /= 2) {
		for (i = t; i < n; i++) {
			temp = a[i];
			for (j = i - t; j >= 0; j -= t) {
				if (temp < a[j]) a[j + t] = a[j];
				else break;
			} a[j + t] = temp;
		}
	}
}

int main(void) {
	int a[] = { 7, 12, 6, 11, 3, 8, 5, 2 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++) 
		printf("%d  ", a[i]);

	ShellSort(a, n);

	printf("\n정렬 후 : ");
	for (i = 0; i < n; i++) 
		printf("%d  ", a[i]);

	return 0;
}
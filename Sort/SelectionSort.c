#include <stdio.h>

void SelectionSort(int a[], int n) {
	int i, j, min, index;

	for (i = 0; i < n - 1; i++) {
		min = a[i];
		index = i;
		for (j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = min;
	}
}

int main(void) {
	int a[] = { 10, 5, 7, 12, 9, 16, 1, 3 };
	int i, n = sizeof(a) / sizeof(int);

	printf("���� �� : ");
	for (i = 0; i < n; i++)
		printf("%d   ", a[i]);

	SelectionSort(a, n);

	printf("\n���� �� : ");
	for (i = 0; i < n; i++)
		printf("%d   ", a[i]);

	return 0;
}
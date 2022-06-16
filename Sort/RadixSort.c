#include <stdio.h>
#include <stdlib.h>

void RadixSort(int a[], int n) {
	int i, max = a[0], digit_Base = 1;
	int digit_cnt[10] = { 0 };
	int *bucket = (int *)malloc(sizeof(int)*n);

	for (i = 1; i < n; i++)
		if (max < a[i]) max = a[i];

	while (digit_Base <= max) {
		for (i = 0; i < n; i++)
			digit_cnt[a[i] / digit_Base % 10]++;

		for (i = 1; i < 10; i++)
			digit_cnt[i] += digit_cnt[i - 1];

		for (i = n - 1; i >= 0; i--)
			bucket[--digit_cnt[a[i] / digit_Base % 10]] = a[i];

		for (i = 0; i < n; i++)
			a[i] = bucket[i];

		for (i = 0; i < 10; i++)
			digit_cnt[i] = 0;

		digit_Base *= 10;
	}
	free(bucket);
}

int main(void) {
	int a[] = { 1, 10, 100, 1000, 25, 50, 120, 450, 2345, 90, 7, 45 };
	int n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);

	RadixSort(a, n);

	printf("\n정렬 후 : ");
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}
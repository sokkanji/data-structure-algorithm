#include <stdio.h>

void HeapSort(int a[], int n) {
	int i, parent, child, value, m=n;
	//최대 힙 구성
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}
	//힙 정렬
	while (n > 1) {
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
		for (i = 1; i <= m; i++)
			printf("    %d", a[i]);
		printf("\n");
	}
}

int main(void) {
	int a[] = { NULL, 17, 8, 16, 3, 1, 6, 5, 13, 89, 32 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전:");
	for (i = 0; i < n; i++)
		printf("%d  ", a[i]);

	HeapSort(a, n-1);

	printf("\n정렬 후:");
	for (i = 0; i < n; i++)
		printf("%d  ", a[i]);
	
	return 0;
}
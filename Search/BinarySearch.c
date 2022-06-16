#include <stdio.h>

int BinarySearch(int a[], int key, int n) {
	int mid, left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key == a[mid]) return mid;
		else if (key > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main(void) {
	int a[] = { 12, 21, 35, 46, 50, 67, 70, 82, 91, 100, 110, 120 };
	int n = sizeof(a) / sizeof(int);
	int key, index;

	printf("ã�� ��: ");
	scanf_s("%d", &key);
	index = BinarySearch(a, key, n);
	
	if (index == -1) printf("ã���� �ϴ� data ����!\n");
	else printf("%d�� %d���� ã��!\n", key, index);

	return 0;
}
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

	printf("찾을 값: ");
	scanf_s("%d", &key);
	index = BinarySearch(a, key, n);
	
	if (index == -1) printf("찾고자 하는 data 없음!\n");
	else printf("%d를 %d에서 찾음!\n", key, index);

	return 0;
}
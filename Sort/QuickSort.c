#include <stdio.h>

void QuickSort(int *a, int low, int high){
   int i, j, key, temp;
   if(low < high){
       key=a[low];
	   i=low;
	   j=high;
	   while(i < j){
	       while(i < high && a[i] <= key) i++; //while (i < high && a[i] >= privot)i++; 내림차순
		   while(j > low && a[j] >= key) j--;  //while (j > left && a[j] <= privot)j--; 내림차순
		   if(i < j){
		       temp=a[i];
			   a[i]=a[j];
			   a[j]=temp;
			}
		}
		a[low]=a[j];
		a[j]=key;

		QuickSort(a, low, j-1);
		QuickSort(a, j+1, high);
	}
}

int main(void) {
	int a[] = {21,24,28,9,27,12,3,30,45,50,38,55,41,33};
	int n = sizeof(a) / sizeof(int);
	printf("정렬 전 : ");
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);

	QuickSort(a, 0, n - 1);

	printf("\n정렬 후: ");
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");

	return 0;
}
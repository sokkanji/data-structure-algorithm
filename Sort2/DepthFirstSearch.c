#include<stdio.h>
#define SIZE 8
typedef enum { false, true } bool;
int top = -1;
int stack[SIZE];
bool push(int index) {
	if (top == SIZE)return false;
	stack[++top] = index;
	return true;
}
bool pop(void) {
	if (top == -1)return -1;
	return stack[top--];
}
void DepthFirstSearch(bool G[][SIZE], char V[]) {
	bool chk[SIZE] = { false };
	int i, j;
	char startV;
	printf("√‚πﬂ ¡§¡° : ");
	scanf_s("%c", &startV, 1);
	for (i = 0; i < SIZE; i++)if (startV == V[i])break;
	printf("±Ì¿ÃøÏº±≈Ωªˆ %c", startV);
	chk[i] = true;
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && chk[j] == 0) {
				printf("->%c", V[j]);
				chk[j] = 1;
				push(i);
				i = j;
				break;
			}
		}
		if (j == SIZE)i = pop();

	} while (i >= 0);

}
int main(void) {
	bool G[SIZE][SIZE] = { {0,1,0,1,0,0,0,0},
	{1,0,0,0,1,0,1,0},
	{0,0,0,0,1,1,0,0},
	{1,0,0,0,0,1,0,0},
	{0,1,1,0,0,0,1,0},
	{0,0,1,1,0,0,0,1},
	{0,1,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0} };

	char V[] = { 'A','B','C','D','E','F','G','H' };
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%5d", G[i][j]);
		}
		printf("\n");
	}
	DepthFirstSearch(G, V);
	printf("\n");
	return 0;
}
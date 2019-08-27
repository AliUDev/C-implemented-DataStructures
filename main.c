#include <stdio.h>

int main() {
	int a = 10;
	int *b = &a;
	int **c = &b;
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("a = %p, b = %p, c = %p", a, b, c);
	getchar();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main() {
	struct Queue q;
	initQ(&q);
	insert(&q, 10);
	insert(&q, 12);
	insert(&q, 100);
	insert(&q, 600);
	insert(&q, 1000);
	insert(&q, 11111);
	displayQ(&q);
	return 0;
}

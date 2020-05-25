#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

unsigned int rando(void);

int main(void) {
	unsigned int i;
	for (i = 0; i<=100; i++) {
		printf("%d\n", rando());
	}
	return 0;
}
unsigned int rando(void) {
	static unsigned int i = 0;
	return i++;
}
void rand_print(void) {
	unsigned int i;
	unsigned int j;
	unsigned int randj;
	printf("RAND_MAX: %d\n", RAND_MAX);
	for(i = 1; i <= 10; i++) {
		for (j = 0; j <= INT_MAX; j++) {
			srand(j);
			randj = rand();
			if (randj == i) {
				printf("%d:%d\n", j, i);
				break;
			}
		}

	}
}

#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

int main(void) {
	unsigned int i;
	unsigned int j;
	unsigned int randj;
	printf("RAND_MAX: %d\n", RAND_MAX);
	for(i = 1; i <= 100; i++) {
		for (j = 0; j <= INT_MAX; j++) {
			srand(j);
			randj = rand();
			if (randj == i) {
				printf("%d:%d\n", j, i);
				break;
			}
		}

	}


	return 0;
}

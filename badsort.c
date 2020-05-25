#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>


#define TEST_SIZE 5
#define TEST_RANGE_MAX 10
void build_test(void);
unsigned int test[TEST_SIZE];
unsigned int rrange(unsigned int min, unsigned int max);
int badsort(void);
int debug = 2;

int main(void) {
	unsigned long count=0;
	build_test();
	unsigned int iteration = 0;
	if (debug > 0) {
		int i;
		printf("%5d", 0);
		for(i=0; i<TEST_SIZE; i++) {
			printf("%2d ", test[i]);
		}
		printf("\n");
	}
	while(1) {
		iteration++;
		sleep(1);
		if (debug > 1) {
			printf("%5d:", iteration);
		}
		if(!badsort()) {
			printf(" winner");
			return 0;
		}

	}
	return 0;
}
void build_test(void) {
	unsigned int i;
	time_t t;
	srand((unsigned) time(&t));
	for (i = 0; i<TEST_SIZE; i++) {
		test[i] = rrange(1,TEST_RANGE_MAX);

	}
}
int badsort(void) {
	unsigned int badarray[TEST_SIZE];
	unsigned int maxnum = 0;
	int i;
	time_t t;
	srand((unsigned) time(&t));
	for (i = 0; i<TEST_SIZE; i++) {
		badarray[i] = rrange(1,TEST_RANGE_MAX);
	}
	if (debug > 1) {
		for(i = 0; i<TEST_SIZE; i++) {
			printf("%2d ", badarray[i]);
		}
		printf("\n");
	}
	return 0;
	
}
int issorted(unsigned int *array, int size) {
	int i;
	unsigned int maxnum=0;
	
	for (i=0; i<size; i++) {
		if (maxnum <= array[i])
			maxnum = array[i];
		else
			return 1;
	}

}

unsigned int rrange(unsigned int min, unsigned int max) {
	return rand() % (max + 1 - min);
}


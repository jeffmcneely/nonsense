#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>


#define TEST_SIZE 5
#define TEST_RANGE_MAX 10
void build_test(void);
uint32_t test[TEST_SIZE];
uint32_t rrange(uint32_t min, uint32_t max);
void printarray(uint32_t *array, int size);
int issamearray(uint32_t *a, uint32_t *b, int size);
int issorted(uint32_t *array, int size);

int badsort(void);
int debug = 0;

int main(void) {
	build_test();
	uint32_t iteration = 0;
	if (debug > 0) {
		printf("%5d:", 0);
		printarray(test,TEST_SIZE);

	}
	while(1) {
		iteration++;
		if (debug > 1) {
			printf("%5d:", iteration);
		}
		if(badsort()) {
			printf("winner %d\n", iteration);
			printf("original\n");
			printarray(test,TEST_SIZE);
			return 0;
		}

	}
	return 0;
}
void build_test(void) {
	uint32_t i;
	srand((unsigned) clock());
	for (i = 0; i<TEST_SIZE; i++) {
		test[i] = rrange(1,TEST_RANGE_MAX);

	}
}
int badsort(void) {
	uint32_t badarray[TEST_SIZE];
	int i;

	srand((unsigned) clock());
	for (i = 0; i<TEST_SIZE; i++) {
		badarray[i] = rrange(1,TEST_RANGE_MAX);
	}
	if (debug > 1)
		printarray(badarray,TEST_SIZE);
	if (!issorted(badarray,TEST_SIZE))
		return 0;
	if (!issamearray(badarray,test,TEST_SIZE))
		return 0;
	return 1;	
	
}
void printarray(uint32_t *array, int size) {
	int i=0;
	for(i = 0; i < size; i++) {
		printf("%-2d", array[i]);
	}
	printf("\n");

}
int issorted(uint32_t *array, int size) {
	int i;
	uint32_t maxnum=0;
	
	for (i=0; i<size; i++) {
		if (maxnum <= array[i])
			maxnum = array[i];
		else
			return 0;
	}
	return 1;

}

uint32_t rrange(uint32_t min, uint32_t max) {
	return rand() % (max + 1 - min);
}

int issamearray(uint32_t *a, uint32_t *b, int size) {
	int i;
	int same=1;
	uint32_t *map;
	uint32_t maxnum=0;

	for(i=0; i<size; i++) {
		if (maxnum < a[i]) maxnum = a[i];
	}
	if(debug>2) printf("maxnum %d\n", maxnum);

	map = calloc(maxnum+1, sizeof(uint32_t));
	for(i=0; i<size; i++) {
		map[a[i]]++;
	}
	if(debug>2) printarray(map,maxnum+1);
	for(i=0; i<size; i++) {
		map[b[i]]--;
	}

	if(debug>2) printarray(map,maxnum+1);
	for(i=0; i<maxnum+1; i++) {
		if (map[i] != 0) {
			same = 0;;
			break;
		}
	}
	return same;

}

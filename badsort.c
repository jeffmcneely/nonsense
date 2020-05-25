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
void printarray(unsigned int *array, int size);
int issamearray(unsigned int *a, unsigned int *b, int size);
int issorted(unsigned int *array, int size);

int badsort(void);
int debug = 3;

int main(void) {
	unsigned long count=0;
	build_test();
	unsigned int iteration = 0;
	if (debug > 0) {
		int i;
		printf("%5d:", 0);
		printarray(test,TEST_SIZE);

	}
	while(1) {
		iteration++;
		if (debug > 1) {
			printf("%5d:", iteration);
		}
		if(badsort()) {
			printf(" winner");
			printf("original\n");
			printarray(test,TEST_SIZE);
			return 0;
		}

	}
	return 0;
}
void build_test(void) {
	unsigned int i;
	srand((unsigned) clock());
	for (i = 0; i<TEST_SIZE; i++) {
		test[i] = rrange(1,TEST_RANGE_MAX);

	}
}
int badsort(void) {
	unsigned int badarray[TEST_SIZE];
	unsigned int maxnum = 0;
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
void printarray(unsigned int *array, int size) {
	int i=0;
	for(i = 0; i < size; i++) {
		printf("%-2d", array[i]);
	}
	printf("\n");

}
int issorted(unsigned int *array, int size) {
	int i;
	unsigned int maxnum=0;
	
	for (i=0; i<size; i++) {
		if (maxnum <= array[i])
			maxnum = array[i];
		else
			return 0;
	}
	return 1;

}

unsigned int rrange(unsigned int min, unsigned int max) {
	return rand() % (max + 1 - min);
}

int issamearray(unsigned int *a, unsigned int *b, int size) {
	int i;
	int same=1;
	unsigned int *map;
	unsigned int maxnum=0;

	for(i=0; i<size; i++) {
		if (maxnum < a[i]) maxnum = a[i];
	}
	if(debug>2) printf("maxnum %d\n", maxnum);

	map = calloc(maxnum+1, sizeof(unsigned int));
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

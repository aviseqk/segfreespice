#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

struct Array NewArray(int size) {
    int *p;
    p = (int *)malloc(sizeof(int) * size);
    struct Array arr = {.A = p, .size = size, .length =  0};
	return arr;
}

void ResizeArray(int **p, int old_size, int new_size){
    int *q;
    q = (int *)malloc(sizeof(int) * new_size);

    for(int i = 0; i < old_size; i++) {
        q[i] = (*p)[i];
    }
    free(*p);
    *p = q;
    q = NULL;
}

void Display(struct Array arr) {
	printf("Elements of the array are\n");
	for (int i =0; i < arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

int main() {
	struct Array myArray = NewArray(5);
	myArray.A[0] = 2;
	myArray.A[1] = 6;
	myArray.A[2] = 1;
	myArray.A[3] = 8;

	myArray.length = 4;

	Display(myArray);

	return 0;
}

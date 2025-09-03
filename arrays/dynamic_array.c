#include <stdlib.h>
#include <stdio.h>

void inc_array_size(int **p, int old_size, int new_size)
{
    int *q;
    q = (int *) malloc(new_size * sizeof(int));

    for(int i=0; i < old_size; i++)
        q[i] = (*p)[i];//replace with memcpy;

    free(*p);
    *p = q;
    q = NULL;
}

int main() {
	int *array;
	array = (int*) malloc(sizeof(int)*5);
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	array[4] = 4;

	for(int i=0; i < 5; i++) {
		printf("%d\t", array[i]);
	}
	printf("New Array\n");

	inc_array_size(&array, 5, 10);
	for(int i=0; i < 10; i++) {
		printf("%d\t", array[i]);
	}
}

#include <stdlib.h>
#include <stdio.h>

/* 2D Arrays can be created in three manners 
 * Method 1: All of 2D Array exists in the stack 
 * Method 2: 2D Array partially exists in Stack and partially in Heap, so Stack has an array of pointers , and then those pointers point to 1D Arrays in heap
 * Method 3: Whole of 2D Array exists in Heap, using double pointer, stack variable points to an array of pointers in heap, that points to individual 1D arrays in heap again
 * */

int main()
{
    /* Method 1 - All in Stack */
    int array_2d_all_stack[3][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
    
    for(int i=0; i < 3; i++) {
    for(int j=0;j<5;j++){
            printf("%d \t",array_2d_all_stack[i][j]);
        }
        printf("\n");
    }

    /* Method 2 - Partial in Stack and Heap, so an array of pointers exist in stack. and respective arrays for them exist in heap */
    int *array_partial_stack_heap[3];
    array_partial_stack_heap[0] = (int *)malloc(5 * sizeof(int));
    array_partial_stack_heap[1] = (int *)malloc(5 * sizeof(int));
    array_partial_stack_heap[2] = (int *)malloc(5 * sizeof(int));

    for(int i=0; i < 3; i++) {
    for(int j=0;j<5;j++){
            printf("%d \t",array_partial_stack_heap[i][j]);
        }
        printf("\n");
    }

    /* Method 3 - only a pointer to pointers exist in stack, and then that pointer in heap points to another pointers that point to individual arrays */
    int **array_all_heap;
    array_all_heap = (int **)malloc(sizeof(int *) * 3);
    array_all_heap[0] = (int *)malloc(sizeof(int) * 5);
    array_all_heap[1] = (int *)malloc(sizeof(int) * 5);
    array_all_heap[2] = (int *)malloc(sizeof(int) * 5);

for(int i=0; i < 3; i++) {
    for(int j=0;j<5;j++){
            printf("%d \t",array_all_heap[i][j]);
        }
        printf("\n");
    }



    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void myFunc(int arr[], int n)
{
    arr[2] = 55;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
}

int * getHeapArray(int n)
{
    int *p;
    p = (int *)malloc(sizeof(int) * n);
    for(int i=0;i < n; i++)
        p[i] = i * 7;
    return p;
}

void changeLength(struct Rectangle *r, int newLength)
{
    r->length = newLength;
}

int main()
{
    int num1, num2;
    num1 = 30;
    num2 = 99;

    int arr[5] = {2, 4, 6, 8, 10};
    printArray(arr, 5);
    myFunc(arr, 5);
    printArray(arr, 5);

    int *ha;
    ha = getHeapArray(10);
    printArray(ha, 10);

    struct Rectangle r = {15, 20};
    changeLength(&r, 55);
    printf("Area: %d\n", r.length * r.breadth);

    swap(&num1, &num2);
    printf("num1: %d  num2:%d\n", num1, num2);
}

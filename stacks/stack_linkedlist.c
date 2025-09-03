#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));

    if (node == NULL)
        printf("Stack is full\n");
    else {
        node->data = x;
        node->next = top;
        top = node;
    }
}

int pop() {
    int res = -1;
    struct Node *node;

    if (top == NULL) {
        printf("Stack is empty, cannot pop\n");
    } else {
        node = top;
        res = top->data;
        top = top->next;
        printf("Popped element %d\n", res);
        free(node);
    }
    return res;
}

void displayStack() {
    struct Node *ptr = top;

    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    push(101);
    push(202);
    push(303);
    push(404);

    displayStack();
    pop();
    pop();
    displayStack();
}

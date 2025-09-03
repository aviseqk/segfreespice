#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Stack ADT - Methods In a Stack DS */
/* 1. push(x)
 * 2. pop()
 * 3. Peek(index)
 * 4. StackTop()
 * 5. isEmpty()
 * 6. isFull()
 * */

struct Stack {
    int size;
    int top;
    int *s;
};

bool isFull(struct Stack stack) {
    return stack.top == stack.size - 1;
}

bool isEmpty(struct Stack stack) {
    return stack.top == -1;
}

void freeStackMemory(struct Stack *stack) {
    free(stack->s);
}

int pop(struct Stack *stack) {
    int result = -1;
    if (isEmpty(*stack))
        printf("Empty Stack\n");
    else {
        result = stack->s[stack->top];
        stack->top--;
    }
    return result;
}

void push(struct Stack *stack, int element) {
    if (isFull(*stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->s[stack->top] = element;
    }
}

int peek(struct Stack stack, int position) {
    int result;
    if (stack.top + 1 - position > 0) {
        printf("Invalid Position Ask\n");
    } else {
        int idx = stack.top - position + 1;
        result = stack.s[idx];
    }
    return result;
}

int stackTop(struct Stack stack) {
    if (isEmpty(stack)) {
        return -1;
    } else {
        return stack.s[stack.top];
    }
}

void displayStack(struct Stack stack) {
    int i;
    printf("[TOP->] ");
    for(i = stack.top; i >= 0; i--)
        printf("%d ", stack.s[i]);
    printf("\n");
}

void createStack(struct Stack *stack) {
    printf("enter size of stack\n");
    scanf("%d", &stack->size);
    stack->s = (int *)malloc(sizeof(int)*stack->size);
    stack->top = -1;
}

int main()
{
    struct Stack st;
    createStack(&st);
    push(&st, 101);
    push(&st, 202);
    push(&st, 303);
    push(&st, 404);
    displayStack(st);

    printf("popped %d\n", pop(&st));
    displayStack(st);

    freeStackMemory(&st);
}

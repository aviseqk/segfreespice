#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        //printf("Popped element %d\n", res);
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

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;

    return 0;
}

char *convertToPostfix(char *infix) {
    int i =0, j=0;
    char *postfix;
    int length = strlen(infix);
    postfix = (char *)malloc((length + 2) * sizeof(char));
    
    while(infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else {
                postfix[j++] = pop();
            }
        }
    }

    while(top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;

}

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = convertToPostfix(infix);

    printf("postfix expression = %s \n", postfix);
}

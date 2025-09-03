#include <stdio.h>
#include <stdlib.h>

struct DNode {
    struct DNode *prev;
    struct DNode *next;
    int data;
}*first = NULL;     /* this is the way to initialise it at start and make it a global variable, so that we dont need to pass it around for modifying head of this doubly LL */

void createLinkedList(int arr[], int n) {
    struct DNode*t, *last;
    int i;
    
    first = (struct DNode*)malloc(sizeof(struct DNode));
    first->data = arr[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1;i<n;i++) {
        t = (struct DNode*)malloc(sizeof(struct DNode));
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct DNode *p) {
    printf("Displaying the Doubly Linked List\n");
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void InsertAtIndex(struct DNode *p, int index, int ele) {
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = ele;
    struct DNode *prev;
    int i = 0;

    if (index == 0) {
        // insert before first node
        newNode->prev = NULL;
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    } else {
        // insert at any other index
        while(p && i < index) {
            prev = p;
            p = p->next;
            i++;
        }
        prev->next = newNode;
        newNode->next = p;
        newNode->prev = prev;
        p->prev = newNode;
    }
}

int Length(struct DNode *p) {
    int len = 0;
    
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

int main()
{

    int arr[6] = {10,20,30,40,50,60};
    createLinkedList(arr, 6);
    Display(first);
    printf("Length of the LL is %d\n", Length(first));
    InsertAtIndex(first, 0, 109);
    Display(first);

    InsertAtIndex(first, 1, 444);
    Display(first);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node {
    int data;
    struct Node *next; /* self-referential structure - a struct that refers to itself */
};

struct Node* NewNode(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;

    return ptr;
}

void createLinkedList(struct Node *head, int array[], int length) {
    struct Node *ptr;
    int i;
    ptr = head;
    ptr->data = array[0];
    for(i = 1; i < length;i++) {
        ptr->next = NewNode(array[i]);
        ptr = ptr->next;
    }
}

void DisplayCircularLinkedList(struct Node *head) {
    struct Node *ptr = head;
    int idx = 0;

    do {
        printf("Element %d: %d\n", idx, ptr->data);
        idx++;
        ptr = ptr->next;
    } while(ptr != head);
}

struct Node *getLastNode(struct Node *p) {
    while(p->next) {
        p = p->next;
    }
    return p;
}

// extra Head as the reference to the head Node, we can also make that a global variable or a varianle in main, so at higher level than this function so that it can be accessed for comparison
void freeCircularLinkedListMemory(struct Node *head, struct Node *p) {
    struct Node *ptr = p;
    static int rec_flag = 0;

    if(ptr != head || rec_flag == 0) {
        rec_flag = 1;
        freeCircularLinkedListMemory(head, ptr->next);
        free(ptr);
    }
    rec_flag = 0;
}

int main() 
{
     struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    //printf("[DEBUG] size of struct Node pointer %lu\n", sizeof(head));

    int arr[5] = {101,202,303,404,505};
    createLinkedList(head, arr, 5);
    getLastNode(head)->next = head;
    DisplayCircularLinkedList(head);
    
    freeCircularLinkedListMemory(head, head);
}



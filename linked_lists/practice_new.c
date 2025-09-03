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

void DisplayLinkedList(struct Node *head) {
    struct Node *ptr;
    ptr = head;
    int idx = 0;
        while(ptr != NULL) {
            printf("Element %d: %d\n", idx, ptr->data);
            idx++;
            ptr = ptr->next;
        }
}

void RecursiveDisplayLinkedList(struct Node *p) {
    if (p == NULL)
        return;

    printf("Element is %d\n", p->data);
    RecursiveDisplayLinkedList(p->next);
}

int countElements(struct Node *head) {
    int c = 0;
    struct Node *ptr = head;
    while(ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

int SumOfElements(struct Node *head) {
    int sum = 0;
    struct Node *ptr = head;
    while(ptr != NULL) {
        sum+=ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

void freeLinkedListMemory(struct Node *p) {
    if(p!=NULL) {
        freeLinkedListMemory(p->next);
        free(p);
    }
}

int findMaximumElement(struct Node *p) {
    int max = INT32_MIN;
    while(p) {
        max = (p->data > max) ? p->data : max;
        p = p->next;
    }
    return max;
}

struct Node *searchElement(struct Node *p, int ele) {
    while(p) {
        if (p->data == ele) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/* passing double pointer to first as we need to modify it, otherwise keeping the first a global pointer would also work */
void moveToHead(struct Node **first, struct Node *p, int ele) {
    struct Node *q;
    while(p) {
        if (p->data == ele) {
            q->next = p->next;
            p->next = *first;
            *first = p;
            return;
        }
        q=p;
        p = p->next;
    }
    return;
}

void insertElement(struct Node **first, struct Node *p, int position, int ele) {
    struct Node *new;
    int i = 0;

    if(position == 0) {
        /* insert at the start of the linked list */
        new = NewNode(ele);
        new->next = *first;
        *first = new;
    } else {
        /* insert after the any other element of the LL, even the last */
        for(i = 0; i < position - 1 && p; i++) {
            p = p->next;
        }
        if (!p)
            return;     // incase one tries to insert element after a node that does not exist

        new = NewNode(ele);
        new->next = p->next;
        p->next = new;
    }
}

void deleteElement(struct Node **first, struct Node *p, int ele) {
    struct Node *oldHead;
    struct Node *prevNode = NULL;
    struct Node *currNode = p;
    int deletedValue = -1;
    
    /* if the node to be deleted is the first node, i.e. Head of the LL */
    if ((*first)->data == ele) {
        oldHead = *first;
        *first = (*first)->next;
        deletedValue = oldHead->data;
        free(oldHead);
    } else {
        while(currNode && currNode->data != ele) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(!currNode)
            return;     // no such element to be deleted

        // found the prev node to the node which is to be deleted
        prevNode->next = currNode->next;
        deletedValue = currNode->data;
        free(currNode);
    }
    printf("Deleted Value %d\n", deletedValue);
}

int IsLinkedListSorted(struct Node *p) {
    struct Node *currNode = p;
    struct 

}

int main() {
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    //printf("[DEBUG] size of struct Node pointer %lu\n", sizeof(head));

    int arr[5] = {101,202,303,404,505};
    createLinkedList(head, arr, 5);
    DisplayLinkedList(head);
    //RecursiveDisplayLinkedList(head);

    printf("Count of elements in LL: %d\n", countElements(head));
    printf("Count of elements in LL: %d\n", SumOfElements(head));
    struct Node *foundNode = searchElement(head, 303);
    if (foundNode)
        printf("Found element %d at address %p\n", foundNode->data, foundNode);
    printf("Maximum element in LL: %d\n", findMaximumElement(head));

    //moveToHead(&head, head, 303);
    //moveToHead(&head, head, 202);
    DisplayLinkedList(head);
    printf("Display after update\n");
    insertElement(&head, head, 11,789);
    DisplayLinkedList(head);

    deleteElement(&head, head, 505);
    deleteElement(&head, head, 6060);
    printf("Display after deleting\n");
    DisplayLinkedList(head);

    freeLinkedListMemory(head);    
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Queue ADT 
 * DATA REQUIRED
 * 1. Data for storing elements
 * 2. Front end pointer - for deleting elements
 * 3. Rear end pointer - for inserting new elements
 * OPERATIONS
 * 1. enqueue()
 * 2. dequeue()
 * 3. isEmpty()
 * 4. isFull()
 * 5. First()
 * 6. Last()
 * */

/* Problems/Drawbacks with using this approach 
 * 1. We cannot reuse the array spaces that has been deleted
 * 2. We can use each space only one time
 * 3. There can be a case when the queue is both full and empty at the same time
 * */

struct Queue {
    int size;
    int front;
    int last;
    int *queue;
};

void enqueue(struct Queue *q, int element) {
    if (q->last == q->size - 1) {
        printf("Queue is full\n");
    } else {
        q->last++;
        q->queue[q->last] = element;
    }
}

int dequeue(struct Queue *q) {
    int element = -1;

    if (q->front == q->last)
        printf("Queue is Empty\n");
    else {
        q->front++;
        element = q->queue[q->front];
    }
    return element;
}

bool isEmpty(struct Queue *q) {
    return (q->front == q->last);
}

bool isFull(struct Queue *q) {
    return (q->last == q->size - 1);
}

void displayQueue(struct Queue q) {
    printf("Displaying elements in the Queue\n[FRONT]->");

    for (int i = q.front + 1; i <= q.last; i++)
        printf("%d ", q.queue[i]);
    printf("<-[REAR]\n");
}

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->queue = (int *)malloc(sizeof(int) * q->size);
    q->front = q->last = -1;
}

int main()
{
    struct Queue q;

    createQueue(&q, 5);

    enqueue(&q, 101);
    enqueue(&q, 202);
    enqueue(&q, 303);
    enqueue(&q, 404);

    displayQueue(q);

    printf("Deleted Value: %d\n", dequeue(&q));
    displayQueue(q);

    free(q.queue);
}

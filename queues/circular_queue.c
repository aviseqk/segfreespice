#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CircularQueue {
    int size;
    int front;
    int last;
    int *queue;
};

void enqueue(struct CircularQueue *q, int element) {
    if ((q->last + 1) % q->size == q->front) {
        printf("CircularQueue is full\n");
    } else {
        q->last = (q->last + 1) % q->size;
        q->queue[q->last] = element;
    }
}

int dequeue(struct CircularQueue *q) {
    int element = -1;

    if (q->front == q->last)
        printf("CircularQueue is Empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        element = q->queue[q->front];
    }
    return element;
}

bool isEmpty(struct CircularQueue *q) {
    return (q->front == q->last);
}

bool isFull(struct CircularQueue *q) {
    return (q->last == q->size - 1);
}

void displayCircularQueue(struct CircularQueue q) {
    printf("Displaying elements in the CircularQueue\n[FRONT]->");

    int i = q.front + 1;
    do {
        printf("%d ", q.queue[i]);
        i = (i + 1) % q.size;
    } while(i != (q.last + 1) % q.size);

    printf("<-[REAR]\n");
}

void createCircularQueue(struct CircularQueue *q, int size) {
    q->size = size;
    q->queue = (int *)malloc(sizeof(int) * q->size);
    q->front = q->last = -1;
}

int main()
{
    struct CircularQueue q;

    createCircularQueue(&q, 5);

    enqueue(&q, 101);
    enqueue(&q, 202);
    enqueue(&q, 303);
    enqueue(&q, 404);
    enqueue(&q, 505);

    displayCircularQueue(q);

    printf("Deleted Value: %d\n", dequeue(&q));
    printf("Deleted Value: %d\n", dequeue(&q));
    printf("Deleted Value: %d\n", dequeue(&q));

    enqueue(&q, 606);
    enqueue(&q, 707);
    displayCircularQueue(q);

    free(q.queue);
}

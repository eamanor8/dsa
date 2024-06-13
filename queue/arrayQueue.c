#include <stdio.h>
#include <stdlib.h>

/* 
    This is the queue implementation using a dynamic array (circular array not applied here).
    Queues follow the First-In First-Out (FIFO) principle.
    
    Common operations that can be performed on a queue are:
        - enqueue: Add an element to the end of the queue.
        - dequeue: Remove an element from the front of the queue.
        - isEmpty: Check if the queue is empty.
        - isFull: Check if the queue is full.
        - displayQueue: Display all elements from front to rear.
*/

struct Queue {
    int size;
    int rear;
    int front;
    int *que;
};

// Initialize the queue by setting size and allocating memory for the queue array.
struct Queue* initQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory Error!\n");
        return NULL;
    }
    printf("Enter size of queue: ");
    scanf("%d", &q->size);
    q->que = (int *)malloc(q->size * sizeof(int));
    if (q->que == NULL) {
        free(q);
        printf("Memory Error!\n");
        return NULL;
    }
    q->front = q->rear = -1;
    return q;
}

// Add an element to the rear of the queue if it is not full.
void enqueue(struct Queue *q, int data) {
    if (q->rear == q->size - 1)
        printf("Queue is Full!\n");
    else {
        q->rear++;
        q->que[q->rear] = data;
        if (q->front == -1) q->front = 0; // Initialize front if it's the first element
    }
}

// Remove and return the front element of the queue if it is not empty.
int dequeue(struct Queue *q) {
    int delData = -1;
    if (q->front == -1 || q->front > q->rear)
        printf("Queue is Empty!\n");
    else {
        delData = q->que[q->front];
        q->front++;
        if (q->front > q->rear) // Reset queue if it becomes empty
            q->front = q->rear = -1;
    }
    return delData;
}

// Display all elements in the queue from front to rear.
void displayQueue(struct Queue q) {
    if (q.front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
        printf("%d ", q.que[i]);
    printf("\n");
}

int main() {
    struct Queue *q = initQueue(); // Initialize the queue
    if (q == NULL) return 1; // Ensure queue was properly initialized

    enqueue(q, 10); // Add elements to the queue
    enqueue(q, 20);
    enqueue(q, 30);

    displayQueue(*q); // Display current queue contents

    printf("Dequeued: %d\n", dequeue(q)); // Dequeue the front element and display it
    displayQueue(*q); // Display queue contents after dequeue

    // Free allocated memory to prevent memory leaks
    free(q->que);
    free(q);
    return 0;
}

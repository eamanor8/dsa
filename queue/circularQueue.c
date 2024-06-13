/*
    Circular Queue is used to solve the drawbacks of arrays implementation of queue.
    The drawback has to do with not being able to use/reuse array spaces from which 
    elements have been deleted.

    One other solution to this problem is to reset the front and rear pointers 
    whenever the queue becomes empty. However we risk the problem of not ever 
    resetting these pointers if the queue never get's empty.

    The idea with the circular queue is that the array location pointed by front doesn't store any element.
    So for an array of size 5, we can only store a maximum of 4 elements.
*/

#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *que;
};

void createQueue(struct Queue *q, int size){
    q->size = size;
    q->que = (int*)malloc(q->size * sizeof(int));
    q->front = q->rear = 0;
}

void enqueue(struct Queue *q, int element){
    // we need to first check if the queue is full before insertion
    if(((q->rear+1) % q->size) == q->front){
        printf("Queue is Full! %d not inserted.\n", element);
        return;
    }
    else {
        q->rear = (q->rear+1)%q->size;
        q->que[q->rear] = element;
    }
}

int dequeue(struct Queue *q){
    int delData = -1;
    // we must ensure that queue is not empty before attempting to delete
    if(q->front == q->rear){
        printf("Queue is Empty!\n");
        return delData;
    }
    else {
        q->front = (q->front+1)%q->size;
        delData = q->que[q->front];
    }
    return delData;
}

void displayCirQueue(struct Queue q){
    int i = q.front+1;
    do{
        printf("%d ", q.que[i]);
        i = (i+1)%q.size;
    } while(i != (q.rear+1)%q.size);

    printf("\n");
}

int main(){
    struct Queue q;
    createQueue(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayCirQueue(q);

    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 50);
    displayCirQueue(q);

    return 0;
}
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

#ifndef Queue_h
#define Queue_h

struct Node{
    struct Node *lChild;
    int data;
    struct Node *rChild;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **que;
};

void createQueue(struct Queue *q, int size){
    q->size = size;
    q->que = (struct Node **)malloc(q->size * sizeof(struct Node *));
    q->front = q->rear = 0;
}

void enqueue(struct Queue *q, struct Node *element){
    // we need to first check if the queue is full before insertion
    if(((q->rear+1) % q->size) == q->front){
        printf("Queue is Full!\n");
        return;
    }
    else {
        q->rear = (q->rear+1)%q->size;
        q->que[q->rear] = element;
    }
}

struct Node* dequeue(struct Queue *q){
    struct Node *delData = NULL;
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

int isEmpty(struct Queue q){
    return q.front == q.rear;
}

#endif /* Queue_h */
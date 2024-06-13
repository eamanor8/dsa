#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

void enqueue(int element){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){ // newNode was not created because heap memory was full 
        printf("Queue is Full!\n");
        return;
    }
    else{
        newNode->data = element;
        newNode->next = NULL;

        if(front == NULL) // this means the queue is empty and this the first element
            front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue(){
    int delData = -1;
    struct Node *tempNode;

    if(front == NULL){
        printf("Queue is Empty!\n");
        return delData;
    }
    else{
        tempNode = front;
        front = front->next;
        delData = tempNode->data;
        free(tempNode);
    }
    return delData;
}

void displayQueue(){
    struct Node *p = front;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    displayQueue();

    printf("Dequeued: %d\n", dequeue());
    displayQueue();

}
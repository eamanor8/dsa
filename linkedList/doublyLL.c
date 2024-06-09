#include <stdio.h>
#include <stdlib.h>

/*
    Doubly LL is such that each node has a pointer to a prev. node as well as pointer to the next node.
    So it helps us traveserse the LL in a bidirectional manner.

*/

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*firstNode=NULL;

void createDLL(int arr[], int arrSize){
    struct Node *tempNode, *lastNode;

    firstNode = (struct Node*)malloc(sizeof(struct Node));
    firstNode->prev = NULL;
    firstNode->data = arr[0];
    firstNode->next = NULL;
    lastNode = firstNode;

    for(int i=1; i<arrSize; i++){
        tempNode = (struct Node*)malloc(sizeof(struct Node));
        tempNode->prev = lastNode;
        tempNode->data = arr[i];
        tempNode->next = lastNode->next;
        lastNode->next = tempNode;
        lastNode = tempNode;
    }
}

void displayDLL(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int lengthDLL(struct Node *p){
    int length =0;
    while(p){
        length+=1;
        p = p->next;
    }
    return length;
}

void insertNodeDLL(struct Node *p, int index, int newData){
    struct Node *tempNode;

    //let's check for validity of the index given
    if(index <0 || index > lengthDLL(p))
        return;
    
    if(index == 0){
        tempNode = (struct Node*)malloc(sizeof(struct Node));
        tempNode->data = newData;
        tempNode->prev = NULL;
        tempNode->next = firstNode;
        firstNode->prev = tempNode;
        firstNode = tempNode;
    }
    else {
        for(int i=0; i<index-1; i++)
            p = p->next;

        tempNode = (struct Node*)malloc(sizeof(struct Node));
        tempNode->data = newData;
        tempNode->prev = p;
        tempNode->next = p->next;

        if(p->next != NULL)
            p->next->prev = tempNode;
        p->next = tempNode; 
    }
}

int deleteNodeDLL(struct Node *p, int index){
    int delData = -1;

    if(index < 1 || index > lengthDLL(p))
        return delData;

    if(index == 1){ // this means we have to delete the firstNode
        firstNode = firstNode->next;
        if(firstNode) // this means if firstNode is not NULL
            firstNode->prev = NULL;
        
        delData = p->data;
        free(p);
    }
    else{
        for(int i=0; i<index-1; i++)
            p = p->next;

        p->prev->next = p->next;
        if(p->next) // if p's next is not NULL
            p->next->prev = p->prev;
        
        delData = p->data;
        free(p);
    }
    return delData;
}

void reverseDLL(struct Node *p){
    struct Node *temp;

    while(p != NULL){
        // interchange next pointers with previous pointers
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if(p!=NULL && p->next == NULL)
            firstNode = p;
    }
}

int main(){
    int A[] = { 3, 6, 9, 12, 15};
    createDLL(A, 5);
    insertNodeDLL(firstNode, 5, 43);
    reverseDLL(firstNode);
    displayDLL(firstNode);
    deleteNodeDLL(firstNode, 1);


    displayDLL(firstNode);

    return 0;
};
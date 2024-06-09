#include <stdio.h>
#include <stdlib.h>

// basic node structure
struct Node {
    int data;
    struct Node *next;
} *headNode;

// let's define a function to create a LL from an array of elements
void createCLL(int arr[], int arrSize){
    struct Node *tempNode, *lastNode;
    headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->data = arr[0];
    headNode->next = headNode; // headNode is pointing back to itself because it's a circular LL
    lastNode = headNode;

    for(int i=1; i<arrSize; i++){
        tempNode = (struct Node*)malloc(sizeof(struct Node)); // we create a new node for each array element
        tempNode->data = arr[i];
        tempNode->next = lastNode->next;
        lastNode->next = tempNode;
        lastNode = tempNode;
    }
}

void displayCLL(struct Node *h){
    do{
        printf("%d ", h->data);
        h = h->next;
    } while(h != headNode);
    printf("\n");
}

int Length(struct Node *h){ // this function returns the number of nodes in the circular LL
    int len = 0;
    do{
        len++;
        h = h->next;
    } while(h != headNode);

    return len;
}

void insertCLL(struct Node *h, int index, int newData){         // for insertion, index 0 means before headNode and index x means after node x
    struct Node *newNode;

    if(index < 0 || index > Length(h)) // checking for invalid indices
        return;

    if(index == 0){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newData;
        
        if(headNode == NULL){   // if the node being inserted is the first node,
            headNode = newNode;
            headNode->next = headNode; // we make it point back to itself since the LL is circular
        }
        else{
            while(h->next != headNode) h = h->next; // if there are other nodes, we move the pointer h until the last node
            h->next = newNode;
            newNode->next = headNode;
            headNode = newNode;
        }
    }
    else {
        for(int i=0; i<index-1; i++) h = h->next; // we move pointer h until we reach the node after which we want to insert the newNode.
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newData;
        newNode->next = h->next;
        h->next = newNode;  
    }
}

int deleteNodeCLL(struct Node *h, int index){
    struct Node *q;
    int delData;

    //let's check for valid index
    if(index <= 0 || index > Length(headNode))
        return -1;       // -1 means no node was deleted
    
    if(index == 1){         // meaning we're to delete the headNode
        while(h->next != headNode) h = h->next;
        delData = headNode->data; 

        // check if headNode is the only node, is so, then the pointer h and headNode will be equal so
        if(headNode == h){
            free(headNode);
            headNode = NULL;
        }
        else { // it means headNode is not the only node
            h->next = headNode->next;
            free(headNode);
            headNode = h->next; // make the next node as headNode
        }
    } 
    else{
        for(int i=0; i<index-2; i++)
            h = h->next; // move pointer to the node just before the one to be deleted

        q = h->next;    // let q point to the node to be deleted
        h->next = q->next;
        delData = q->data;
        free(q);
    }  

    return delData;
}

int main(){
    int A[] ={2, 4, 6, 8, 10};
    createCLL(A, 5);
    // insertCLL(headNode, 5, 15);

    deleteNodeCLL(headNode, 0);

    displayCLL(headNode);

    return 0;
}
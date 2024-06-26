#include <stdio.h>
#include "Queue.h"

struct Node *root = NULL;

void createTree(){
    struct Node *p, *t;
    int nodeValue;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &nodeValue);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = nodeValue;
    root->lChild = root->rChild = NULL;

    enqueue(&q, root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &nodeValue);

        if(nodeValue != -1){ // we use -1 to denote that either the left or right child of a node is NULL
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = nodeValue;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &nodeValue);

        if(nodeValue != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = nodeValue;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lChild);
        printf("%d ", p->data);
        inOrder(p->rChild);
    }
}

void postOrder(struct Node *p){
    if(p){
        postOrder(p->lChild);
        postOrder(p->rChild);
        printf("%d ", p->data);
    }
}

void levelOrder(struct Node *root){
    struct Queue q;
    createQueue(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while(!isEmpty(q)){
        root = dequeue(&q);

        if(root->lChild){
            printf("%d ", root->lChild->data);
            enqueue(&q, root->lChild);
        }
        if(root->rChild){
            printf("%d ", root->rChild->data);
            enqueue(&q, root->rChild);
        }
    }
}

int countNodes(struct Node *root){
    if(root)
        return countNodes(root->lChild) + countNodes(root->rChild) +1;
    return 0;
}

int countLeafNodes(struct Node *root){
    int x, y;
    if(root){
        x = countLeafNodes(root->lChild);
        y = countLeafNodes(root->rChild);

        if(root->lChild==NULL && root->rChild==NULL) // with a slight change to this condition we can get the function to return various values;
                                                     // Nodes with degree 2 : if(root->lChild!=NULL && root->rChild!=NULL)
                                                     // Nodes with degree 1 or 2 (all internal nodes): if(root->lChild!=NULL || root->rChild!=NULL)
                                                     // Nodes with degree 1 : if((root->lChild!=NULL && root->rChild==NULL) || (root->lChild==NULL && root->rChild!=NULL))
                                                        // this last condition is nothing but XOR on lChild and rChild. So we can rewrite it as
                                                        //      if(root->lChild != NULL ^ root->rChild != NULL) 
            return x+y+1;
        else 
            return x+y;
    }
    return 0;
}

int treeHeight(struct Node *root){
    int x = 0, y=0;
    if(root == NULL)
        return 0;
    
    x = treeHeight(root->lChild);
    y = treeHeight(root->rChild);
    
    if(x>y)
        return x+1;
    else 
        return y+1;
}

int main(){

    createTree();
    printf("\nPre-Order Traversal: ");
    preOrder(root);

    printf("\nIn-Order Traversal: ");
    inOrder(root);

    printf("\nPost-Order Traversal: ");
    postOrder(root);

    printf("\nLevel-Order Traversal: ");
    levelOrder(root);
    printf("\n");

    printf("Count: %d\n", countNodes(root));
    printf("Height: %d\n", treeHeight(root));

    return 0;
}
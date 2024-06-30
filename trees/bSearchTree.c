#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lChild;
    int data;
    struct Node *rChild;
} *root =NULL;

struct Node* rSearchBT(struct Node *t, int key){ // this is a recursive function
    if(t == NULL)
        return NULL;
    if(key == t->data)
        return t;
    else if(key < t->data)
        return rSearchBT(t->lChild, key);
    else
        return rSearchBT(t->rChild, key);
}

struct Node* iSearchBT(int key){ // this is an iterative search
    struct Node *t = root;
    while(t != NULL){
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->lChild;
        else
            t = t->rChild;
    }
    return NULL;
}

// the idea is that we need to first search the BT to be sure the data doesn't already exist since duplicates are not allowed in binary search trees
// before making an insertion
void insertBST(int newData){ // iterative version
    struct Node *t = root;
    struct Node *r, *tempNode;

    if(root == NULL){ // this condition is true when the data being inserted is the first node
        tempNode = (struct Node *)malloc(sizeof(struct Node));
        tempNode->data = newData;
        tempNode->lChild = tempNode->rChild = NULL;
        root = tempNode;
        return;
    }
    while(t != NULL){
        r = t;
        if(newData == t->data)
            return;
        else if(newData < t->data)
            t = t->lChild;
        else 
            t = t->rChild;
    }

    tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->data = newData;
    tempNode->lChild = tempNode->rChild = NULL;

    if(tempNode->data < r->data)
        r->lChild = tempNode;
    else 
        r->rChild = tempNode;
}

struct Node * rInserAVL(struct Node *p, int newData){
    struct Node *t = NULL;
    if(p == NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = newData;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if(newData < p->data)
        p->lChild = rInserAVL(p->lChild, newData);
    else if(newData > p->data)
        p->rChild = rInserAVL(p->rChild, newData);

    return p;
}

int Height(struct Node *p){
    int x, y;
    if(p==NULL) return 0;

    x = Height(p->lChild);
    y = Height(p->rChild);
    return x>y ? x+1 : y+1;
}

/*
    When performing a delete operation in a BST, there are various scenarios that could arise.
    1. If the node being deleted is a leaf node: then we just delete it and make it's parent point to null it the deleted node's place
    2. if the Node being deleted has only only one child.: then the child takes it's place
    3. the node being deleted has 2 or more children: then we can either make
        * it's inOrder predecessor or inOrder successor take it's place. That way we don't have to make a lot of changes to the BST.

        inOrder predecessor: the rightmost leafNode on the left subtree
        inOrder successor: the leftmost leafNode of the right subtree
*/

struct Node* inPredecessor(struct Node *p){
    while(p && p->rChild != NULL)
        p = p->rChild;
    
    return p;
}

struct Node* inSuccessor(struct Node *p){
    while(p && p->lChild != NULL)
        p = p->lChild;
    
    return p;
}

struct Node* rDeleteNode(struct Node *p, int delData){
    struct Node *q;

    if(p==NULL)
        return NULL;
    if(p->lChild==NULL && p->rChild==NULL){ // meaning p is pointing on a leafNode
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }

    if(delData < p->data)
        p->lChild = rDeleteNode(p->lChild, delData);
    else if(delData > p->data)
        p->rChild = rDeleteNode(p->rChild, delData);
    else{ // at this point, we've found the node to be deleted and p is the pointer on that node
        if(Height(p->lChild) > Height(p->rChild)){ // we are choosing to use either successor or predecessor based on the subtree with longer height
            q = inPredecessor(p->lChild);
            p->data = q->data; // we are making the predecessor node take the place of the node being deleted
            p->lChild = rDeleteNode(p->lChild, q->data); // we are recursively deleting the predecessor after copying it.
        } 
        else {
            q = inSuccessor(p->rChild);
            p->data = q->data; // we are making the successor node take the place of the node being deleted
            p->rChild = rDeleteNode(p->rChild, q->data); // we are recursively deleting the successor after copying it.
        }
    }
    return p;
}

// NB: Inorder traversal of a binary search tree always yields the node elements in sorted order.
void inOrder(struct Node *p){
    if(p){
        inOrder(p->lChild);
        printf("%d ", p->data);
        inOrder(p->rChild);
    }
}

int main(){
    struct Node *searchResult;

    // insertBST(10);
    // insertBST(5);
    // insertBST(20);
    // insertBST(8);
    // insertBST(30);

    root = rInserAVL(root, 50);
    rInserAVL(root, 10);
    rInserAVL(root, 40);
    rInserAVL(root, 20);
    rInserAVL(root, 30);

    rDeleteNode(root, 50);


    inOrder(root);
    printf("\n");

    int searchItem = 20;
    searchResult = iSearchBT(searchItem);
    if(searchResult != NULL)
        printf("Element %d is found.\n", searchResult->data);
    else
        printf("Element %d not Found!\n", searchItem);

    return 0;
}
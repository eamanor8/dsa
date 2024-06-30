/*
    AVL trees helps us to dealing with the problem of balancing binary trees.
    
    balance factor = height of left subtree - height of right subtree
        in short bf = hl - hr = {1, 0, 1}
        if |bf| = |hl-hr| <= 1 then that node is balanced
        if |bf| = |hl-hr| > 1 then the node is imbalanced

    To balance and avl tree, we perform rotations

*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node *lChild;
    int data;
    int height;
    struct Node *rChild;
} *root=NULL ;

int nodeHeight(struct Node *p){
    int hl, hr;
    hl=p && p->lChild ? p->lChild->height : 0; // height of left subtree is assigned as the height of p's lChild if p!=NULL AND p has a left child otherwise 0
    hr=p && p->rChild ? p->rChild->height : 0;

    return hl > hr ? hl+1 : hr+1;
}

int balanceFactor(struct Node *p){
    int hl, hr;
    hl = p && p->lChild ? p->lChild->height : 0; 
    hr = p && p->rChild ? p->rChild->height : 0; // height of right subtree is assigned as the height of p's rChild if p!=NULL AND p has a right child otherwise 0

    return hl-hr;
}

struct Node * LLRotation(struct Node *p){
    struct Node *pl = p->lChild;
    struct Node *plr =  pl->rChild;

    pl->rChild = p;
    p->lChild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root==p)
        root = pl; //p's lChild becomes the new rootNode after LLRotation
    
    return pl;
}

struct Node * RRRotation(struct Node *p){
    struct Node *pr = p->rChild;
    struct Node *prl =  pr->lChild;

    pr->lChild = p;
    p->rChild = prl;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if(root==p)
        root = pr; //p's lChild becomes the new rootNode after LLRotation
    
    return pr;
}

struct Node * LRRotation(struct Node *p){
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;

    pl->rChild = plr->lChild;
    p->lChild = plr->rChild;
    plr->lChild = pl;
    plr->rChild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root==p)
        root = plr;
    
    return plr;
}

struct Node * RLRotation(struct Node *p){
    struct Node *pr = p->rChild;
    struct Node *prl = pr->lChild;

    pr->lChild = prl->rChild;
    p->rChild = prl->lChild;
    prl->rChild = pr;
    prl->lChild = p;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root==p)
        root = prl;
    
    return prl;
}

struct Node * rInsertAVL(struct Node *p, int newData){
    struct Node *t = NULL;
    if(p == NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = newData;
        t->height=1;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if(newData < p->data)
        p->lChild = rInsertAVL(p->lChild, newData);
    else if(newData > p->data)
        p->rChild = rInsertAVL(p->rChild, newData);
    
    p->height = nodeHeight(p); //updating the height of every node after insertion

    if(balanceFactor(p)==2 && balanceFactor(p->lChild)==1)
        return LLRotation(p);
    else if(balanceFactor(p)==2 && balanceFactor(p->lChild)==-1)
        return LRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->lChild)==-1)
        return RRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->lChild)==1)
        return RLRotation(p);

    return p;
}

int main(){

    root = rInsertAVL(root, 10);
    rInsertAVL(root, 5);
    rInsertAVL(root, 3);
    
    return 0;
}

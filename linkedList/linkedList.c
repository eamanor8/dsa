#include <stdio.h>
#include <stdlib.h>

/*
    The LinkedList data structure is a node that has a data portion and a pointer to the next node. 
    If the current node is the last node, then it's next pointer points to NULL

*/

struct Node {
    int data;
    struct Node *next;  // this is a self-referential pointer
} *first = NULL, *second=NULL, *third=NULL;           // this is a global pointer to the Node structure

void createLL1(int arr[], int arrSize){
    int i;
    struct Node *temp, *last;

    first = (struct Node*)malloc(sizeof(struct Node)); // we are accessing the global first variable and assigning it memory in heap
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(i=1; i<arrSize; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp; //this means last points to the same address as temp
    }
}

void createLL2(int arr[], int arrSize){
    int i;
    struct Node *temp, *last;

    second = (struct Node*)malloc(sizeof(struct Node)); // we are accessing the global first variable and assigning it memory in heap
    second->data = arr[0];
    second->next = NULL;
    last = second;

    for(i=1; i<arrSize; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp; //this means last points to the same address as temp
    }
}

int countItemsLL(struct Node *p){ // this function returns the number of items in the LL
    int lengthLL = 0;
    while(p != NULL){
        lengthLL ++;
        p = p->next;
    }
    return lengthLL;
}

void displayLL(struct Node *p){ // ITERATIVE VERSION
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;            // we move the pointer to the next node
    }
    printf("\n");
}

void RdisplayLL(struct Node *p){ // RECURSIVE VERSION OF THE DISPLAY FUNCTION
    if(p != NULL){
        RdisplayLL(p->next);
        printf("%d ", p->data); // because we make a recursive function call before printing the data,
                                // printing is done in the reverse order of the LL.
    }
}

int findMax(struct Node *p){
    int max= INT16_MIN;
    while(p != NULL){
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    printf("Maximum data in the LL is %d \n", max);
    return max;
}

int searchLL(struct Node *p, int query){
    while(p!=0){
        if (query == p->data){
            printf("Element %d Found!\n", query);
            return 1;
        }
        p = p->next; // move to the next node
    }
    printf("Element %d Not Found!\n", query);
    return 0;
}

struct Node* moveToHead(struct Node *p, int query){      // Assuming we want to improve subsequent search operation by moving the search item to
                                                         // the beginning of the LL so that it is found faster in the next search operation.
    struct Node *prev = NULL;
    while (p != NULL){
        if(query == p->data){
            prev->next = p->next;
            p->next = first;
            first = p;
            printf("Element %d Found!\n", p->data);
            return p;
        }
        prev = p;
        p = p->next;
    }
    printf("Element %d Not Found!\n", query);
    return NULL;
}

/*
    There are two ways of inserting an item into a LL.
    1. Before first node
    2. At an index beyond the first node.
*/

void insertLL(struct Node *p, int index, int item){
    struct Node *newNode;

    if(index < 0 || index > countItemsLL(p)) // checking if the given index is valid,
        return;                              // if not abort the function
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    
    if(index == 0){ // Before first node
        newNode->next = first;
        first = newNode;
    }
    else if(index > 0){ // At a index after first
    
        for(int i=0; i<index-1 && p!=NULL; i++)
            p = p->next;
    
        if(p){
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}

void appendLL(int item) {
    struct Node *newNode, *lastNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    // Check if the linked list is empty
    if (first == NULL) {
        first = newNode;  // If list is empty, both first and last point to the new node
    } else {
        // Traverse the list to find the last node
        lastNode = first;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;  // Append the new node
    }
}

void sortedInsertLL(struct Node *p, int item){
    struct Node *newNode, *lastNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    //if the LL is empty then the item should be the first node
    if(first == NULL)
        first = newNode;
    else {
        while(p && p->data < item){
            lastNode = p;
            p = p->next;
        }
        // now if the item to be inserted is the smallest then it should come before the first node
        if(p == first){
            newNode->next = first;
            first = newNode;
        }
        else { // means the item being inserted is not the smallest
            newNode->next = lastNode->next;
            lastNode->next = newNode;
        }
    }
}

int deleteNode(struct Node *p, int index){
    struct Node *delNode=NULL;
    int x=-1; // this would hold the deleted value
    p = first;

    //let's handle invalid indices
    if(index <1 || index > countItemsLL(p)){
        return -1;
    }

    //case1: deleting first node
    if(index == 1){
        delNode = first;
        x = first->data;
        first = first->next;
        free(delNode);
        return x;
    }
    else {
        for(int i=1; p!=NULL && i<index; i++){
            delNode = p;
            p = p->next;
        }
        delNode->next = p->next;
        x = p->data;
        free(p);        // deallocate memory for deleted node
        return x;
    }
}

void isSortedLL(struct Node *p){
    int x = INT16_MIN;
    while(p!=NULL){
        if(p->data < x){
            printf("LL Not Sorted!\n");
            return;
        }
        else {
            x = p->data;
            p = p->next;
        }
    }
    printf("LL is Sorted!\n");
    return;
}

void removeDuplicates(struct Node *p){ // note that the pointer parameter passed is always pointing to the first node in the LL
    struct Node *tempNode = p->next;

    while(tempNode != NULL){
        if(tempNode->data != p->data){
            p = tempNode;
            tempNode = tempNode->next;
        }
        else {
            p->next = tempNode->next;
            free(tempNode);
            tempNode = p->next;
        }
    }
}

/*
    to reverse a LL we can use one of two methods:
    1. Reversing Elements: thus interchanging the elements, for eg. 1st with last
        this can be done by copying the data elements into an auxiliary array and then
        reverse copy the array elements into the linked list.
    2. Reversing Links.
*/
void reverseElements(struct Node *p){
    int i=0;
    int arr[countItemsLL(p)];
    // copy data in LL into array
    while(p!=NULL){
        arr[i] = p->data;
        p = p->next;
        i++;
    }
    p = first; // take pointer p back to the first node
    i--;    // i as a counter goes outside the array so we need to decrement once 
            // before we start using it again

    // reverse copy array elements into LL
    while(p != NULL){
        p->data = arr[i];
        p = p->next;
        i--;
    }
}

/*
    It's much more efficient and preferred to reverse a LL by reversing the links rather than
    moving data elements around. This is because the data in a LL may be huge and moving data around
    would be costly.
*/

void reverseLinks(struct Node *p){
    struct Node *q=NULL, *r=NULL;       // picture pointers r, q, p as sliding pointers that following each 
                                        // each other one step at a time. r->q->p
    p = first;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next; // up to this point is where we were sliding the pointers
        q->next = r; // because pointer q is in the middle, we reverse just that after sliding
    }
    first = q;  // first must be moved to q because p points to null at the last iteration
}

void concatLL(struct Node *p, struct Node *q){
    third = p; // third is a global pointer so it points to the concatenated LL

    // we first move the pointer on the first LL to the last node
    while(p->next != NULL){
        p = p->next;
    }

    // then we make the last node's pointer of the first LL 
    // point to the first node of the second LL
    p->next = q;
}

void mergeSortedLL(struct Node *p, struct Node *q){
    struct Node *last;

    if(p->data < q->data){
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p && q){  // this means while p!=NULL && q!==NULL
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    // if one of the LL ends, then we make it's last node point to the remaining nodes of the other LL
    if(p) last->next = p;
    if(q) last->next = q;
}

// It's important to for us to be able to check whether a LL is linear or contains a loop.

int isLoop(struct Node *f){     // the idea here is to use two pointers which both start from the first node
                                // but one will move one node at a time while the other moves two nodes at a time.
                                // If there is a loop, the two pointers will eventually meet at some node, 
                                // otherwise, the pointer moving two nodes at a time will reach NULL first
    
    struct Node *p, *q;         // let p move one step at a time while q moves 2 steps 
    p=q=f;              // remember that f is a pointer to the first node of the LL. so we're setting both p & q to point to the first node

    do{
        p = p->next;    // move p to the next node;
        q = q->next;
        q = q != NULL ? q->next : q; // if q is not equal to null, it moves one step forward, else it remains where it is (still null)
    }  while(p && q && p!=q); // the loop terminates if any of these conditions fail

    if(p==q){
        printf("LL contains a loop.\n");
        return 1;
    }
    else{
        printf("LL is linear.\n");
        return 0;
    }
}

int midNodeLL(struct Node *p){
                                // There are several ways by which to find the middle element or node in a LL
    struct Node *q;             // 1st method: find the length the LL and then divide that by 2 to get the index of the 
                                // LL. This approach would require us to scan the LL 2x which will take more time than
                                // when we scan it just once.

                                // 2nd method: we use two pointers to scan the list once. We move pointer q 2x while we move
                                // pointer p once in each iteration. We when q becomes NULL, then pointer p will be on the 
                                // middle node. This saves us some time since we scan the LL only once
    p = q = first;

    while(q){ // while q != NULL
        q = q->next;
        if(q)
            q = q->next;
        if(q)
            p = p->next;
    }
    return p->data;
}

int main() {

    // int A[] = {3, 5, 7, 10, 15, 2, -1, 12};
    // struct Node *temp;
    // createLL1(A, 8);
    // displayLL(first);
    // findMax(first);
    // temp = moveToHead(first, 17);
    // temp = moveToHead(first, 12);
    // temp = moveToHead(first, 15);
    // temp = moveToHead(first, 7);

    // int B[] = {3, 5, 7};
    // createLL1(B, 3);
    // insertLL(first, 0, 79);
    // insertLL(first, 2, 10);
    // insertLL(first, 5, 23);

    // int C[] = {10, 20, 30, 40, 50};
    // createLL1(C, 5);
    // sortedInsertLL(first, 35);
    // sortedInsertLL(first, 20);

    // int D[] = {10, 20, 30, 40, 50};
    // createLL1(D, 5);
    // printf("Deleted Element: %d \n", deleteNode(first, 1));

    // isSortedLL(first);

    // int E[] = {3, 5, 5, 8, 8, 8, 10};
    // createLL1(E, 7);
    // removeDuplicates(first);

    // int F[] = {3, 5, 7, 9, 11};
    // createLL1(F, 5);
    // // reverseElements(first);
    // reverseLinks(first);

    // int G[] = {10, 20, 30, 40, 50};
    // int H[] = {5, 15, 25, 35, 45};
    // createLL1(G, 5);
    // createLL2(H, 5);
    
    // printf("First: ");
    // displayLL(first);

    // printf("\nSecond: ");
    // displayLL(second);
    // printf("\n");

    // // concatLL(second, first);
    // mergeSortedLL(first, second);
    // displayLL(third);

    // // let's test for loops
    // struct Node *t1, *t2;
    // int I[]={10, 20, 30, 40, 50};
    // createLL1(I, 5);
    // t1 = first->next->next; // this pointer points to the third node (30)
    // t2 = first->next->next->next->next; // this points to the fifth node (50)
    // // now let's form a loop in this LL
    // t2->next = t1;
    // isLoop(first);

    // find Middle element or node
    int J[]={10, 20, 30, 40, 50, 60, 70};
    createLL1(J, 7);
    printf("Middle element: %d \n", midNodeLL(first));

    return 0;
}
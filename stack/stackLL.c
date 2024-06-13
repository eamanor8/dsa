#include <stdio.h>
#include <stdlib.h>

/*
    This is the stack implementation using the LinkedList data structure.
    The LinkedList data structure is a node that has a data portion and a pointer to the next node.
    If the current node is the last node, then its next pointer points to NULL.
*/

struct Node {
    int data;
    struct Node *next;  // This is a self-referential pointer.
};

struct Stack {
    struct Node *top;  // Pointer to the top of the stack.
};

// Initialize the stack to be empty
void initStack(struct Stack *s) {
    s->top = NULL;
}

// Function to push an element onto the stack
void push(struct Stack *s, int element) {
    struct Node *tempNode = (struct Node*)malloc(sizeof(struct Node)); // Dynamically allocate a new node
    if (tempNode == NULL) {  // Check if the heap is full and malloc has failed
        printf("Stack Overflow!\n");
    } else {
        tempNode->data = element; // Set the data part
        tempNode->next = s->top; // Point next to the previous top
        s->top = tempNode; // Update top to the new node
    }
}

// Function to pop the top element from the stack
int pop(struct Stack *s) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;  // Indicate underflow
    } else {
        struct Node *temp = s->top; // Temp pointer to top
        int poppedData = temp->data; // Retrieve data to return
        s->top = temp->next; // Move top to next node down
        free(temp); // Release the old top node
        return poppedData;
    }
}

// Function to display all elements from top to bottom
void displayStack(struct Stack *s) {
    struct Node *p = s->top; // Start from top
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next; // Move to next node
    }
    printf("\n");
}

int main() {
    struct Stack st;
    initStack(&st); // Initialize the stack

    push(&st, 10); // Push elements onto the stack
    push(&st, 20);
    push(&st, 30);

    displayStack(&st); // Display all elements in the stack

    printf("Popped: %d\n", pop(&st)); // Pop the top element and display it
    displayStack(&st); // Display all elements after the pop

    return 0;
}

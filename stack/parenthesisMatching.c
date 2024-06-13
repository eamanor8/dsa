#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
} *Top = NULL; // Global pointer to the top of the stack

// Pushes an element onto the top of the stack
void push(char element) {
    struct Node *tempNode = (struct Node*)malloc(sizeof(struct Node));
    if (tempNode == NULL) {
        printf("Stack Overflow!\n"); // Stack overflow error if malloc fails
    } else {
        tempNode->data = element;
        tempNode->next = Top;
        Top = tempNode; // Update top pointer
    }
}

// Pops the top element from the stack and returns it
char pop() {
    char delData = -1; // Default error value if the stack is empty
    if (Top == NULL) {
        printf("Stack Underflow!\n");
    } else {
        struct Node *temp = Top; // Temporary pointer to the top node
        Top = Top->next; // Move top to the next node
        delData = temp->data; // Retrieve data from the node
        free(temp); // Free memory allocated for the top node
    }
    return delData;
}

// Function to display the stack from top to bottom
void displayStack() {
    struct Node *p = Top;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next; // Move to the next node
    }
    printf("\n");
}

// Retrieves the top element of the stack without popping it
char stackTop() {
    return (Top != NULL) ? Top->data : -1; // Return -1 if stack is empty
}

// Checks whether the given open and close characters are matching pairs
int matches(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

// Clears the stack completely
void clearStack() {
    while (Top != NULL) {
        pop();
    }
}

// Determines if the parentheses in the expression are balanced
int isBalanced(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]); // Push to stack if open parenthesis
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (Top == NULL) // Stack cannot be empty if closing parenthesis found
                return 0;
            else if (matches(stackTop(), exp[i])) {
                pop(); // Pop only if there is a matching opening parenthesis
            } else {
                return 0; // Mismatch found
            }
        }
    }
    return (Top == NULL) ? 1 : 0; // If stack is empty, parentheses are balanced
}

int main() {
    char *exp = "((a+b)*(c-d))";
    char *exp2 = "{([a+b]*[c-d])/e}";

    printf("%d \n", isBalanced(exp));  // Check if parentheses in exp are balanced
    printf("%d \n", isBalanced(exp2)); // Check if parentheses in exp2 are balanced

    return 0;
}

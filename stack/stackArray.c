#include <stdio.h>
#include <stdlib.h>

/*
    The stack ADT is how data in stack is represented and the operations that can be performed on that data.
    Stack can be implemented using either of the two physical data structures that we have already discussed 
    in arrays and LinkedLists.

    Stack works based on the Last In First Out paradigm

    The necessary operations for a stack are: Push, Pop, Peek, Top, isFull, isEmpty

*/

struct Stack{
    int size;
    int top; // when the stack is empty, this is set as -1;
    int *S; // this would be a pointer to the first address of the array that stores the stack elements.
            // this array would be dynamically created in heap memory
};

void createStack(struct Stack *st){
    printf("Enter stack size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int)); //we create the dynamic array of needed size
}

void displayStack(struct Stack st){
    if(st.top == -1){
        printf("Stack is Empty! Nothing to display.\n");
        return;
    }

    for(int i=st.top; i>=0; i--)
        printf("%d ", st.S[i]);
    
    printf("\n");
}

void push(struct Stack *st, int element){
    if(st->top == st->size-1) // this means the stack is full so we can add anymore elements
        printf("Stack Overflow!\n");
    else{
        st->top++;
        st->S[st->top] = element;
    }
}

int pop(struct Stack *st){
    int delData = -1;
    if(st->top == -1) // this means stack is empty and there is nothing to delete/pop
        printf("Stack Underflow!\n");
    else{
        delData = st->S[st->top];
        st->top--;
    }
    return delData;
}

int peek(struct Stack st, int index){ // peek returns the value at the specified index in the stack
    int peekData = -1;
    //let's first check whether the given index is valid
    if(st.top-index+1 < 0)
        printf("Invalid index!\n");
    
    peekData = st.S[st.top-index+1];
    return peekData;
}

int isEmpty(struct Stack st){
    if(st.top == -1) // stack is empty
        return 1; // true
    else
        return 0;
}

int isFull(struct Stack st){
    if(st.top == st.size-1) //stack is full
        return 1; 
    else
        return 0; // false
}

int stackTop(struct Stack st){ // this function returns the topmost element
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main(){
    struct Stack st;
    createStack(&st);
    
    push(&st, 10);
    push(&st, 20);

    pop(&st);
    pop(&st);

    displayStack(st);
    
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
    Pointers are address variables that store the memory address of another variable.
    Pointers do not store the value of the variable, they store the address of the variable.

    Why use pointers?
    - Pointers are used to access memory locations that are external to the program. eg: heap memory, hard disk, etc.
    - Pointers are used to pass large structures so that the structure is not passed by value.
    - Pointers are used to return multiple values from a function.

    Any variables defined within a function are stored in the stack memory.
    To store data in the heap memory, we use the malloc() function.
    
    The malloc() function returns a void pointer to the memory location in the heap memory. 
    So we need to typecast it to the appropriate data type.
    eg: int *p = (int *)malloc(5*sizeof(int)); // p is a pointer to an integer array of size 5 --> the syntax is C-style

        C++ provides a new operator to allocate memory in the heap memory.
        eg: int *p = new int[5]; // p is a pointer to an integer array of size 5 --> the syntax is C++-style

*/

int main() {
    int x = 10;
    int *p; // pointer variable declaration
    p = &x; // p stores the address of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Value of *p: " << *p << endl;

    return 0;
}
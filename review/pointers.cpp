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

struct rectangle
{
    int length;
    int breadth;
};


int main() {
    cout << "\n Integer POINTERS\n" << endl;
    int x = 10;
    int *p; // pointer variable declaration
    p = &x; // p stores the address of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl; // &x is the address of x
    cout << "Value of p: " << p << endl; // p is the address of x
    cout << "Address of p: " << &p << endl;
    cout << "Value of *p: " << *p << endl;  // *p is the value stored at the address p

    // Pointer Sizes: irrrespective of the data type, the size of a pointer is the same
    cout << "\n POINTER SIZES\n";
    cout << "Size of int pointer: " << sizeof(p) << endl;
    cout << "Size of char pointer: " << sizeof(char *) << endl;
    cout << "Size of float pointer: " << sizeof(float *) << endl;
    cout << "Size of double pointer: " << sizeof(double *) << endl;

    struct rectangle *stp; // initialize a pointer to a struct
    cout << "Size of struct pointer: " << sizeof(stp) << endl;


    cout << "\n ARRAY IN STACK MEMORY\n" << endl;
    // Pointer to an array -- this is stored in the stack frame of the main function
    int arr[2] = {1, 2, };
    int *q = arr; // q stores the address of the first element of the array
        // q = &arr[0]; // this is equivalent to the above statement
    
    for(int i = 0; i < 2; i++) {
        cout << "Value of arr[" << i << "]: " << arr[i] << endl;
        cout << "Address of arr[" << i << "]: " << &arr[i] << endl;
        cout << "Value of q[" << i << "]: " << q[i] << endl;
        cout << "Address of q[" << i << "]: " << &q[i] << endl;
    }

    cout << "\n ARRAYS IN HEAP MEMORY\n" << endl;
    // Pointer to an array in the heap memory
    int *r = new int[2]; // alternative syntax: int *r = (int *)malloc(5*sizeof(int));
    for(int i = 0; i < 2; i++) {
        r[i] = i+3;
    }
    for(int i = 0; i < 2; i++) {
        cout << "Value of r[" << i << "]: " << r[i] << endl;
        cout << "Address of r[" << i << "]: " << &r[i] << endl;
    }

    // Free dynamically allocated memory
    delete [] r; // alternative syntax: free(r); -- C-style

    return 0;
}
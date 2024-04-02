#include <iostream>
#include <stdio.h>

using namespace std;

/*
    NB: Arrays can never be passed by value, they are only passed by address.
    The address of the first element is passed
*/

// A function that takes an array as a parameter
void printArray(int *Arr, int size){
    cout << "Array elements: ";
    for(int i=0; i<size; i++){
        cout << Arr[i] << " ";
    }
}


// A function that returns  an array
int* returnArray(int size){
    int *p;
    p = (int *)malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        p[i] = i+1;
    }
    return p;
}

int main() {
    int A[]={2, 5, 8, 17, 43};
    int size = sizeof(A)/sizeof(A[0]);
        // NB: sizeof(A) gives the size of the array in bytes so we divide by the size of the first element to get the number of elements in the array
    printArray(A, size);

    int *B;
    B = returnArray(5);
    cout << "\nPrinting array returned by function\n";
    printArray(B, 5);

    free(B);
    return 0;
}
#include <iostream>

/*
    LOWER TRIANGULAR MATRIX
    For a lower traiangular matrix, the most important things to note are:
        1. an entry of the matrix is zero only when the row number for that entry is less than the column number
        2. an entry is non-zero if row <= column
        3. total number of non-zero elements that must be stored is n(n+1)/2
        4. we need this to now the size of array to create.

    Now to access the matrix in a row-major approach, we need a formula to retrieve the elements for the array storing 
    the elements: row(row-1)/2 + (col-1)

    SYMMETRIC MATRIX
    A matrix is symmetric if the the entry M[i, j] == M[j, i]
    So to save space, we should only store either the upper or lower traingular part of a symmetric matrix
*/

int main(){

    return 0;
}
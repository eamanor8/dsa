#include <stdio.h>

struct Matrix {
    int A[10]; // a fixed-size array to store the diagonal elements of the matrix
    int n;  // this denotes the size of the matrix
};

void setDiagonal(struct Matrix *mat, int row, int col, int value){
    if(row == col)
        mat->A[row-1] = value;
}

int getDiagonal(struct Matrix mat, int row, int col){
    if(row == col)
        return mat.A[row-1];
    else
        return 0;
}

void displayMatrix(struct Matrix mat){
    for(int i=0; i<mat.n; i++){
        for(int j=0; j<mat.n; j++){
            if(i==j)
                printf("%d ", mat.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}



int main(){

    struct Matrix M;
    M.n=4;

    setDiagonal(&M, 1, 1, 5);
    setDiagonal(&M, 2, 2, 8);
    setDiagonal(&M, 3, 3, 3);
    setDiagonal(&M, 4, 4, 7);

    displayMatrix(M);

    return 0;
}
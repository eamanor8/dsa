#include <stdio.h>

/*
    SelectionSort works by scanning the list, and during each pass, the smallest element is swapped 
    with the first unsorted element. Hence after k-passes, we get k sorted elements in the first k-positions
    of the list. 
    In SelectionSort, we select a position and find the element for that position.

    QuickSort: this sorting technique works on the idea that an element is in a sorted position if all elements
    before it are smaller and all element after it are greater. For the following lists, we want to find just one
    element that is in a sorted position.
        List A: 10, 30, 20, 70, 40, 90, 80 => 10
        List B: 80, 70, 40, 30, 20, 10, 90 => 90
        List C: 40, 30, 20, 50, 90, 70, 80 => 50
    In QuickSort, we select an element and find it's position.
*/

void Swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n){
    int i, j, flag;

    for(i=0; i<n-1; i++){
        flag = 0;
        for(j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) //it means the array is already sorted
            break;
    }
}

void InsertionSort(int A[], int n){
    int i, j, x;
    for(i=1; i<n; i++){ //for each pass
        j=i-1;
        x = A[i]; 
        while(j>-1 && A[j]>x){ // shifting elements in a particular pass
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n){
    int i, j, k;
    for(i=0; i<n-1; i++){ // this for loop is for the number of passes
        for(j=k=i; j<n; j++){
            if(A[j] < A[k])
                k = j;
        }
        Swap(&A[i], &A[k]);
    }
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i=low, j=high;

    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);

        if(i<j)
            Swap(&A[i], &A[j]);
    }while(i < j);

    Swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high){
    int j;
    if(low < high){
        j = partition(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j+1, high);
    }
}

void Merge1(int A[], int low, int mid, int high){ // This function is to sort a single array that contains a combined list of sorted elements
    int i=low, j=mid+1, k=low;
    int B[100];

    while(i<=mid && j<=high){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }  

    // copying remaining elements if one section ends
    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=high; j++)
        B[k++] = A[j];
    
    // copy sorted elements back into original array
    for(int i=low; i<=high; i++)
        A[i] = B[i];
}

void Merge2(int A[], int B[], int m, int n){ // this function merges two sorted arrays
    int i, j, k;
    i=j=k=0;
    int C[m+n];
    
    while(i<m && j<n){
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    
    // we copy the remaining elements from A if list B ends
    for(; i<m; i++)
        C[k++] = A[i];

    // copy remaining elements from B if list A ends
    for(; j<n; j++)
        C[k++] = B[j];
}

void iMergeSort(int A[], int n){ // Iterative Function
    int p, low, high, mid, i;

    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<=n; i=i+p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            Merge1(A, low, mid, high);
        }
    }

    if(p/2 < n)
        Merge1(A,0, p/2-1, n);
}

void rMergeSort(int A[], int low, int high){ // Recursive Function
    int mid;
    if(low < high){
        mid = (low+high)/2;
        rMergeSort(A, low, mid);
        rMergeSort(A, mid+1, high);
        Merge1(A, low, mid, high);
    }
}





int main(void){
    int A[]={3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n=10;
    // int A[]={3, 7, 9, 10, 6, 5, 12, 4, 11, 2, __INT_MAX__}, n=11; // this for QuickSort

    // BubbleSort(A, n);
    // InsertionSort(A, n);
    // SelectionSort(A, n);
    // QuickSort(A, 0, 10);
    // iMergeSort(A, n);
    rMergeSort(A, 0, n-1);

    for(int i=0; i<10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
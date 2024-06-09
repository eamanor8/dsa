#include <iostream>

/*
    A way to improve linear search operation is to perform transposition.
    Thus, whenver we find the key element being searched, we swap the key element
    with the immediate element before it.
    This way, if we happen to search for the same element again, then it will take
    less number of comparisons to find it. And the more frequently we search for a 
    particular element, the less time it takes on subsequent search operations 
    than the previous attempts.
*/

struct Array{
    int A[10];
    int size;
    int length;
};

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int linearSearch(struct Array *arr, int key){
    
    for(int i=0; i<10; i++){
        if(arr->A[i] == key){
            swap(&arr->A[i], &arr->A[i-1]);
            std::cout << "Search item " << key << " found at index " << i << std::endl;
            return i;
        }
    }
    std::cout << "Item not found!" << std::endl;    
    return -1; // return -1 if item not found.
}

/*
    an important precondition to binary search is that the list must be sorted.
*/

int binarySearch(struct Array arr, int key){
    int low = 0;
    int high = arr.length-1;
    int mid = (low+high)/2;

    while(low <= high){
        mid = (low+high)/2;

        if(key < arr.A[mid])
            high = mid-1; 
        else if(key > arr.A[mid])
            low = mid+1;
        else {
            std::cout << "Item " << key << " found at index " << mid << std::endl;
            return mid;
        }
    }
    std::cout << "Item not found!" << std::endl;    
    return -1; // return -1 if item not found.
}

int main(){

    struct Array arr = {{1, 4, 7, 23, 45, 98, 12}, 10, 7};
    struct Array sortedArr = {{2, 4, 12, 17, 22, 36, 54, 72, 91, 99}, 10, 10};

    linearSearch(&arr, 98);
    linearSearch(&arr, 98); // this second search should return a lower index for where the item is found.

    binarySearch(sortedArr, 2);
    
    return 0;
}
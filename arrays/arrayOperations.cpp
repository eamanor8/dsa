#include <iostream>
#include <utility> // for std::pair

using namespace std;

// void dynamicArr(){
//     Array arr;
//     cout << "Enter desired array size: ";
//     cin >> arr.size;
//     arr.A = new int[arr.size];
//     arr.length = 0;
//     int num;
//     cout << "Enter number of elements to be provided: ";
//     cin >> num;
//     cout << "Enter your " << num << " array elements: ";
//     for (int i = 0; i < num; i++) {
//         cin >> arr.A[i];
//         arr.length++;
//     }
// }

struct Array {
    int A[10];
    int size;
    int length;
};

void Swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Insert(struct Array *arr, int index, int value){
    // to insert an element at a particular index in our array, we need to shift some elements
    // to create space at that index

    if(index >= 0 && index <= arr->length){
        for(int i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        
        arr->A[index] = value;
        arr->length++;
    }
    
}

void Display(struct Array arr) {
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
    cout << endl;
}

void Append(struct Array *arr, int value){
    // add an element to the end of the array
    if(arr->length < arr->size)
        arr->A[arr->length++] = value;
}

void Delete(struct Array *arr, int index){
    if(index >= 0 && index <= arr->length){
        for(int i=index; i<arr->length; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
}

int MaxElement(struct Array arr){
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int SumofAll(struct Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++)
        sum += arr.A[i];
    return sum;
}

std::pair<int*, int> ReverseArray(struct Array *arr){
    // several methods can be used 1. copy all elements into a different array in reverse order and copying back into the original array
    // or 2. swaping elements from opposite ends
    int temp=0;
    for(int i=0, j=arr->length-1; i<j; i++, j--){
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    return std::make_pair(arr->A, arr->length); // Return pointer and size as a pair
}

void Display2(const std::pair<int*, int> arrWithSize){
    std::cout << "\nReversed Array: ";
    for(int i=0; i<arrWithSize.second; i++)
        std::cout << arrWithSize.first[i] << " ";
    std::cout << std::endl; // Adding a newline for better formatting after display
}

void LeftShift(struct Array *arr){ // we can edit this slightly to work for RightShift
    for(int i=0; i<arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length] = 0;
}

void RightRotate(struct Array *arr){ // we can edit this slightly to work for LeftRotate
    int temp = arr->A[arr->length];
    for(int i=arr->length; i>0; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}

// INSERTING INTO A SORTED LIST
// Unlike the regular insert operation where we place the element at a specified index,
// here we insert at a position which ensures that the list is still sorted after the operation
void SortedInsert(struct Array *arr, int item){
    int i = arr->length-1;

    if(arr->length == arr->size)
        return;
    while(i>=0 && arr->A[i] > item){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = item;
    arr->length++;
}

std::string IsSorted(struct Array arr){
    for(int i=0; i<arr.length-1; i++)
        if(arr.A[i] > arr.A[i+1])
            return "\nList not sorted! Unsorted element at index " + std::to_string(i);
    
    return "\nList is sorted in ASCENDING order!";
}

// this function is to regroup all negatives on the left side and positives on the right hand
void ReArrange(struct Array *arr){
    int i=0; // i will track positive numbers while j tracks the negatives
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i] < 0 )
            i++;
        while(arr->A[j] >= 0)
            j--;
        if(i<j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}



int main() {
    struct Array arr = {{2, 1, 6, 4, 10}, 10, 5};
    struct Array sortedArr = {{2, 4, 12, 17, 22, 36, 54}, 10, 7};
    struct Array mixedArr = {{-6, 7, 8, -19, 14, -30, -4, 23, 42}, 10, 9};
    
    std::cout << "Initial array: ";
    Display(arr);
    // let's append 157 to the array
    // append(&arr, 157);
    
    //let's insert 99 at index 4
    Insert(&arr, 4, 99);
    std::cout << "After Insertion: ";
    Display(arr);

    LeftShift(&arr);
    std::cout << "After Left Shift: ";
    Display(arr);

    RightRotate(&arr);
    std::cout << "After Right Rotate: ";
    Display(arr);

    // let's delete element at index 3
    Delete(&arr, 3);
    std::cout << "After Deletion: ";
    Display(arr);

    // let's rearrange +ves and -ves on one side
    std::cout << "\nMixed Array: ";
    Display(mixedArr);
    ReArrange(&mixedArr);
    std::cout << "After re-arranging: ";
    Display(mixedArr);

    auto ReversedArray = ReverseArray(&arr);
    Display2(ReversedArray);

    std::cout << "Maximum element in array: " << MaxElement(arr) << std::endl;
    std::cout << "Sum of all array elements: " << SumofAll(arr) << std::endl;

    std::cout << IsSorted(sortedArr) << std::endl;

    std::cout << "\nBefore Insertion: ";
    Display(sortedArr);
    SortedInsert(&sortedArr, 13);
    std::cout << "After Insertion: ";
    Display(sortedArr);

    return 0;
}

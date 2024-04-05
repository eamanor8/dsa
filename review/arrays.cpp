#include <iostream>

using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Size of arr[] is " << sizeof(arr) << " bytes\n" << endl;
    //Note: sizeof(arr) = 5 * sizeof(int) = 5 * 4 = 20 bytes

    // Accessing elements of an array using a normal for-loop
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //using for-each loop: each array element is multiplied by 2
    for(int x:arr) {
        cout << x*2 << " ";
    }
    cout << endl;
    
    return 0;
}
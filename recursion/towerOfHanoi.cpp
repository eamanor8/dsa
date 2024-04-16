#include <iostream>

using namespace std;

/*
    The tower of hanoi problem has to do with moving n number of disks from one tower(A) to another tower(C)
    with the of an intermediate tower(B) under the following constraints:
        1. only one disk can be moved at a time
        2. a larger disk cannot be placed on a smaller disk in any of the arrangements.

    So we use recursion to develop a function that gives a the steps to follow in moving the disks.
*/

void ToH(int n, int A, int B, int C){
    if(n>0){
        ToH(n-1, A, C, B);
        cout << "( " << A << ", " << C << ")" << endl;
        ToH(n-1, B, A, C);
    }
}

int main() {
    int n=3;

    ToH(n, 1, 2, 3);
    
    return 0;
}
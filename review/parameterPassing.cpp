#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Passing by value: the actual value is passed to the function. The function creates a copy of the value and works with the copy.
    Any changes made to the copy of the value will not affect the original value. The parameters passed by value are variables.

    Passing by address: the address of the actual value is passed to the function. The function works with the actual value.
    Any changes made to the actual value will affect the original value. The parameters passed by address are pointers.

    Passing by reference: the address of the actual value is passed to the function. The function works with the actual value.
    Any changes made to the actual value will affect the original value. This is similar to passing by address, but the syntax is different.
    It works only in C++. In call by reference, the function isn't treated as a separate entity. It is treated as the same entity as the caller. 
    Remember that the reference is not a new variable. It is just an alias for the variable that is passed to the function.


*/

// passing by value
void swapVal(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// passing by address
void swapAddr(int *m, int *n) {
    int temp = *m;
    *m = *n;
    *n = temp;
}

// passing by reference
void swapRef(int &u, int &v) {
    int temp = u;
    u = v;
    v = temp;
}

int main() {
    cout << "PASSING BY VALUE" << endl;
    int x = 5, y = 3;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapVal(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    cout << "NB: The values of x and y did not change because we passed by value.\n" << endl;

    cout << "PASSING BY ADDRESS" << endl;
    int m = 10, n = 17;
    cout << "Before swap: m = " << m << ", n = " << n << endl;
    swapAddr(&m, &n);
    cout << "After swap: m = " << m << ", n = " << n << endl;
    cout << "NB: The values of m and n changed because we passed by address.\n" << endl;

    cout << "PASSING BY REFERENCE" << endl;
    int p = 20, q = 30;
    cout << "Before swap: p = " << p << ", q = " << q << endl;
    swapRef(p, q);
    cout << "After swap: p = " << p << ", q = " << q << endl;
    cout << "NB: The values of p and q changed because we passed by reference.\n" << endl;
 
    return 0;
}
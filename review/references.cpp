#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Reference is a concept in C++ that is an alias to a variable.
    References are used to access the same memory location as the original variable.

    This reference concept is useful in parameter passing to functions.
    When a reference is passed to a function, the function can modify the original variable.

    Note: References cannot be NULL, they must be initialized when declared.

*/

int main() {

    int x = 10; // x is a variable
    int *p = &x; // p is a pointer to x
    int &r = x; // r is a reference to x

    cout << "Value of x: " << x << endl;
    cout << "Value of r: " << r << endl;
    r++; // increment the value of x using the reference r
    cout << "Value of x after incrementing r: " << x << endl;
    x++; // increment the value of x directly
    cout << "Value of x after incrementing x: " << x << endl;

    int b = 20;
    r = b;  // assign the value of b to x using the reference r; don't get tricked into thinking that r is now a reference to b, 
            // remember that r is a reference to x, and references cannot be re-assigned to another variable;

    cout << "\n Value of x after assigning b to x using r: " << x << endl;

    return 0;
}
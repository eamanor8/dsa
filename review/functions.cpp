#include <iostream>
#include <stdio.h>

using namespace std;

/*
    A function is a group of related instructions that perform a specific task.

    Monolithic programming: writing all the code in the main function. This is not a good practice. 
    
    It is better to break the code into smaller functions. This makes the code more readable, easier to maintain, and reusable. 
    This is called modular or procedural programming.

*/

// simple add function 
int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 3;
    int sum = add(x, y);
    cout << "Sum: " << sum << endl;

    
    return 0;
}
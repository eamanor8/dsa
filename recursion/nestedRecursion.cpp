#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Nested recursion is when a recursive function call takes another call to the recursive function as a parameter
    instead of a value as the parameter.
*/

int fun(int n){
    if(n > 100)
        return n-10;
    else
        return fun(fun(n+11));
}

int main() {

    int result = fun(95);

    cout << "Result: " << result << endl;
    
    return 0;
}


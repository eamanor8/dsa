#include <iostream>
#include <vector>

using namespace std;

/*
    The Fibonacci Series always starts with two terms by default: 0, 1
    All subsequent terms are obtained by adding the previous two terms: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

             { 0,                    n=0
    fib(n) = { 1,                    n=1
             { fib(n-2)+fib(n-1),    n>1
*/

// Recurssion runs in O(2^n) exponential time complexity
int fib(int n){
    if(n<=1)
        return n;
    else
        return fib(n-2)+fib(n-1);
}

/*
    When we trace the recursion tree for the above fibonacci function, it performs excessive recurssion which increases the execution
    time of the function. A better way to go about this is to perform memoization (store the intermediate results when the function is called
     multiple times with the same paraters).
*/

// Memoizatoin Technique runs in O(n) linear time
        // let's declare a global array variable to store our intermediate values
        // a value of -1 in the array tells us that particular function call has not been made yet 
        // so we need to do it.

vector<int> F(10, -1); // Vector of size 10, initialized with -1

int fibMem(int n){ 
    if(n <= 1){
        F[n] = n;
        return n;
    }
    else {
        if(F[n-2] == -1)
            F[n-2] = fibMem(n-2);
        if(F[n-1] == -1)
            F[n-1] = fibMem(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
}


int main(){
    int n=8;

    cout << n << "th term of the Fibonacci series: " << fib(n) << endl; 
    cout << n << "th term of the Fibonacci series: " << fibMem(n) << endl; 
    return 0;
}
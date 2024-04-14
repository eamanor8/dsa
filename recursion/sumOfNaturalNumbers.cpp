#include <iostream>

using namespace std;

/*
    sumToN(7) = 1 + 2 + 3 + 4 +  5 + 6 + 7
    sumToN(n) = 1 + 2 + 3 + 4 + ... + (n-1) + n

    Aside the recursive approach, we can use a for-loop

    But there is a straight forward formula to calculate this which is more efficient than the recursive approach
        sumToN(n) = n*(n+1)/2
*/

// RECURSIVE APPROACH --> Runs in O(n) & takes more space because it creates n activation records in stack
int recursiveSum(int n){
    if(n==0)
        return 0;
    else
        return recursiveSum(n-1)+n;
}

// LOOP APPROACH --> Runs in O(n)
int iterativeSum(int n){
    int s=0;
    
    for(int i=1; i<=n; i++)
        s += i;
    
    return s;
}

// FORMULA --> Runs in O(1)
int sumFormula(int n){
    return n*(n+1)/2;
}

int main(){
    int a=10;

    cout << "Recursive sum: " << recursiveSum(a) << endl;
    cout << "Iterative sum: " << iterativeSum(a) << endl;
    cout << "Formula sum: " << sumFormula(a) << endl;

    return 0;
}
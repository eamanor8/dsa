#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    else
        return factorial(n-1)*n;;
}

/*
    nCr = n!/r!(n-r)!

    NB: the r values can range from 0 to n

    Because the combination process involves factorials in three different places, we can make a factorial function call
    and store the values in three separate variables.
*/

int combination(int n, int r){
    int num = factorial(n);                       // num represents numerator
    int den = factorial(r)*factorial(n-r);        // den = expression in the denominator

    return num/den;
}

// Recurssion approach
    /*
        This is borne out the idea of Pascal's Triangle 

                                                        1
                                                      /    \
                                                     1      1
                                                   /   \  /   \
                                                  1     2       1
                                                /   \  /  \   /   \
                                              1       3     3       1
                                                    
    */
int rCombination(int n, int r){
    if(r==0 || n==r)
        return 1;
    else
        return rCombination(n-1, r-1) + rCombination(n-1, r);
}

int main(){
    int n=6, r=3;

    // cout << n <<"C" << r << ": " << combination(n, r) << endl;
    cout << n <<"C" << r << ": " << rCombination(n, r) << endl;

    return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Here we try to find the exponents of numbers.
    eg: m^n
*/

int powerA(int m, int n){
    if(n == 0)
        return 1;
    else  
        return powerA(m, n-1)*m;
}

// This function uses less number of multiplications than the previous one
int powerB(int m, int n){
    if(n == 0)
        return 1;
    if(n%2 == 0)
        return powerB(m*m, n/2);
    else  
        return m*powerB(m*m, (n-1)/2);
}

int main() {
    int a=2;
    int b=8;

    cout << a << " power " << b << ": " << powerA(a, b) << endl;
    cout << a << " power " << b << ": " << powerB(a, b) << endl;
    
    return 0;
}
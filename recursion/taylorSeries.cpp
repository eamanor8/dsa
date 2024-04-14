#include <iostream>

using namespace std;

/*
    Taylor Series is the expression e^x whic is computed as 
    1 + x/1 + x^2/2! + x^3/3! + ... + x^n/n!
*/

double taylorSeries(int x, int n){  //x=exponent for the series, & n=number of terms. The higher the n value, the higher the precision of the result we get
    static double p=1, f=1;    //p=power, f=factorial
    double r;              //r=result
    if(n == 0)
        return 1;
    else{
        r = taylorSeries(x, n-1);
        p=p*x;
        f=f*n;

        return r + p/f;
    }
}

// The horner's rule approach reduces the number of multiplication operations from O(n^2) to O(n)
// This approach works by factoring common terms from the expression

double hornersRule(int x, int n){
    static double r;
    if(n==0)
        return r;
    
    r = 1 + x*r/n;
    return hornersRule(x, n-1);
}
int main(){
    int x=2, n=15;

    cout << "e^" << x << ": " << taylorSeries(x, n) << endl;
    cout << "e^" << x << ": " << hornersRule(x, n) << endl;
    return 0;
}
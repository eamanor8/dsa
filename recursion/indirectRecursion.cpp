#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Indirect recursion is when a function does not call itself directly but rather calls another function(s) which ultimately 
    leads back to calling the starting function. Let's see and example of such.
*/
void funA(int n);
void funB(int n);

void funA(int n){
    if(n>0){
        cout << n << " " ;
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){
        cout << n << " ";
        funA(n/2);
    }
}

int main(){

    funA(20);

    return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

// function without static or global variable
int func1(int n){
    if(n>0){
        return func1(n-1) + n;
    }
    return 0;
}

/*
    function with static variable...
    Because x is declared as a static variable, a new instance is not created every time the function gets called
    instead, the previous value is only updated with the increment operation. And since x is actually used 
    after the function call, only the last value from the last function call is used across all the other calls.
*/
int func2(int n){
    static int x=0;

    if(n>0){
        x++;
        return func2(n-1) + x;
    }
    return 0;
}

int main(){

    int a=5;
    int result = func2(a);
    cout << result << endl;

    return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Tree recursion is when the recursive function call is done more than once within the function
    Time complexity is O(2^n)
*/

void fun(int n){
    if(n>0){
        printf("%d ", n);
        fun(n-1);
        fun(n-1);
    }
}

int main(){

    int a=3;
    fun(a);

    return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Head recursion is when the recursive function call happens before any other statement in 
    in the function is executed.
    Unlike tail recursions, head recursive functions can not be easily converted to loops
*/

void fun(int n){
    if(n>0){
        fun(n-1);
        printf("%d ", n);
    }
}

int main(){

    int a=3;
    fun(a);

    return 0;
}
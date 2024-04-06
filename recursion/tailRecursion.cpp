#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Tail recursion is when the recursive function is the last statement in the function.
    All tail recursions can be easily converted into loops. And it's better to use the loop version 
    of tail recurions because they are more space efficient.... 
    This is because the tail recursion creates n activation records in stack if the function is called n-times
    whereas the loop just creates an activation record for the variable just once.
*/

void fun(int n){
    if(n>0){
        cout << n << " ";
        fun(n-1);
    }
}

// let's convert the recursive function above into it's corresponding loop function which is more space efficient.
void funLoop(int n){
    while(n>0){
        cout << n << " ";
        n--;
    }
}

int main(){
    int a=3;
    fun(a);
    printf("\n");
    
// this produces the same output as the recursive function above...
    funLoop(a);

    return 0;
}
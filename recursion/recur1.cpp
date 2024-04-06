#include <iostream>
#include <stdio.h>

using namespace std;

/*
    A recursive function must always have a base condition which allows it to terminate at some point.
    Otherwise, the function is bound to run infinitely...

    NB: Any statements or operations that come before a recursive function call are executed at the calling phase (ascending)
        while statements or operations that come after a recursive function call are executed during the return phase (descending)
*/

void fun1(int x){
    if(x<4){
        cout << "CountUp: " << x << endl;
        fun1(x+1);
    }
}

void fun2(int x){
    if(x<4){
        fun2(x+1);
        cout << "CountDown: " << x << endl;
    }
}

int main(){
    int n=1;
    fun1(n);
    // cout << "\t..." << endl;
    // fun2(n);

    return 0;
}
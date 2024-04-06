#include <iostream>

using namespace std;

int factorial(int n){
    if(n>0){
        return n*factorial(n-1);
    }
}

int main(){
    int x=5;

    cout << x << "! = " << factorial(x);

    return 0;
}

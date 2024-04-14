#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    else
        return factorial(n-1)*n;;
}

int main(){
    int x=5;

    cout << x << "! = " << factorial(x);

    return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

/*
    Just like variables, we can pass structs to functions. We can pass structs by value, by address, or by reference.

    NB: Though we can not pass arrays by value directly, we can pass structs that contain arrays by value.
*/

struct rectangle {
    int length;
    int breadth;
};

// passing the struct by value
int area(struct rectangle R){
    return R.length * R.breadth;
}

// passing the struct by reference
void changeLength(struct rectangle &R, int l){
    R.length = l;
}

// passing the struct by address
void changeBreadth(struct rectangle *R, int b){
    R->breadth = b;
}

int main(){

    struct rectangle r = {10, 5};

    cout << "Area of rectangle: " << area(r) << endl;

    changeLength(r, 12);
    changeBreadth(&r, 4);

    cout << "New area of rectangle: " << area(r) << endl;


    return 0;
}
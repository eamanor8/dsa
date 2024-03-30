#include <iostream>
#include <stdio.h>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

int main() {
    struct rectangle rec = {10, 5};

    // the direct way to access the struct members is by using the dot operator
    cout << "Length of rectangle: " << rec.length << endl;
    cout << "Area of rectangle: " << rec.length * rec.breadth << endl;

    // the pointer way to access the struct members is by using the arrow operator
    struct rectangle *p = &rec;
    cout << "Breath of rectangle: " << p->breadth << endl;

    struct rectangle *q;
    // to create an object of type struct rectangle in the heap memory and have q point to it
    q = (struct rectangle *)malloc(sizeof(struct rectangle));
        // alternatively, we can use the new operator in C++
        // q = new struct rectangle;
    q->length = 7;
    q->breadth = 3;
    cout << "Area of rectangle in heap memory: " << q->length * q->breadth << endl;
    
    free(q);    // free the memory allocated in the heap memory
                // alternatively, we can use the delete operator in C++
                // delete q;
    

    return 0;
}

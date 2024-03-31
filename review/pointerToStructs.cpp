#include <iostream>
#include <stdio.h>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

// let's create a struct for volume of a cone
struct cone {
    float radius;
    float height;
};

int main() {
    struct cone c = {3.0, 4.0};

    // the direct way to access the struct members is by using the dot operator
    cout << "Radius of cone: " << c.radius << endl;
    cout << "Volume of cone: " << 3.14 * c.radius * c.radius * c.height / 3 << endl;

    // the pointer way to access the struct members is by using the arrow operator
    struct cone *p = &c;
    cout << "Height of cone: " << p->height << endl;

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

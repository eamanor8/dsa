#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
class Arithmetic {
    private:
        T val1;
        T val2;

    public:
        Arithmetic(T a, T b);
        T Add();
        T Subtract();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->val1 = a;
    this->val2 = b;
}

template<class T>
T Arithmetic<T>::Add(){
    T sum;
    sum = val1+val2;
    return sum;
}

template<class T>
T Arithmetic<T>::Subtract(){
    return val1-val2;
}

int main(){
    Arithmetic<int> OpInt(15, 7);
    cout << "Adding Integers: " << OpInt.Add() << endl;

    Arithmetic<float> OpFloat(13.7, 4.2);
    cout << "Subtracting Floats: " << OpFloat.Subtract() << endl;

    return 0;
}
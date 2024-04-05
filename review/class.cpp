#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle {
    private: 
        int length;
        int breadth;
    
    public:
        // default constructor
        Rectangle(){
            this->length=0; this->breadth=0;
        }

        // parameterized constructor
        Rectangle(int l, int b){
            this->length = l;
            this->breadth = b;
        }

        void setLength(int l){
            length=l;
        }

        void setBreadth(int b){
            breadth = b;
        }

        int getLength(){
            return length;
        }

        int getBreadth(){
            return breadth;
        }

        // area
        int Area (){
            return length*breadth;
        }

        // perimeter
        int Perimeter(){
            return 2*(length+breadth);
        }

        // printArea
        void printArea(){
            cout << "Area of Rectangle: " << Area() << endl;
        }

        // printPerimeter
        void printPeri(){
            cout << "Perimeter of Rectangle: " << Perimeter() << endl;
        }
        
};

int main(){

    Rectangle R(10, 5);

    R.printArea();
    R.printPeri();

    return 0;
}
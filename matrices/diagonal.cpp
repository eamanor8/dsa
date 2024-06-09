#include <iostream>

class Diagonal{
    private:
        int *A;             // Because the diagonal of any matrix will have n elements,
                            // we need to create an Array of size n to store those n elements 
                            // and avoid storing zeros to save space.
        int n;
    public:
        Diagonal(){             
            n=2;
            A = new int[2];
        }

        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }

        ~Diagonal(){     // because we're creating an array in heap, we need a destructor to deallocate the memory
                         // when it's no longer needed.
            delete []A;
        }

        void Set(int row, int col, int value);
        int Get(int row, int col);
        void Display();
};

    /*
        note that we ended the class with a semi-colon(;)

        also, the implementations of the class functions were done outside the class and we use the scope 
        resoluton operator ::
    */

void Diagonal::Set(int row, int col, int value){
    if(row == col)
        A[row-1] = value;
}

int Diagonal::Get(int row, int col){
    if(row == col)
        return A[row-1];
    else
        return 0;
}

void Diagonal::Display(){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j)
                std::cout << A[i] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }
}



int main(){
    Diagonal d(4);

    d.Set(1, 1, 5);
    d.Set(2, 2, 8);
    d.Set(3, 3, 3);
    d.Set(4, 4, 7);

    d.Display();

    return 0;
}
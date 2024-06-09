#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    int i, j;
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 5, 7, 9}};

    for(i=0; i<3; i++){
        for(j=0; j<4; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
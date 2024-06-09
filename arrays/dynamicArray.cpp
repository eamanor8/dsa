#include <stdio.h>
#include <iostream>

using namespace std;

/*
    The idea of dynamic arrays is that, only arrrays created in heap memory can have their sizes changed
    later. And even that, we can do it directly.

    So we need to create a new array in heap memory of the desired new size and then copy the content
    of the old memory into the new.
*/

int main(){
    
    int *p, *q;
    int i;
    p= (int*)malloc(5*sizeof(int));
    
    // initializing the array 
    for(i=0; i<5; i++)
        p[i] = i+2;
    
    // printing the elements in the array
    for (i=0; i<5; i++) {
        cout << p[i] << " ";
    }

    q = (int*)malloc(10*sizeof(int));

    // we need to copy the contents of the array p points to into the new array q points to
    memcpy(q, p, 5*sizeof(int));    // we could have done this using a for-loop

    free(p);    // deallocate the memory previously assigned to p
    p=q;    // change the location p points to
    q = NULL;   // since p and q both points to the same location we remove q

    // now that we've successfully increased the size of the array p points to, let's assign few elements
    p[5]=12, p[6]=34, p[7]=99;

    cout << "\n";
    // printing the elements in the array 
    for (i=0; i<8; i++) {
        cout << p[i] << " ";
    }
    
    return 0;
}

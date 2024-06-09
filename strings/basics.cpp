#include <iostream>
#include <stdio.h>

/*
    ASCII codes are the numeric representation of characters
    A - Z: 65 - 90;  a - z: 97 - 122;    0 - 9: 48 - 57;

    When we create an array of characters, because the number of characters stored may be 
    less than the array size, a null character ('\0') is used to denote the end of the string
    stored in the array.
*/

void Display(char arr[], int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void DisplayString(char arr[]){
    for(int i = 0; arr[i] != '\0'; i++)
        std::cout << arr[i];
    std::cout << std::endl;
}

int main(){

    char grade = 'A';
    char grades[] = {65, 66, 67, 68, 69}; // Since we specified the datatype as char, the initialized values 
                                          // are considered the ASCII representation of the values. 
                                          // So printing the grades[] array will display A B C D E
    Display(grades, 5);

    char name[10] = {'E', 'd', 'm', 'u', 'n', 'd'}; // Even though the name[] array has a size of 10, 
                                                    // the length of my name is only 6. So to know where
                                                    // the string ends, a null character/ string terminator 
                                                    // is used to denote the end of the string.
                                                    // So name[] here is just an array of characters, therefore
                                                    // to make it a string, we need to explicitly add the 
                                                    // null character ('\0')
    char firstName[10] = {'E', 'd', 'm', 'u', 'n', 'd', '\0'};

    // alternative ways to declare and initialize strings are:
    char lastName[] = {'A', 'm', 'a', 'n', 'o', 'r', '\0'};
    char status[] = "single"; // Corrected syntax for string initialization

    // Display the strings
    DisplayString(firstName);
    DisplayString(lastName);
    DisplayString(status);

    return 0;
}

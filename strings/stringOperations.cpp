#include <iostream>
#include <stdio.h>

int stringLength(char arr[]){
    int i = 0;
    while (arr[i] != '\0') {
        i++;
    }
    return i;
}

void toLowerCase(char arr[]){               // The trick in converting from upper to lowercase and vice versa is
                                            // knowing that for all  alphabets the numeric difference between the 
                                            // upper and lowercase is 32. So we need to add 32 to convert to 
                                            // lowercase and subtract 32 to convert to upper case.
    for(int i=0; arr[i] != '\0'; i++){
        arr[i] +=32;
    }
    printf("\n%s\n", arr);
}

void toggle(char arr[]){
    for(int i=0; arr[i] != '\0'; i++){
        if(arr[i] >= 65 && arr[i] <= 90) // if uppercase, add 32 to make it lower
            arr[i] += 32;
        else if(arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] -= 32;
    }

    printf("%s\n", arr);
}

void reverseString(char arr[]){
    int length = 0;
    while(arr[length] != '\0'){
        length++;
    }
    
    char newArr[length + 1]; // Allocate enough space for the reversed string including null terminator
    int i = length - 1;

    for(int j = 0; j < length; j++){
        newArr[j] = arr[i];
        i--;
    }
    newArr[length] = '\0'; // Place the null terminator at the end

    printf("%s\n", newArr);
}

int main(){

    char note[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', '\0'};
    char mixedNote[] = {'W', 'e', 'l', 'C', 'O', 'm', 'E', '\0'};

    printf("%s\n", note);
    printf("The length of note is %d ", stringLength(note));

    toLowerCase(note);
    printf("%s\n", mixedNote);
    toggle(mixedNote);
    reverseString(note);




    return 0;
}
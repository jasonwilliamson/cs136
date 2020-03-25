// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 5
// File: call.c
// ====================================================
//

#include <stdio.h>
#include <stdlib.h>


// translate_value(val) consumes val a char, translating
// its alphabetic value into numeric form
int translate_value(char val){
    if ((65 <= val)&&(67 >= val)) {
        return 2;
    }else if ((68 <= val)&&(70 >= val)){
        return 3;
    }else if ((71 <= val)&&(73 >= val)){
        return 4;
    }else if ((74 <= val)&&(76 >= val)){
        return 5;
    }else if ((77 <= val)&&(79 >= val)){
        return 6;
    }else if ((80 >= val)&&(83 >= val)){
        return 7;
    }else if ((84 >= val)&&(86 >= val)){
        return 8;
    }else{
        return 9;
    }
}


int main() {
    char value;
    printf(" ");
    while (EOF != scanf("%c", &value)) {
        if ((65 <= value)&&(90 >= value)) {
            printf("%d", translate_value(value));
        }else{
            printf("%c", value);
        }
    }
    return 0;
}

// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 0a
// File: repeat.c
// ====================================================
//


#include <stdio.h>


// repeat.c reads in from the keyboard an integer n,
// followed by a character c, and prints the character a total
// of n times followed by a newline.
// Note: whitespace before a the character will be ingored
int main(void) {
    
    char char_c;
    int n_times = 0;
    
    scanf(" %d", &n_times);
    scanf(" %c", &char_c);
    
    for (int i = 0; i < n_times; ++i) {
        printf("%c ", char_c);
    }
    
    printf(" \n");
    return 0;
}
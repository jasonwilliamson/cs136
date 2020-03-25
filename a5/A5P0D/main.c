// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 0d
// File: train.c
// ====================================================
//

#include <stdio.h>

/*
 A simple program that draws an ASCII train
 */

int main(void)
{
    int first = 0;
    int second = 0;
    int third = 0;
    
    scanf(" %d", &first);
    scanf(" %d", &second);
    scanf(" %d", &third);
    
    printf("\n");
    printf("     oO                            \n");
    printf("    o   +---+                      \n");
    printf("   H____|___|  _______   _______   \n");
    printf("  |   %5d | | %5d | | %5d |  \n", first, second, third);
    printf("  |_________|=|_______|=|_______|  \n");
    printf("   -O-----O-   -O---O-   -O---O-   \n\n");
}

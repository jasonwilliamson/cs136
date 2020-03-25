// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 0d
// File: readstr.c
// ====================================================
//

#include "readstr.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *readstr(void) {
    char value;
    int len = 0;
    int max = 16;
    char *str = malloc(sizeof(char) * max);
    
    while (1) {

        if ((scanf("%c", &value) != EOF)  && ('\n' != value)) {
            if (len == max) {
                if (len == INT_MAX) {
                    //max string length reached here
                    break;
                }
                else if (INT_MAX <= (max *= 2)) {
                    max = INT_MAX;
                }else{
                   max *= 2;
                }
                str = realloc(str, sizeof(char) * max);
            }
            str[len] = value;
            ++len;
        }else{
            break;
        }
    }
    str[len] = '\0';
    
    str = realloc(str, sizeof(char) * (len + 1));
    
    return str;
}


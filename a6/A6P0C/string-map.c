// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 0c
// File: string-map.h
// ====================================================
//

#include "string-map.h"
#include <stdlib.h>
#include <assert.h>


// my_str_len(str) returns the length of str
static int my_str_len(char *str){
    assert(str != NULL);
    int len = 0;
    while (*str) {
        ++len;
        ++str;
    }
    return len;
}

// string_map(str, proc) maps proc to each character in str.
// requires: str and proc are not NULL
// effects: modifies str by applying proc to each char in str.
void string_map(char *str, char (*proc)(char)) {
    assert(str != NULL);
    assert(proc != NULL);
    
    char new_str[my_str_len(str)];
    int len = 0;
    
    while (str[len]) {
        new_str[len] = proc( str[len]);
        str[len] = new_str[len];
        ++len;
    }
}

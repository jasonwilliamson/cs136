// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 0a
// File: strdup.c
// ====================================================
//

#include "strdup.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// my_strdup(s) makes a duplicate of s and returns a pointer to
// the duplicate char array
// returns NULL if there is not enough memory
// effects: allocates char array on the heap (caller must free)
// time: O(n)
// requires: s != NULL
char *my_strdup(const char *s) {
    assert(s);
    int str_size = 0;
    while (s[str_size]) {
        ++str_size;
    }
    
    int bytes = (sizeof(char) * (str_size + 1));
    char *new = malloc(bytes);
    
    for (int i = 0; i < str_size; ++i) {
        new[i] = s[i];
    }
    new[str_size] = '\0';
    return new;
}

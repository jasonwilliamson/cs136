// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 1
// File: strappend.c
// ====================================================
//

#include "strappend.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// see strappend.h for details
char *strappend(const char *s1, const char *s2) {
    assert(s1);
    assert(s2);
    
    int len1 = 0;
    int len2 = 0;
    const char *n1 = s1;
    const char *n2 = s2;
    
    while (*n1) {
        ++len1;
        ++n1;
    }
    while (*n2) {
        ++len2;
        ++n2;
    }
    
    int total_len = len1 + len2;
    int bytes = sizeof(char) * (total_len + 1);
    char *new_s = malloc(bytes);
    
    for (int i = 0; i < len1; ++i) {
        new_s[i] = s1[i];
    }
    
    int k = 0;
    for (int j = len1; j < total_len; ++j) {
        new_s[j] = s2[k];
        ++k;
    }
    
    new_s[total_len] = '\0';
    return new_s;
}

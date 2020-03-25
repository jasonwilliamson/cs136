// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 0b
// File: case_catcher.c
// ====================================================
//

#include "case-catcher.h"

#include <stdbool.h>
#include <assert.h>


// is_proper_case(str) determines if uppercase letters only occur at the
//   beginning of str or immediately after a period. Moreover, only
//   uppercase letters or a NULL terminator can follow a period.
// requires: str is not NULL and str is NULL terminated
bool is_proper_case(char str[]) {
    assert(str != NULL);
    
    int len = 0;
    while (str[len]) {
        if ((str[len] >= 'A') && (str[len] <= 'Z')) {
            if (len > 0) {
                if ('.' != str[(len - 1)]) {
                    return false;
                }
            }
        }else if ((str[len] >= 'a') && (str[len] <= 'z')){
            if (len > 0) {
                if ('.' == str[(len - 1)]) {
                    return false;
                }
            }
        }
        ++len;
    }
    return true;
}


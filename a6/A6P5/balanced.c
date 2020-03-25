// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 5
// File: balanced.c
// ====================================================
//

#include "balanced.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


// is_balanced(str) determines if str is balanced. str is balanced if
//   every parenthesis is closed and the most recent openeing parenthesis
//   is closed first. '(' is an openning parenthesis and ')' is a closing
//   parenthesis. Other chars in str are ignored.
// requires: str is not NULL
bool is_balanced(char str[]) {
    assert(str != NULL);
    int open_bracket_count = 0;
    int i = 0;
    while (str[i]) {
        if ('(' == str[i]) {
            ++open_bracket_count;
        }else if ((')' == str[i]) && (open_bracket_count > 0)){
            --open_bracket_count;
        }
        ++i;
    }
    if (0 == open_bracket_count) {
        return true;
    }else{
        return false;
    }
}

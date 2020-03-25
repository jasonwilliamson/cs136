// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 1
// File: name_char.c
// ====================================================

#include <stdio.h>
#include <stdbool.h>


// name_char(c) Determines if c is valid in a C identifier.
bool name_char(char c) {
    if ((c >= '0') && (c <= '9')) {
        return true;
    }else if ((c >= 'A') && (c <= 'Z')){
        return true;
    }else if ((c >= 'a') && (c <= 'z')){
        return true;
    }else if ('_' == c){
        return true;
    }else{
        return false;
    }
}
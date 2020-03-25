// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 0b
// File: fequals.c
// ====================================================

#include "fequals.h"
#include <stdio.h>
#include <stdbool.h>


// fequals(a,b) Returns true if a and b are within 0.00001
//    of each other.
bool fequals(float a, float b) {
    const float range = 0.00001;
    float difference = a - b;
    if (difference <= range && difference >= -range) {
        return true;
    }else{
        return false;
    }
}
// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 0b
// File: is_prime.c
// ====================================================
//

#include "is_prime.h"
#include <stdbool.h>
#include <assert.h>


// is_prime(n) Returns true if n is a prime number,
//   otherwise returns false.
// requires: n > 0
bool is_prime(int n) {
    assert(n > 0);
    int acc = 2;
    while (acc < n) {
        if (n % acc == 0) {
            return false;
        }
        ++acc;
    }
    return true;
}



// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 2
// File: count_primes.c
// ====================================================
//

#include "count_primes.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static bool is_prime(int n);

// count_primes(a,b) consumes a, and b both integers and
// produces the number of prime numbers in the range
// inclusively, [a,b].
// Note: if a > b then the range is empty but not invalid
int count_primes(int a, int b) {
    if (a > b) {
        return 0;
    }else{
        int count = 0;
        do {
            if (is_prime(a)) {
                ++count;
            }
            ++a;
        } while (a <= b);
        return count;
    }
}


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
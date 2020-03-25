// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 1
// File: palindrome.c
// ====================================================
//

#include "palindrome.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


/*static int count_digits(int n);
static int first_digit(int n);
static int last_digit(int n);
static int nth_power_of_ten(int n);
static int remove_first_last_digit(int n);*/


// is_palindrome(n) consumes n, an int, and produces true if n
// is a palindrome number, otherwise produces false.
// requires: n > 0
// examples: is_palindrome(131) == true
//           is_palindrome(123329) == false
bool is_palindrome(int n){
    assert(n > 0);
    if (first_digit(n) == last_digit(n)) {
        int count = count_digits(n);
        do {
            if (1 == count) {
                return true;
            }else if((2 == count) && (first_digit(n) == last_digit(n))){
                return true;
            }else{
                n = remove_first_last_digit(n);
                count = count_digits(n);
            }
            
        } while (count_digits(n) >= 1);
    }
    // this is not a palindrome
    return false;
}


// count_digits(n) consumes n, an int, and produces a number
// that represents the amount of digits n has
// examples: count_digits(54) == 2
//** make static ****
int count_digits(int n){
    if (n < 10) {
        return 1;
    }else{
        int count = 1;
        do {
            ++count;
        } while ((n *= .1) >= 10);
        return count;
    }
}


// first_digit(n) consumes n, an int, and produces the first
// digit of n.
// examples: first_digit(54321) == 5
int first_digit(int n){
    
    while (count_digits(n) > 1) {
        n *= .1;
    }
    return n;
}


// last_digit(n) consumes n, an int, and produces the last
// digit of n.
// examples: last_digit(54321) == 1
int last_digit(int n){
    return (n % 10);
}


// nth_power_of_ten(n) consumes n, an int, and produces the
// value of 10^n
int nth_power_of_ten(int n){
    if (0 == n) {
        return 1;
    }else{
        int base = 10;
        for (int i = 1; i < n; ++i) {
            base *= 10;
        }
        return base;
    }
}


// remove_first_last_digit(n) consumes n, and int, and produces
// a number value that is n with its first and last value removed
// requires: n must be atleast 3 digits long.
int remove_first_last_digit(int n){
    return (.1 * (n - (first_digit(n) *
                       (nth_power_of_ten (count_digits(n) -1)))));
}



// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 2
// File: is_palindrome.c
// ====================================================

// A module that evaluates wheather or not a number is a
// palindrome number.
// A palindrome number is a number whose digits are the same
// read backward, for example, 5885, 131, 11, 5, 65856.

#include "is_palindrome.h"
#include <stdio.h>

static int count_digits(const int n);
static int first_digit(const int n);
static int last_digit(const int n);
static int nth_power_of_ten(const int n);
static int remove_first_last_digit(const int n);


// is_palindrom(n) consumes n, an int, and produces true if n
// is a palindrome number, otherwise produces false.
// requires: n > 0
// examples: is_palindrome(131) == true
//           is_palindrome(123329) == false
int is_palindrome(const int n){
    if (first_digit(n) == last_digit(n)) {
        if (1 == count_digits(n)) {
            return 1;
        }else if((2 == count_digits(n)) &&
                 (first_digit(n) == last_digit(n))){
            return 1;
        }else{
            return is_palindrome(remove_first_last_digit(n));
        }
    }else{
        return 0;
    }
}


// count_digits(n) consumes n, an int, and produces a number
// that represents the amount of digits n has
// examples: count_digits(54) == 2
//** make static ****
int count_digits(const int n){
    if (n >= 10) {
        return 1 + (count_digits((n * .1)));
    }else{
        return 1;
    }
}


// first_digit(n) consumes n, an int, and produces the first
// digit of n.
// examples: first_digit(54321) == 5
int first_digit(const int n){
    if((count_digits(n)) > 1) {
        return first_digit((n * .1));
    }else{
        return n;
    }
}


// last_digit(n) consumes n, an int, and produces the last
// digit of n.
// examples: last_digit(54321) == 1
int last_digit(const int n){
    return (n % 10);
}


// nth_power_of_ten(n) consumes n, an int, and produces the
// value of 10^n
int nth_power_of_ten(const int n){
    if (n > 0) {
        return 10 * (nth_power_of_ten(n - 1));
    }else{
        return 1;
    }
}


// remove_first_last_digit(n) consumes n, and int, and produces
// a number value that is n with its first and last value removed
// requires: n must be atleast 3 digits long.
int remove_first_last_digit(const int n){
    return (.1 * (n - (first_digit(n) *
                       (nth_power_of_ten (count_digits(n) -1)))));
}



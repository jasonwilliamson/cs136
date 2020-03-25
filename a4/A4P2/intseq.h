// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 2
// File: intseq.h
// ====================================================
//

// A module for keeping track of the statistics on a sequence of integers

#include <stdio.h>
#include <assert.h>


// next_number(n) processes the next number in a sequence of integers
//   effects: integer n is processed
//         (this will change the return value of other functions)
void next_number(int n);


// prev_number() returns the most recently processed number
//    requires: number_count() > 0
int prev_number(void);


// number_count() returns the number of integers processed so far
int number_count(void);


// number_sum() returns the sum of the integers processed so far
//    requires:  number_count() > 0
int number_sum(void);


// max_number() returns the largest processed number
//    requires:  number_count() > 0
int max_number(void);


// min_number() returns the smallest processed number
//    requires:  number_count() > 0
int min_number(void);


// minmax_dist() returns the quantity of numbers that have been processed between
//      the first appearance of the min number
//      and the first appearance of the max number
//    requires:  number_count() > 0
//    examples:
//      sequence: 100 200, the distance is 1 (between 100 and 200)
//      sequence: -1 10 0 8 -10 5, the distance is 3 (between 10 and -10)
//      sequence: -1 10 0 10 -10 5, the distance is 3 (between 10 and -10)
//      sequence: 42, the distance is 0 (between 42 and 42)
int minmax_dist(void);


// reset_seq() clears all statistics and returns module to its initial state
//   effects: resets to initial state (no numbers processed yet)
//         (this will change the return value of other functions)
void reset_seq(void);



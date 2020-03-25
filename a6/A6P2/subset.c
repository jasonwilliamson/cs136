// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 2
// File: subset.c
// ====================================================
//

#include "subset.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


// has_dupe(arr[], len) consumes arr[] a pointer to an array or int's, and
// len the legth of arr. Returing true if the array contains duplicate values
// otherwise returning false.
static bool has_dupe(int arr[], int len){
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if ((i != j) && (arr[i] == arr[j])) {
                return true;
            }
        }
    }
    return false;
}


// subset(arr, len, sum) outputs each combination (solution) of 3
//   integers in arr that add to sum followed by a message with the
//   total number of solutions or a message if no solutions exist.
// requires: arr is not NULL, arr has no duplicates, and len >= 0
// effects: if no solutions exist, output "No solution(s)\n".
//   if one or more solutions exist, output "x1 + x2 + x3 = y\n"
//   where the index of x1 < index of x2 < index of x3
//   for each solution, followed by "A total of z solution(s)\n",
//   where z is the total number of solutions.
void subset(int arr[], int len, int sum) {
    assert(arr != NULL);
    assert(len >= 0);
    assert(!has_dupe(arr, len));
    int total_solns = 0;
    for (int i = 0; i < (len - 2); ++i) {
        for (int j = (i + 1); j < (len - 1); ++j) {
            for (int k = (j + 1); k < len; ++k) {
                if (sum == arr[i] + arr[j] + arr[k]) {
                    printf("%d + %d + %d = %d\n", arr[i], arr[j], arr[k], sum);
                    ++total_solns;
                }
            }
        }
    }
    if (total_solns > 0) {
        printf("A total of %d solutions(s)\n", total_solns);
    }
}

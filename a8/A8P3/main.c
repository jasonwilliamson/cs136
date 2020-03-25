// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 3
// File: skipints.c
// ====================================================
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


// This program reads in a sequence of of positive integers until 0 is encountered
// The program then reads in a final positive integer k. The program then prints every
// k-th integer from the original sequence of integers. Each integer printed is followed
// by a newline.
// time: O(n), where n is number of integers read
// effects: may print to screen
// requires: reads in only positive integers
//           EOF is not encountered
int main() {
    int val;
    bool final = false;
    int final_val = 0;
    
    int max = 64;
    int bytes = sizeof(int) * max;
    int * int_arr = malloc(bytes);
    int len = 0;
    
    while (1) {
        scanf("%d", &val);
        if (final) {
            final_val = val;
            break;
        }
        else if (0 == val){
            final = true;
        }else{
            if (len == (max / sizeof(int))) {
                if (len == INT_MAX) {
                    // max int length reached
                    final_val = 0;
                    break;
                }else if (INT_MAX <= (max *= 2)){
                    max = INT_MAX;
                }
                max *= 2;
                bytes = sizeof(int) * max;
                int_arr = realloc(int_arr, max);
            }
            int_arr[len] = val;
            ++len;
        }
    }
    
    for (int i = 0; i < len; ++i) {
        if (0 == ((i+1) % final_val)) {
            printf("%d\n", int_arr[i]);
        }
    }
    free(int_arr);
}

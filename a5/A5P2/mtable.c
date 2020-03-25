// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 2
// File: mtable.c
// ====================================================
//

#include "mtable.h"
#include <stdio.h>
#include <assert.h>

// mtable(w,h) prints a multiplication table with w columns
// and h rows.
// requires: 1 <= w <= 14 and 1 <= h <= 70
void mtable(int w, int h) {
    assert((w >= 1)&&(w <= 14));
    assert((h >= 1)&&(h <= 70));
    for (int i = 0; i <= (h + 1); ++i) {
        for (int j = 0; j <= w; ++j) {
            if (0 == i) {
                if (0 == j) {
                    printf("  X |");
                }else{
                    printf("%4d ", j);
                }
            }else if (1 == i){
                printf("-----");
            }else{
                if (0 == j) {
                    printf("%3d |", (i-1));
                }else{
                    printf("%4d ", (i-1)*j);
                }
            }
        }
        printf("\n");
    }
}

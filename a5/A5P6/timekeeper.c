// =======================================
// = CS136, S15: Assignment 5, Problem 6 =
// = =================================== =
// = Author: Salmon [12345678]           =
// =======================================

// Implementation for a C module that provides functions to work with various
// times.

#include "timekeeper.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// See interface (timekeeper.h).
struct time T(int hour, int minute, int second) {
    struct time retval = { 0, 0, 0 };
    
    if (((hour >= 0) && (hour < 24)) &&
        ((minute >= 0) && (minute < 60)) &&
        ((second >= 0) && (second < 60))) {
        retval.hour = hour;
        retval.minute = minute;
        retval.second = second;
    }
    
    return retval;
}

// See interface (timekeeper.h).
bool time_equal(struct time *t1, struct time *t2) {
    // Checks pre-conditions.
    assert(t1 != NULL);
    assert(t2 != NULL);
    
    return ((t1->hour == t2->hour) &&
            (t1->minute == t2->minute) &&
            (t1->second == t2->second));
}

// See interface (timekeeper.h).
void time_tick(struct time *t) {
    // Checks pre-conditions.
    assert(t != NULL);
    
    t->second += 1;
    
    if (t->second == 60) {
        t->second = 0;
        t->minute += 1;
        
        if (t->minute == 60) {
            t->minute = 0;
            t->hour += 1;
            
            if (t->hour == 24) {
                t->hour = 0;
            }
        }
    }
}

// See interface (timekeeper.h).
void time_twelve(struct time *t) {
    // Checks pre-conditions.
    assert(t != NULL);
    
    const bool PM = t->hour / 12;
    
    if (PM) {
        printf("%.2d", (t->hour == 12) ? 12 : t->hour % 12);
    } else {
        printf("%.2d", (t->hour == 0) ? 12 : t->hour);
    }
    
    printf(":%.2d:%.2d ", t->minute, t->second);
    
    if (PM) {
        printf("PM");
    } else {
        printf("AM");
    }
    
    printf("\n");
}

// See interface (timekeeper.h).
void time_print(struct time *t) {
    // Checks pre-conditions.
    assert(t != NULL);
    
    printf("%.2d:%.2d:%.2d\n", t->hour, t->minute, t->second);
}


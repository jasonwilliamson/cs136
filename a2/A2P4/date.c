// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 4
// File: date.c
// ====================================================

#include "date.h"


static bool is_leap_year(const struct date d);


// see date.h for details
bool is_valid(const struct date d) {
    if ((4 == d.month) ||
        (6 == d.month) ||
        (9 == d.month) ||
        (11 == d.month)){
        if (d.day <= 30) {
            return true;
        }else{
            return false;
        }
    // checking for leap year
    }else if (2 == d.month){
        if ((is_leap_year(d)) &&
             (d.day <= 29)) {
            return true;
        }else if(d.day <= 28){
            return true;
        }else{
            return false;
        }
    // checking remaining valid months of 31 days
    }else if ((d.month >= 0) && (d.month <= 12)){
        if(d.day <= 31){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}


// see date.h for details
// requires: d1, d2 are valid dates
bool d_eq(const struct date d1, const struct date d2) {
    if ((d1.year == d2.year) &&
        (d1.month == d2.month) &&
        (d1.day == d2.day)){
        return true;
    }else{
        return false;
    }
}


// greaterthan(d1,d2) determines if d1 is after the d2 date.
// requires: d1, d2 are valid dates
bool greaterthan(const struct date d1, const struct date d2) {
    if (d2.year < d1.year) {
        return true;
    }else if (d2.year == d1.year){
        if (d2.month < d2.month) {
            return true;
        }else if (d2.month == d2.month){
            if (d2.day < d2.day) {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}


// is_leap_year(d) cosumes d, a struct date and produces true if
// the date meets criteria for a leap year other wise returning false
static bool is_leap_year(const struct date d){
    if (0 ==(d.year % 400)) {
        return true;
    }else if(0 == (d.year % 100)){
        return false;
    }else if(0 == (d.year % 4)){
        return true;
    }else{
        return false;
    }
}

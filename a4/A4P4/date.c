// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 2
// File: date.c
// ====================================================
//

#include "date.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

static bool is_leap_year(const struct date *d);


// see header file
bool is_valid(const struct date *d) {
    assert(d != NULL);
    if ((d->year < 0) ||
        (d->month < 0) ||
        (d->day < 0)){
        return false;
    }else if ((4 == d->month) ||
              (6 == d->month) ||
              (11 == d->month)) {
        if (d->day <= 30) {
            return true;
        }else{
            return false;
        }
    // checking for leap year
    }else if (2 == d->month){
        if ((is_leap_year(d)) &&
            (d->day <= 29)){
            return true;
        }else if(d->day <= 28){
            return true;
        }else{
            return false;
        }
    // checking remaining valid months of 31 days
    }else if (d->month <= 12){
        if (d->day <= 31) {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
    
}


// see header file
// requires: d1, d2 are not NULL, *d1, *d2 are valid dates
bool d_eq(const struct date *d1, const struct date *d2) {
    assert(d1 != NULL);
    assert(d2 != NULL);
    assert(is_valid(d1));
    assert(is_valid(d2));
    
    if ((d1->year == d2->year) &&
        (d1->month == d2->month) &&
        (d1->day) == d2->day)
    {
        return true;
    }else{
        return false;
    }
}


// see header file
// requires: d1, d2 are not NULL, and *d1, *d2 are valid dates
bool greaterthan(const struct date *d1, const struct date *d2) {
    assert(d1 != NULL);
    assert(d2 != NULL);
    assert(is_valid(d1));
    assert(is_valid(d2));
    
    if (d1->year > d2->year) {
        return true;
    }else if(d1->year == d2->year){
        if (d1->month > d2->month) {
            return true;
        }else if (d1->month == d2->month){
            if (d1->day > d2->day) {
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

// see header file
void tomorrow(struct date *d) {
    assert(d != NULL);
    assert(is_valid(d));
    int year = d->year;
    int month = d->month;
    int day = d->day;
    ++day;
    
    if ((4 == month) ||
        (6 == month) ||
        (11 == month)){
        if (day > 30) {
            ++month;
            day = 1;
        }
    }else if (2 == month){
        if (is_leap_year(d)) {
            if (day > 29) {
                ++month;
                day = 1;
            }
        }else if (day > 28){
            ++month;
            day = 1;
        }
    }else if (day > 31){
        ++month;
        day = 1;
    }
    
    if (month > 12) {
        ++year;
        month = 1;
    }
    
    d->year = year;
    d->month = month;
    d->day = day;
}

// see header file
void yesterday(struct date *d) {
    assert(d != NULL);
    assert(is_valid(d));
    
    int year = d->year;
    int month = d->month;
    int day = d->day;
    --day;
    
    if (day < 1) {
        if ((4 == month) ||
            (6 == month) ||
            (11 == month)){
            day = 30;
            --month;
        }else if (2 == month){
            if (is_leap_year(d)) {
                day = 29;
                --month;
            }else{
                day = 28;
                --month;
            }
        }else{
            day = 31;
            --month;
        }
    }
    
    if (month < 1) {
        month = 12;
        --year;
    }
    
    d->year = year;
    d->month = month;
    d->day = day;
}


// is_leap_year(d) cosumes d, a struct date and produces true if
// the date meets criteria for a leap year other wise returning false
static bool is_leap_year(const struct date *d){
    if (0 ==(d->year % 400)) {
        return true;
    }else if(0 == (d->year % 100)){
        return false;
    }else if(0 == (d->year % 4)){
        return true;
    }else{
        return false;
    }
}





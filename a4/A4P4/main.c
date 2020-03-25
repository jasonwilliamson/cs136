//
//  main.c
//  A4P4
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "date.h"
#include <assert.h>

const struct date date1 = {12,33,2013};
const struct date date2 = {12,23,2013};
const struct date date3 = {2,10,2010};
const struct date date4 = {12,23,2013};
const struct date date5 = {2,29,2100};
struct date d6 = {12, 31, 1999};
struct date d7 = {1,1,2000};

int main(int argc, const char * argv[]) {
    assert(is_valid( &date1 )==false);
    assert(d_eq(&date4 ,&date2)== true);
    assert(is_valid(&date5)==false);
    assert(greaterthan(&date2,&date3) == true);
    tomorrow(&d6);
    printf("tomorrow %d %d %d\n",d6.month, d6.day, d6.year );
    yesterday(&d6);
    printf("yesterday %d %d %d\n",d6.month, d6.day, d6.year );
    //assert(d_eq( tomorrow(&d6), &d7) == true);
    printf("Hello, World!\n");
    return 0;
}

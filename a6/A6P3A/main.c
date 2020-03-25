//
//  main.c
//  A6P3A
//
//  Created by Jason Williamson on 2015-06-27.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "intseq.h"
#include "fequals.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[] = {1, 2, 3};
    assert(number_sum(a, 3) == 6);
    max_number(a,3);
    assert(max_number(a,3) == 3);
    assert(min_number(a,3) == 1);
    assert(seq_has_duplicates(a,3) == false);
    //minmax_dist(a,3);
    assert(minmax_dist(a,3) == 2);
    assert(fequals(seq_avg(a,3), 2.0)); // fequals as defined in assignment 3.
    assert(seq_most_occurrences(a,3) == 1);
    return 0;
}

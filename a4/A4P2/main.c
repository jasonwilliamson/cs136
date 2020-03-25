//
//  main.c
//  A4P2
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "intseq.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(number_count() == 0);
    next_number(42);
    assert(prev_number() == 42);
    assert(number_count() == 1);
    reset_seq();
    
    next_number(100);
    next_number(200);
    assert(minmax_dist() == 1);
    reset_seq();
    
    next_number(-1);
    next_number(10);
    next_number(0);
    next_number(8);
    next_number(-10);
    next_number(5);
    assert(number_count() == 6);
    assert(prev_number() == 5);
    printf("Hello, dist == %d \n", minmax_dist());
    assert(minmax_dist() == 3);
    
    return 0;
}

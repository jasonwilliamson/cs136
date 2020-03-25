//
//  main.c
//  A3P0A
//
//  Created by Jason Williamson on 2015-05-29.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "count_ones.h"
#include <assert.h>

int main(int argc, const char * argv[]) {

    printf("nth_power_base_2 , 2^3 == %d \n", nth_power_base_2(3));
    assert(nth_power_base_2(3) == 8);
    assert(nth_power_base_2(7) == 128);
    assert(nth_power_base_2(0) == 1);
    
    assert(highest_nth_power(111, 1) == 6);
    
    assert (count_ones(1) == 1);
    assert (count_ones(7) == 3);
    assert (count_ones(32421) == 10);
    assert(count_ones(0) == 0);
    
    return 0;
}

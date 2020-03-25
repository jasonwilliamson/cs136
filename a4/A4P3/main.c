//
//  main.c
//  A4P3
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "count_primes.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(count_primes(5,19) == 6); // because 5,7,11,13,17,19
    
    return 0;
}

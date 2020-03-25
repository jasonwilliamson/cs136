//
//  main.c
//  A4P0B
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "is_prime.h"
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(is_prime(5));
    assert(!is_prime(25));
    
    
    return 0;
}

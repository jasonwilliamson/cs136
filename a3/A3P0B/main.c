//
//  main.c
//  A3P0B
//
//  Created by Jason Williamson on 2015-05-29.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "fequals.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(fequals(8/3.0, 2.66666));
    printf("fequals(8/3.0, 2.6666) == %d \n", fequals(8/3.0, 2.6666));
    assert(!fequals(8/3.0, 2.6666));
    
    return 0;
}

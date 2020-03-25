//
//  main.c
//  A4P0C
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "next.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(next() == 1);
    assert(next() == 2);
    assert(next() == 3);
    
    return 0;
}

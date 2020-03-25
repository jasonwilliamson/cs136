//
//  main.c
//  A6P0A
//
//  Created by Jason Williamson on 2015-06-27.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "count_pos.h"
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int a[10] = {1, 2, 3, 4, 0, -1, -2, -3, -4, 5};
    assert(count_pos(a,10) == 5);
    assert(count_pos(a,5) == 4);
    
    return 0;
}

//
//  main.c
//  A2P5B
//
//  Created by Jason Williamson on 2015-05-24.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "mathfunc.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(max2(5, 2)==5);
    assert(max2(5, 20)==20);
    assert(max2(20, 20)==20);
    
    assert(min2(5, 2)==2);
    assert(min2(5, 20)==5);
    assert(min2(5, 5)==5);
    
    assert(maxfactor(100)==50);
    assert(maxfactor(9)==3);
    assert(maxfactor(7)==1);
    
    assert(is_cube_perfect(125) == true);
    assert(is_cube_perfect(8) == true);
    
    printf("is_cube_perfect(1345423) == %d \n", is_cube_perfect(1345423));
    assert(is_cube_perfect(1345423) == false);
    assert(is_cube_perfect(157464) == true);
    printf("is_cube_perfect(1345423) == %d \n", is_cube_perfect(997002999));
    assert(is_cube_perfect(997002999) == true);
    return 0;
}

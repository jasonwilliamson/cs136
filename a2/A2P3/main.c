//
//  main.c
//  A2P3
//
//  Created by Jason Williamson on 2015-05-23.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "squarenum.h"
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    /*printf("is_squarenum(49) %d \n", is_squarenum(49));
    printf("is_squarenum(50) %d \n", is_squarenum(50));
    printf("is_squarenum(4) %d \n", is_squarenum(4));
    printf("next_squarenum(16) == %d \n", next_squarenum(16));
    printf("count_sqnum(14, 17) 1 == %d \n", count_sqnum(14, 17));
    printf("count_sqnum(1, 15) 2 == %d \n", count_sqnum(1, 15));*/
    assert(is_squarenum(100)==true);
    assert(is_squarenum(231)==false);
    assert(next_squarenum(16)==25);
    return 0;
}

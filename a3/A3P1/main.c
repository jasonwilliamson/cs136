//
//  main.c
//  A3P1
//
//  Created by Jason Williamson on 2015-05-29.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "name_char.h"
#include <assert.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {

    printf("Hello, name_char('c') == %d \n", 'c');
    assert(name_char('5') == true);
    assert(!name_char('?'));
    assert(!name_char('/'));
    
    return 0;
}

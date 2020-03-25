//
//  main.c
//  A6P0B
//
//  Created by Jason Williamson on 2015-06-27.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>


#include "case-catcher.h"

// Stores the size of the buffer. This is the length of the string. This can be
// increased and decreased as needed.
//static const int BUFFER_SIZE = 1024;

int main(void) {
    /*char buffer[BUFFER_SIZE + 1];
    char c;
    
    // Zero-fills the buffer.
    for (int i = 0; i < BUFFER_SIZE + 1; ++i) {
        buffer[i] = '\0';
    }
    
    for (int i = 0; (EOF != (c = getchar())) && (i < BUFFER_SIZE); ++i) {
        buffer[i] = c;
    }
    
    printf("%c\n", is_proper_case(buffer) ? 'y' : 'n');*/
    
    assert(is_proper_case("Hello world.") == true);
    assert(is_proper_case("hello world.") == true);
    assert(is_proper_case("i like C language.very much.") == false);
    assert(is_proper_case("The dog ran down the street.He likes running.") == true);
    assert(is_proper_case("This sentence is not.correct.") == false);
    
    return 0;
}


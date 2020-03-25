//
//  main.c
//  A6P0C
//
//  Created by Jason Williamson on 2015-06-27.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "string-map.h"
#include <assert.h>

// rot13(c) returns the rot13 of c (a letter substitution cipher) if c is an
// uppercase letter.
static char rot13(char c) {
    char retval = c;
    
    if ((c >= 'A') && (c <= 'Z')) {
        retval = (c >= 'N') ? c - 13 : c + 13;
    }
    
    return retval;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char s[] = "AB";
    string_map(s, rot13); //rot13 defined in
    assert ((s[0] == 'N') && (s[1] == 'O'));
    
    return 0;
}

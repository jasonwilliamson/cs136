//
//  main.c
//  A7P4
//
//  Created by Jason Williamson on 2015-07-05.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "anagrams.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char s1[] = "florence nightingale";
    char s2[] = "comedian";
    char s3[] = "orchestra";
    char s4[] = "anagram";
    char s5[] = "flit on cheering angel";
    char s6[] = "demoniac";
    char s7[] = "carthorse";
    char s8[] = "abc";
    char s9[] = "bca";
    
    char *arr[] = {s1, s2, s3, s4, s5, s6, s7};
    assert(count_anagrams(arr, 7) == 2);
    
    char *arr2[] = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
    assert(count_anagrams(arr2, 9) == 3);
    printf("Hello, World!\n");
    return 0;
}

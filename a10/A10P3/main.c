//
//  main.c
//  A10P3
//
//  Created by Jason Williamson on 2015-07-26.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "file2strqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strqueue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    //file2StrQueue("text.txt");
    
    char s1[] = "florence";
    char s2[] = "comedian";
    char s3[] = "orchestra";
    char s4[] = "anagram";
    char s5[] = "flit";
    char s6[] = "demoniac";
    char s7[] = "carthorse";
    char s8[] = "abc";
    char s9[] = "bca";
    
    char *arr[] = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
    
    
    //char word[100]; // artificial limit on word size
    StrQueue sq = create_StrQueue();
    
    int len = 0;
    while (len < 9) {
        sq_add_back(sq, arr[len]);
        ++len;
    }
    
    char *tmp = sq_remove_front(sq);
    
    printf("remove from front %s\n", tmp);
    
    free(tmp);
    
    //return sq;
    return 0;
}

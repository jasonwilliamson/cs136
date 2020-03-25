//
//  main.c
//  A7P0A
//
//  Created by Jason Williamson on 2015-07-02.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include "ang.h"
#include <assert.h>
#include "ccount.h"

int main() {
    /*int a[] = {9, 4, 0, 7, 2, 6, 5, 1 };
    char b[] = {'z','4','a','7','2','A','5','1'};
    char *c[] = {"9", "ab", "a", "aa", "111111", "11", "0", "0"};
    
    sort_int(a, 8);
    sort_char(b, 8);
    sort_str(c, 8);
    
    for(int i = 0; i < 8; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
    
    for(int i = 0; i < 8; i++)
    {
        printf(" %c", b[i]);
    }
    printf("\n");

    for(int i = 0; i < 8; i++)
    {
        printf(" %s", c[i]);
    }   
    printf("\n");
    
    char c3[] = "abc";
    char c4[] = "bac";
    assert(is_anagrams(c3, c4));
    
    is_anagrams(c3, c4);
    
    char c1[] = "comedian";
    char c2[] = "demoniac";
    assert(is_anagrams(c1, c2));
    
    
    
    char c5[] = "abc";
    char c6[] = "a bc";
    assert(!is_anagrams(c5, c6));
    
    char c7[] = "abc";
    char c8[] = "abc";
    assert(is_anagrams(c7,c8));
    
    char c9[] = "william shakespeare";
    char c10[] = "i am a weakish speller";
    assert(!is_anagrams(c9, c10));
    
    char c11[] = "i am a weakish speller";
    char c12[] = "   william shakespeare";
    assert(is_anagrams(c11, c12));*/
    
    char s1[] = "a1jklsdo";
    char s2[] = "co";
    char s3[] = "string1";
    char s4[] = "nothing here";
    char s5[] = "another 1";
    
    char *arr[] = {s1, s2, s3, s4, s5};
    printf("%d\n", ccount(arr, 5, '1'));
    printf("%d\n", ccount(arr, 5, 'o'));
    printf("%d\n", ccount(arr, 5, 'O'));
    
    assert(ccount(arr, 5, '1') == 3);
    assert(ccount(arr, 5, 'o') == 4);
    assert(ccount(arr, 5, 'O') == 0);
    
}

// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 10, Problem 5
// File:spellcheck.c
// ====================================================
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "dictionary.h"
#include "file2strqueue.h"

// for convenience: this is how you represent an apostrophe (')
const char apostrophe = '\'';

// a simple void * wrapper for strcmp
int strcmp_wrapper(const void *a, const void *b) {
    assert(a);
    assert(b);
    const char *str_a = a;
    const char *str_b = b;
    return strcmp(str_a, str_b);
}

// Because the Dictionary ADT uses key/value pairs,
// and for the wordlist dictionary, we only need keys
// we can use the VALID pointer for every value
int valid = 1;
void *VALID = &valid;

// but we don't want our Dictionary ADT free-ing VALID,
// so we need a function that does not free anything
// (to pass to the create_Dictionary function)
void do_nothing(void *p) {
    return;
}



// lower_case_version(str) consumes a string pointer, duplicating its contents
// and returning it's new string pointer
// effects: malloc's a string on the heap
//          caller must free the new string
// time: O(n) where n is the length of str
char *lower_case_version(char *str) {
    assert(str);
    int len = strlen(str);
    char *tmp = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i) {
        if ((str[i] >= 'A') && (str[i] <= 'Z')) {
            tmp[i] = str[i] - 'A' + 'a';
        }else{
            tmp[i] = str[i];
        }
    }
    tmp[len] = '\0';
    return tmp;
}


int main(void) {
    
    
    // create the wordlist dictionary
    Dictionary wordlist = create_Dictionary(strcmp_wrapper, free, do_nothing);
    
    // read in the words from the file to a string queue
    StrQueue sq = file2StrQueue("wordlist.txt");
    
    // for each word in the queue, insert it into the dictionary
    while (sq_length(sq)) {
        char *word = sq_remove_front(sq);   // remove word from queue
        insert(wordlist, word, VALID);      // insert it to Dictionary (with the value of VALID)
    }
    // now lookup(wordlist, my_word) will either return VALID or NULL
    destroy_StrQueue(sq);   // you can now re-use this sq pointer if you want.
    sq = NULL;
    
    
    // the rest is up to you... have fun!
    
    // create the autocorrect dictionary
    Dictionary autocorret = create_Dictionary(strcmp_wrapper, free, free);
    
    // read in the words from the file to a string queue
    sq = file2StrQueue("autocorrect.txt");
    while (sq_length(sq)) {
        char *key_word = sq_remove_front(sq);
        char *value_word = sq_remove_front(sq);
        insert(autocorret, key_word, value_word);
    }
    destroy_StrQueue(sq);   // you can now re-use this sq pointer if you want.
    sq = NULL;
    
    
    sq = file2StrQueue(false);
    int word_count = 0;
    while (sq_length(sq)){
        char *word = sq_remove_front(sq);
        char *lower = lower_case_version(word);
        char *lower_cpy = lower;
        bool other_char = false;
        while(*lower_cpy){
            if(((*lower_cpy >= 'A') && (*lower_cpy <= 'Z')) || ((*lower_cpy >= 'a') &&
                                                                (*lower_cpy <= 'z')) || (*lower_cpy == 43)){
                ++lower_cpy;
                continue;
            }else{
                other_char = true;
                break;
            }
        }
        
        if(other_char){
            printf("_%s_", word);
        }else if (lookup(wordlist, lower)!= NULL){
            printf("%s", word);
        }else{
            char *val = lookup(autocorret, word);
            if(val != NULL) {
                printf("*%s*", val);
            }else{
                printf("[%s]", word);
            }
        }
        
        free(word);
        free(lower);
        lower_cpy = NULL;
        ++word_count;
        if ((word_count%10) == 0) {
            printf("\n");
        }else if(sq_length(sq)>0){
            printf(" ");
        }
    }
    
    
    
    destroy_StrQueue(sq);
    sq = NULL;
    // don't forget to free your memory
    destroy_Dictionary(wordlist);
    destroy_Dictionary(autocorret);
    
}



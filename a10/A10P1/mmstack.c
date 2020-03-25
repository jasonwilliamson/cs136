// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 10, Problem 1
// File: mmstack.c
// ====================================================
//

#include "mmstack.h"
#include <stdlib.h>
#include <assert.h>


// a llnode (linked list node)
// is a stucture containing a pointer to its
// on stucture type.
struct llnode {
    int item;
    struct llnode *next;
    int max;
    int min;
};

struct mmstack{
    struct llnode *topnode;
    int length;
};


// see mmstack.h for details
MMStack create_MMStack(void){
    MMStack new = malloc(sizeof(struct mmstack));
    new->topnode = NULL;
    new->length = 0;
    return new;
}


// see mmstack.h for details
void destroy_MMStack(MMStack mms){
    while (mms->length > 0) {
        mms_pop(mms);
    }
    free(mms);
}


// see mmstack.h for details
int mms_length(MMStack mms){
    return mms->length;
}


// see mmstack.h for details
void mms_push(MMStack mms, int i){
    struct llnode *newnode = malloc(sizeof(struct llnode));
    newnode->item = i;
    
    if (mms->length == 0) {
        newnode->max = i;
        newnode->min = i;
    }else{
        if (i > mms->topnode->max) {
            newnode->max = i;
        }else{
            newnode->max = mms->topnode->max;
        }
        
        if (i < mms->topnode->min) {
            newnode->min = i;
        }else{
            newnode->min = mms->topnode->min;
        }
    }

    newnode->next = mms->topnode;
    mms->topnode = newnode;
    mms->length += 1;
}


// see mmstack.h for details
int mms_pop(MMStack mms){
    assert(mms->length > 0);
    int val = mms->topnode->item;
    struct llnode *tmp = mms->topnode;
    mms->topnode = tmp->next;
    mms->length -= 1;
    free(tmp);
    return val;
}


// see mmstack.h for details
int mms_min(MMStack mms){
    assert(mms->length > 0);
    return mms->topnode->min;
}


// see mmstack.h for details
int mms_max(MMStack mms){
    assert(mms->length > 0);
    return mms->topnode->max;
}


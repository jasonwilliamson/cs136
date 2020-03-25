// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 09, Problem 0
// File: mylist.c
// ====================================================
//

#include "mylist.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


struct lnode {
    int item;
    struct lnode *next;
};

// destroy_list(lst) frees all memory allocated for lst
//   requires: lst is a valid list
//   effects: lst is destroyed
//   time: O(n) where n is the length of lst
void destroy_list(struct lnode *lst) {
    struct lnode *next;
    while (lst != NULL) {
        next = lst->next;  // note the next pointer
        free(lst);         // delete the node
        lst = next;        // advance to the next node
    }
}


// print_list(lst) prints the items in the list lst from front to back
//   requires: lst is valid
//   effects: all elements in lst printed using "  %d", followed by "\n" at the end
//   time: O(n) where n the length of lst
void print_list(struct lnode *lst) {
    struct lnode *current;
    for (current = lst; current != NULL; current = current->next) {
        printf("  %d", current->item);
    }
    printf("\n");
}


int main(void)
{
    
    // YOUR CODE SHOULD BE ADDED HERE
    // DO NOT USE ANY HELPER FUNCTIONS:
    // CONSTRUCT YOUR LIST MANUALLY, USING DYNAMIC MEMORY
    int incr = 1;
    struct lnode * last = NULL;
    int bytes = sizeof(struct lnode);
    
    while (incr <= 9) {
        
        struct lnode * llst = malloc(bytes);
        llst->item = incr;
        llst->next = last;
        last = llst;
        ++incr;
    }
    
    struct lnode * myl = malloc(bytes);
    myl->item = incr;
    myl->next = last;
    
    print_list(myl);
    destroy_list(myl);
    return 0;
}




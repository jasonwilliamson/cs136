// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 09, Problem 0b
// File: mytree.c
// ====================================================
//

#include <stdlib.h>
#include <stdio.h>

struct bstnode {
    int item;
    struct bstnode *left;
    struct bstnode *right;
};


// destroy_tree(t) frees all memory allocated for tree t
//   requires: t is a valid tree
//   effects: all memory allocated for tree is freed
//   time: O(n) where n is the number of nodes in t
void destroy_tree(struct bstnode *t) {
    if (NULL == t) {return;}
    destroy_tree(t->left);
    destroy_tree(t->right);
    free(t);
}

// inorder_print(t) prints the values in t in certain order.
//   requires: t is a valid tree
//   effects: all elements in the tree t will be printed
//   time: O(n) where n is the number of nodes in t
void inorder_print(struct bstnode *t) {
    if (NULL == t) {return;}
    inorder_print(t->left);
    printf("  %d", t->item);
    inorder_print(t->right);
}

int main(void) {
    
    
    // YOUR CODE SHOULD BE ADDED HERE
    // DO NOT USE ANY HELPER FUNCTIONS:
    // CONSTRUCT YOUR TREE MANUALLY, USING DYNAMIC MEMORY
    int bytes = sizeof(struct bstnode);
    struct bstnode *ln = malloc(bytes);
    ln->item = 20;
    ln->left = NULL;
    ln->right = NULL;
    
    struct bstnode *rn = malloc(bytes);
    rn->item = 78;
    rn->left = NULL;
    rn->right = NULL;
    
    struct bstnode *myt = malloc(bytes);
    myt->item = 35;
    myt->left = ln;
    myt->right = rn;
    
    
    
    inorder_print(myt);
    printf("\n");
    destroy_tree(myt);
}


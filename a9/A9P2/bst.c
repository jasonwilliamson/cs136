// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 09, Problem 2
// File: bst.c
// ====================================================
//

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "bst.h"

// see bst.h documentation
struct btree *create_bst(void) {
    struct btree *tree = malloc(sizeof(struct btree));
    tree->root = NULL;
    return tree;
}


// see bst.h documentation
struct bstnode *make_bstnode(int val, struct bstnode *l, struct bstnode *r) {
    struct bstnode *new = malloc(sizeof(struct bstnode));
    new->item = val;
    new->left = l;
    new->right = r;
    return new;
}


// destroy_node(node) is a helper for destroy_tree
// see bst.h documentation
void destroy_node(struct bstnode *node) {
    if (NULL == node) {return;}
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
}


// see bst.h documentation
void destroy_bst(struct btree *t){
    destroy_node(t->root);
    free(t);
}


// see bst.h documentation
bool is_bempty(struct btree *t){
    assert(t);
    return (NULL == t->root);
}


// inorder_node(node) is a helper for traverse_inorder
// see bst.h documentation
void inorder_node(struct bstnode *node) {
    if (NULL == node) {return;}
    inorder_node(node->left);
    printf("  %d", node->item);
    inorder_node(node->right);
}

// see bst.h documentation
void traverse_inorder(struct btree *t){
    assert(t);
    inorder_node(t->root);
    printf("\n");
}


// YOUR IMPLEMENTATION STARTS HERE


// see bst.h documentation
void bst_insert(int val, struct btree *t){
    assert(t);
    struct bstnode *prev = NULL;
    struct bstnode *cur = t->root;
    while (cur != NULL) {
        if (val == cur->item) {
            return;
        }
        prev = cur;
        if (val < cur->item) {
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
    struct bstnode *new = make_bstnode(val, NULL, NULL);
    if (NULL == prev) {
        t->root = new;
    }
    else if (val < prev->item) {
        prev->left = new;
    } else {
        prev->right = new;
    }
}


// see bst.h documentation
bool bst_search(struct btree *t, int val){
    assert(t);
    struct bstnode *cur = t->root;
    if (NULL == cur) {
        return false;
    }
    
    while (cur != NULL) {
        if (val == cur->item) {
            return true;
        }
        if (val < cur->item) {
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
    return false;
}


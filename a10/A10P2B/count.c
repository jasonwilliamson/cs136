// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 10, Problem 2b
// File: count.c
// ====================================================
//

#include "count.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>


// A Binary Search Tree Node (bstnode)
struct bstnode{
    int item;
    int count;
    struct bstnode *left;
    struct bstnode *right;
};


struct count{
    struct bstnode *node;
    int total;
    int unique_count;
    int max_count;
    int max_item;
};


// create_bstnode() creates a new empty bstnode
// effects: allocates a struct bstnode on the heap
//          client must eventually destroy call
//          destroy_node
// time: O(1)
struct bstnode *create_bstnode(void){
    int bytes = sizeof(struct bstnode);
    struct bstnode *new_bstnode = malloc(bytes);
    new_bstnode->count = 0;
    new_bstnode->left = NULL;
    new_bstnode->right = NULL;
    return new_bstnode;
}


// see count.h for details
Count create_Count(void){
    int bytes = sizeof(struct count);
    Count new_count = malloc(bytes);
    new_count->node = create_bstnode();
    new_count->total = 0;
    new_count->unique_count = 0;
    new_count->max_count = 0;
    new_count->max_item = 0;
    return new_count;
}


// destroy_node(node) is a helper for destroy_Count
// see count.h documentation
// recursively free's all nodes within a BST given
// a root node
// time: O(n), where n = unique(c)
void destroy_node(struct bstnode **node) {
    if (NULL == *node) {return;}
    destroy_node(&(*node)->left);
    destroy_node(&(*node)->right);
    free(*node);
}


// see count.h for details
void destroy_Count(Count c){
    destroy_node(&(c->node));
    free(c);
}


// see count.h for details
void insert(struct bstnode **node, int i, Count c){
    if (*node == NULL) {
        *node = create_bstnode();
        (*node)->item = i;
        (*node)->count = 1;
        c->unique_count += 1;
        return;
    }else if (i == (*node)->item){
        (*node)->count += 1;
        int cnt = (*node)->count;
        if (c->max_count < cnt) {
            c->max_count = cnt;
            c->max_item = i;
        }
        return;
    }else if (i < (*node)->item){
        insert(&(*node)->left, i, c);
    }else if (i > (*node)->item){
        insert(&(*node)->right, i, c);
    }
}


// see count.h for details
void next(Count c, int i){
    if (0 == c->total) {
        c->node->item = i;
        c->node->count = 1;
        c->max_count = 1;
        c->max_item = i;
        c->unique_count = 1;
    }else{
        insert(&(c->node), i, c);
    }
    c->total += 1;
}


// see count.h for details
int total(Count c){
    return c->total;
}


// see count.h for details
int unique(Count c){
    return c->unique_count;
}


// bst_search(*node, i) searches contents of node for
// an item match agains i. Function returns the occurence
// count of that item, if item i is not found, function returns 0
// time:  O(n), where n = unique(c)
int bst_search(struct bstnode *node, int i){
    if (node == NULL) {
        return 0;
    } else if (i == node->item) {
        return node->count;
    } else if (i < node->item) {
        return bst_search(node->left, i);
    } else{
        return bst_search(node->right, i);
    }
}


// see count.h for details
int count(Count c, int i){
    return bst_search(c->node, i);
}


// see count.h for details
int mostfreq(Count c){
    return c->max_item;
}


// inorder_node(node, c) is a helper for stats
// see bst.h documentation
// consumes a root node and recursively prints bstnode
// node values for each unique i in c in ascending order
// time: O(n), where n = unique(c)
void inorder_node(struct bstnode *node, Count c) {
    if (NULL == node) {return;}
    inorder_node(node->left, c);
    printf("%d: %d\n", node->item, count(c,node->item));
    inorder_node(node->right, c);
}


// see count.h for details
void stats(Count c){
    inorder_node(c->node, c);
}


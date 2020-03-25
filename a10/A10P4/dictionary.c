// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 10, Problem 4
// File: dictionary.c
// ====================================================
//

#include "dictionary.h"
#include <stdlib.h>
#include <assert.h>


// A Binary Search Tree Node (bstnode)
struct bstnode{
    void *key;
    void *value;
    struct bstnode *left;
    struct bstnode *right;
};


struct dictionary{
    struct bstnode *root;
    CompareFunction key_compare;
    FreeFunction free_key;
    FreeFunction free_value;
};


// make_bstnode() creates a new bstnode
// effects: allocates a struct on the heap that must be free by client
// time: O(1)
struct bstnode *make_bstnode(void){
    struct bstnode *new_node = malloc(sizeof(struct bstnode));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


// see dictionary.h for details
Dictionary create_Dictionary(CompareFunction comp_k, FreeFunction free_k, FreeFunction free_v){
    assert(comp_k);
    assert(free_k);
    assert(free_v);
    Dictionary new_dict = malloc(sizeof(struct dictionary));
    new_dict->key_compare = comp_k;
    new_dict->free_key = free_k;
    new_dict->free_value = free_v;
    return new_dict;
}


// destroy_bst is a helper function for destroy_Dictionary
// see dictionary.h for documentation
// recursively frees each node in the provided BST along with
// freeing each nodes key and value
// requires: dict is a valid Dictionary (not NULL)
// time: O(n * f), where n is the number of items in Dictionary,
//         f is time to free key & value
// effects: provided node will no longer be valid
void destroy_bst(struct bstnode **node, Dictionary dict){
    assert(dict);
    if (NULL == *node) {return;}
    destroy_bst(&(*node)->left, dict);
    destroy_bst(&(*node)->right, dict);
    dict->free_key(*node);
    dict->free_value(*node);
    free(*node);
}


// see dictionary.h for details
void destroy_Dictionary(Dictionary dict){
    assert(dict);
    destroy_bst(&dict->root, dict);
    free(dict);
}


// insert_bst(**node, dict, k, v) helper function for insert
// see dictionary.h for documentation
// inserts a value into the BST. If the key already exists, the previous
// value will be freed and the value for k will be replaced with v.
// requires: dict, k, v are valid (not NULL)
//           node poinst to a valid BST
// time: O(h * c + f), where h is height of underlying BST,
//         c is time to compare two keys,
//         and f is the time to free the previous value (if necessary)
// effects: modifies the BST provided, inserting a new value into the BST
//          if k already existed, the previous value will be freed.
void insert_bst(struct bstnode **node, Dictionary dict, void *k, void *v){
    assert(dict);
    assert(k);
    assert(v);
    if ((*node) != NULL) {
        int result = dict->key_compare(k, (*node)->key);
        if (result < 0) {
            insert_bst(&(*node)->left, dict, k, v);
        }else if (result > 0){
            insert_bst(&(*node)->right, dict, k, v);
        }else{ // key found
            dict->free_value((*node)->value);
            (*node)->value = v;
        }
    }else{ // key is NULL
        *node = make_bstnode();
        (*node)->key = k;
        (*node)->value = v;
    }
}


// see dictionary.h for details
void insert(Dictionary dict, void *k, void *v){
    assert(dict);
    assert(k);
    assert(v);
    insert_bst(&dict->root, dict, k, v);
}


// see dictionary.h for details
void *lookup(Dictionary dict, void *k){
    assert(dict);
    assert(k);
    struct bstnode *t = dict->root;
    while (t) {
        int result = dict->key_compare(k, t->key);
        if (result < 0) {
            t = t->left;
        }else if (result > 0){
            t = t->right;
        }else{ // key found
            return t->value;
        }
    }
    return NULL;
}






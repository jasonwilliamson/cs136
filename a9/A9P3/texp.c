// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 09, Problem 3
// File: texp.c
// ====================================================
//

#include "texp.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//see texp.h for documentation
struct enode *newnode(void) {
    struct enode *t=malloc(sizeof(struct enode));
    t->left=NULL;
    t->right=NULL;
    return t;
}

//see texp.h for documentation
void destroy_tree(struct enode *t){
    if (NULL == t) {return;}
    destroy_tree(t->left);
    destroy_tree(t->right);
    free(t);
}



//YOUR IMPLEMENTATION STARTS HERE



// eval(t) evaluates the arithmetic expression stored in t
//   requires: t is a valid arithmetic expression
//   time: O(n) where n in the number of nodes in t.
int eval(struct enode *t){
    
    if ((t->op) && (t->left != NULL) && (t->right != NULL)) {

        if (t->op == '+') {
            return (eval(t->left) +  eval(t->right));
        }else if (t->op == '-'){
            return (eval(t->left) -  eval(t->right));
        }else if (t->op == '/'){
            return (eval(t->left) /  eval(t->right));
        }else{
            return (eval(t->left) *  eval(t->right));
        }
        
    }else{

        return t->arg;
    }
}






void add_nodes(struct enode *parent){
    parent->left = newnode();
    parent->right = newnode();
}



void create_etree(struct enode *parent, struct enode *current, char c[],
                   struct enode **token){
    assert(c);
    if (*c) {

        if ('(' == *c) {
            add_nodes(current);
            ++c;
            if ((*c) && (('0' <= *c) && ('9' >= *c))){
                current->left->arg = (*c - '0');
                ++c;
                create_etree(parent, current, c, token);
            }else{
                create_etree(current, current->left, c, token);
               
            }
        } else if (('+' == *c) || ('-' == *c) ||
                   ('*' == *c) || ('/' == *c)){
            current->op = *c;
            *token = parent;
            ++token;
            ++c;
            if ((*c) && (('0' <= *c) && ('9' >= *c))){
                current->right->arg = (*c - '0');
                ++c;
                create_etree(parent, current, c, token);
            }else{
                create_etree(current, current->right, c, token);
            }
        } else if (')' == *c){
            ++c;
            --token;
            create_etree(*token, parent, c, token);
        }
    }
}




// build_tree(c) produces an expression tree for the expression in c
//   requires: c is a valid fully parenthesized expression, null terminated
//   effects:  a new tree representing the expression c is allocated
//   time: O(n) where n is the length of c
struct enode *build_tree(char c[]){
    
    struct enode *root = newnode();
    struct enode **token = malloc(sizeof(struct enode *) *100);
    
    create_etree(NULL, root, c, token);
    printf("root->op == %c \n", root->op);
    return root;
    
}


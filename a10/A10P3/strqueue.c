// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 10, Problem 3
// File: strqueue.c
// ====================================================
//

#include "strqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// A linked list node (llnode)
struct llnode {
    struct llnode *next;
    char *str;
};


struct strqueue{
    struct llnode *front;
    struct llnode *back;
    int length;
};


// see strqueue.h for details
StrQueue create_StrQueue(void){
    StrQueue new_q = malloc(sizeof(struct strqueue));
    new_q->front = NULL;
    new_q->back = NULL;
    new_q->length = 0;
    return new_q;
}


// see strqueue.h for details
void destroy_StrQueue(StrQueue sq){
    assert(sq);
    while (sq->length > 0) {
        char *str = sq_remove_front(sq);
        free(str);
    }
    free(sq);
}


// see strqueue.h for details
void sq_add_back(StrQueue sq, const char *str){
    assert(sq);
    assert(str);
    // get str's length
    int len = 0;
    char *tmp = (char *)str;
    while (*tmp) {
        ++len;
        ++tmp;
    }
    // copy str contents into new_node->str
    struct llnode *new_node = malloc(sizeof(struct llnode));
    new_node->str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i) {
        new_node->str[i] = *((char *)str);
        ++str;
    }
    // is at the back .. no next
    new_node->next = NULL;
    
    // if strqueue is empty new node is
    // both front and back
    if (0 == sq->length) {
        sq->back = new_node;
        sq->front = new_node;
    }else{
        sq->back->next = new_node;
        sq->back = new_node;
    }
    sq->length += 1;
}


// see strqueue.h for details
char *sq_remove_front(StrQueue sq){
    assert(sq);
    if (0 == sq->length) {
        return NULL;
    }else{
        char *tmp_str = sq->front->str;
        if (1 == sq->length){
            free(sq->front);
            sq->back = NULL;
        }else{
            struct llnode *tmp_node = sq->front->next;
            free(sq->front);
            sq->front = tmp_node;
        }
        sq->length -= 1;
        return tmp_str;
    }
}


// see strqueue.h for details
int sq_length(StrQueue sq){
    assert(sq);
    return sq->length;
}
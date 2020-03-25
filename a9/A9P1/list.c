// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 09, Problem 1
// File: list.c
// ====================================================
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// see list.h for documentation
struct llist *create_list(void) {
    struct llist *lst = malloc(sizeof(struct llist));
    lst->front = NULL;
    lst->back = NULL;
    lst->length = 0;
    return lst;
}

// see list.h for documentation
void destroy_list(struct llist *lst) {
    assert(lst);
    struct llnode *current = lst->front;
    struct llnode *next;
    while (current != NULL) {
        next = current->next; // note the next pointer
        free(current); // delete the node
        current = next; // advance to the next node
    }
    free(lst);
}


// see list.h for documentation
int list_length(struct llist *lst) {
    return lst->length;
}


// see list.h for documentation
void print_list(struct llist *lst) {
    struct llnode *current;
    for (current = lst->front; current != NULL; current = current->next)
        printf("  %d", current->item);
    printf("\n");
}

// YOUR IMPLEMENTATION STARTS HERE


// see list.h for documentation
void add_to_front(int n, struct llist *lst){
    assert(lst);
    int bytes = sizeof(struct llnode);
    struct llnode *new_front = malloc(bytes);
    new_front->item = n;
    
    // check is lst is empty
    if (0 == lst->length) {
        // lst is empty so node is both back and front
        lst->back = new_front;
    }else{
        // next is now what used to be the front
        new_front->next = lst->front;
    }
    lst->front = new_front;
    lst->length += 1;
}


// see list.h for documentation
void add_to_back(int n, struct llist *lst){
    assert(lst);
    int bytes = sizeof(struct llnode);
    struct llnode *new_back = malloc(bytes);
    new_back->item = n;
    new_back->next = NULL;
    
    if (0 == lst->length) {
        // lst is empty so node is both back and front
        lst->front = new_back;
    }else{
        // Assign new back to old back's next
        lst->back->next = new_back;
    }
    lst->back = new_back;
    lst->length += 1;
}


// see list.h for documentation
int delete_from_front(struct llist *lst){
    assert(lst);
    struct llnode *front = lst->front;
    int val = front->item;
    lst->front = front->next;
    free(front);
    lst->length -= 1;
    return val;
}


// see list.h for documentation
int get_nth(struct llist *lst, int index){
    assert(lst);
    int len = list_length(lst);
    assert(len > index);
    int incr = 0;
    struct llnode *current = lst->front;
    while (incr < index) {
        current = current->next;
        ++incr;
    }
    return current->item;
}


// see list.h for documentation
void insert_nth(struct llist *lst, int index, int data){
    assert(lst);
    int incr = 0;
    struct llnode *current = lst->front;
    while (incr < (index - 1)) {
        current = current->next;
        ++incr;
    }

    if (0 == index) {
        add_to_front(data, lst);
    }else if (index == lst->length){
        add_to_back(data, lst);
    }else{
        int bytes = sizeof(struct llnode);
        struct llnode *new = malloc(bytes);
        new->item = data;
        // set new to point to node in current position
        new->next = current->next;
        // assign new to be next @ (index -1)
        current->next = new;
        lst->length += 1;
    }
}


// see list.h for documentation
void lst_append(struct llist *lst1, struct llist *lst2){
    assert(lst1);
    assert(lst2);
    lst1->back->next = lst2->front;
    lst1->back = lst2->back;
    lst1->length += lst2->length;
    lst2->front = NULL;
    lst2->back = NULL;
    lst2->length = 0;
}


// see list.h for documentation
bool eq_list(struct llist *lst1, struct llist *lst2){
    assert(lst1);
    assert(lst2);
    if (lst1->length == lst2->length) {
        struct llnode *current_lst1 = lst1->front;
        struct llnode *current_lst2 = lst2->front;
        while (current_lst1) {
            if (current_lst1->item != current_lst2->item) {
                return false;
            }
            current_lst1 = current_lst1->next;
            current_lst2 = current_lst2->next;
        }
        return true;
        
    }else{
        return false;
    }
}


// see list.h for documentation
int maxminlist(struct llist *lst, int *max, int *min){
    assert(lst);
    if (lst->length > 0) {
        struct llnode *cur = lst->front;
        *max = cur->item;
        *min = cur->item;
        while (cur) {
            if (*max < cur->item) {
                *max = cur->item;
            }
            
            if (*min > cur->item) {
                *min = cur->item;
            }
            cur = cur->next;
        }
        return 1;
    }else{
        // lst is empty
        return 0;
    }
}


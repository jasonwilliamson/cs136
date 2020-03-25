#include <stdio.h>
#include <assert.h>
#include "texp.h"

int main(void){
    struct enode *t1;
    char e1[100];
    for (int i=0; i<1; i++){
        scanf("%s", e1);
        t1=build_tree(e1);
        //printf("root? %c\n", t1->op);
        printf("%d\n",eval(t1));
        //traverse_inorder(t1);
        //destroy_tree(t1);
    }
    
    return 0;
}

/*

 // push(s, i) puts item i on top of the stack
 // NOTE: The caller should not free the item until it is popped 
 void push(Stack s, void *i);
 // top(s) returns the top but does not pop it
 // NOTE: The caller should not free the item until it is popped 
 void *top(Stack s);
 // pop(s) removes the top item and returns it
 //   NOTE: The caller is responsible for freeing the item
 void *pop(Stack s);
 // destroy_Stack(s) destroys the stack
 // requires:_The stack must be empty (all items popped)
 void destroy Stack(Stack s);

*/
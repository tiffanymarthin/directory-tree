/**
 * Stack of tree node data structure header file
 */

#ifndef STACK_H 
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#include "linkedlist.h"

typedef struct stack Stack;

// Linked list as the underlying data structure of the stack
struct stack {
    LL_Node* top;
};

/****** Stack Implementation ******/

// Create an empty Stack
Stack* CreateStack();

// Push specified tree node on top of the Stack
void Push(Stack* stack_data, TreeNode* n);

// Pop the top tree node from top of the Stack
TreeNode* Pop(Stack* stack_data);

// See the top tree node from Stack without removal
TreeNode* PeekTop(Stack* stack_data);

// Destroy the Stack
Stack* DestroyStack(TreeNode* n);


#endif

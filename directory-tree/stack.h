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

// Queue implementation using linked list
struct stack {
    LL_Node* top;
};

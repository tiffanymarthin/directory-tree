/**
 * Stack of tree node data structure implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

/********** Stack Implementation **********/

// Create an empty stack
Stack *CreateStack()
{
    Stack *stack_data = (Stack *)malloc(sizeof(Stack));
    stack_data->top = NULL;
    return stack_data;
}

// Add the specified tree node to the top of the stack
void Push(Stack *stack_data, TreeNode *n)
{
    LL_Node *nodeToPush = CreateLLNode(n);
    LL_Node *l = AddFirst(stack_data->top, nodeToPush);
    stack_data->top = l;
}

// Remove and returns the tree node from the top of the stack
TreeNode *Pop(Stack *stack_data)
{
    if (stack_data->top == NULL)
        return NULL;
    TreeNode *top = stack_data->top->data;
    LL_Node *l = stack_data->top;
    LL_Node *tmp = l->next;
    stack_data->top = tmp;
    free(l);
    return top;
}

// Returns the tree node at the top of the stack
// Without removal
TreeNode *PeekTop(Stack *stack_data)
{
    if (stack_data->top == NULL)
        return NULL;
    return stack_data->top->data;
}

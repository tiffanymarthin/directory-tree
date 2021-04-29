/**
 * Header file for linked_list.c
 */

#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

typedef struct treeNode TreeNode;
typedef struct ll_node LL_Node;

// Linkedlist node struct
struct ll_node{
    TreeNode* data;
    LL_Node* next;
};

/****** Linked List Method Implementation ******/

// Create a linked list node based on specified tree node
LL_Node* CreateLLNode(TreeNode* data);

// Add the specified node to the beginning of linked list
LL_Node* AddFirst(LL_Node* head, LL_Node* nodeToAdd);

// Add the specified node to the end of linked list
LL_Node* AddLast(LL_Node* head, LL_Node* nodeToAdd);

// Remove the first linked list node in the linked list
LL_Node* RemoveFirst(LL_Node* head);

// Checks if linked list node is empty
int isEmpty(LL_Node* nodes);


#endif

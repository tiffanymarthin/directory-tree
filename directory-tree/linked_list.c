/**
 * Program to implement linked list data structure
 */

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

/****** Linked List Node Implementation ******/

// Create a linked list node based on specified tree node
// Node.next will start with pointing to null
LL_Node* CreateLLNode(TreeNode* data) {
    LL_Node* node = (LL_Node*)malloc(sizeof(LL_Node));

    node->data = data;
    node->next = NULL;

    return node;
}

// Add specified node to the beginning of specified linked list
LL_Node* AddFirst(LL_Node* head, LL_Node* nodeToAdd) {
    nodeToAdd->next = head;
    return nodeToAdd;
}


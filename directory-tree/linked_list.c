/**
 * Program to implement linked list data structure
 */

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

/****** Linked List Node Implementation ******/

// Create a linked list node based on specified tree node
// Node.next will start with pointing to null
// Return: The new linked list node
LL_Node* CreateLLNode(TreeNode* data) {
    LL_Node* node = (LL_Node*)malloc(sizeof(LL_Node));

    node->data = data;
    node->next = NULL;

    return node;
}

// Add specified node to the beginning of specified linked list
// Return: The updated linked list head
LL_Node* AddFirst(LL_Node* head, LL_Node* nodeToAdd) {
    nodeToAdd->next = head;
    return nodeToAdd;
}

// Add specified node to the end of specified linked list
// Return: The updated linked list head
LL_Node* AddLast(LL_Node* head, LL_Node* nodeToAdd) {
    if (head == NULL) {
        return nodeToAdd;
    }

    LL_Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = nodeToAdd;
    return head;
}

// Remove the first element of specified linked list 
// Return: The updated linked list head
LL_Node* RemoveFirst(LL_Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    LL_Node* tmp = head->next;
    DestroyTreeNode(head->data);
    free(head);
    return tmp;
}

// Checks if the specified linked list is empty
// Return: 1 if linked list is empty, 0 otherwise
int IsEmpty(LL_Node* head){
    return head == NULL;
}

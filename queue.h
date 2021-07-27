/**
 * Header file for queue.c
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "linked_list.h"

typedef struct queue Queue;

// Queue struct
struct queue
{
    LL_Node *head;
    int size;
};

/****** Queue Method Implementation ******/

// Create an empty Queue
Queue *CreateQueue();

// Add a TreeNode to the back of the Queue
void Enqueue(Queue *q, TreeNode *tn);

// Remove the head of the Queue
TreeNode *Dequeue(Queue *q);

// Returns the head of the Queue without removal
TreeNode *Peek(Queue *q);

// Destroy the specified Queue
void DestroyQueue(TreeNode *head);

// Gets the size of the queue
int Size(Queue *q);

#endif

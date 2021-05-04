/**
 * Queue data structure implementation
 */

#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

/****** Queue Implementation ******/
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->size = 0;
    return q;
}

void Enqueue(Queue* q, TreeNode* n) {
    LL_Node* nodeToEnq = CreateLLNode(n);
    LL_Node* l = AddLast(q->head, nodeToEnq);
    q->head = l;
    q->size += 1;
}

TreeNode* Dequeue(Queue* q) {
    if (q->head == NULL) return NULL;
    TreeNode* head = q->head->data;
    LL_Node* l = q->head;
    LL_Node* tmp = l->next;

    q->head = tmp;
    free(l);
    q->size -= 1;
    return head;
}

TreeNode* Peek(Queue* q) {
    if (q->head == NULL) return NULL;
    return q->head->data;
}

int Size(Queue* q) {
    return q->size;
}


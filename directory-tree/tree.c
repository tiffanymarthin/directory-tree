/**
 * N-ary tree data structure implementation
 */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<wchar.h>
#include<string.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

/****** Tree Implementation ******/

// Create a tree
Tree* CreateTree(TreeNode* root) {
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->root = root;
    return new_tree;
}

// Destroy tree using BFS traversal
void DestroyTree(TreeNode* root) {
    if (root->children == NULL) {
        free(root);
        return;
    }

    Queue* q = CreateQueue();
    Enqueue(q, root);

    while (q->head != NULL) {
        int level_len = Size(q);
        int i;
        for (i = 0; i < level_len; i++) {
            TreeNode* node = Dequeue(q);

            // Add current level to queue
            TreeNode* tmp; 
            if (node->children != NULL) {
                tmp = node->children;
                Enqueue(q, tmp);
            }
            while (tmp->siblings != NULL) {
                Enqueue(q, tmp->siblings);
                tmp = tmp->siblings;
            }
            // Root node does not put path and name in heap
            if (node->level > 0) free(node->path);
            if (node->level > 0) free(node->name);
            free(node);
        }
    }
    free(q);
}

/****** Tree Node Implementation ******/
 
// Create a tree node using specified path and name
TreeNode* CreateTreeNode(char* path, char* name) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->path = path;
    newNode->name = name;

    newNode->children = NULL;
    newNode->siblings = NULL;
    newNode->level = 0;
    return newNode;
}

// Add specified node as the node's child
void AddChild(TreeNode* root, TreeNode* nodeToAdd) {
    TreeNode* temp = root->children;
    int root_level = root->level;

    if (root->children == NULL) {
        root->children = nodeToAdd;
        root->children->level = root_level + 1;
    } else {
        int root_level = root->level;
        while (temp->siblings != NULL) {
            temp = temp->siblings;
        }
        temp->siblings = nodeToAdd;
        temp->siblings->level = root_level + 1;
    }
}

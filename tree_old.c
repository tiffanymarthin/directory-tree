/* 
 * Copyright (C) March 2020 Tiffany Marthin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited

/**
 * N-ary tree data structure implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

/****** Tree Implementation ******/

// Create a tree
Tree *CreateTree(TreeNode *root)
{
    Tree *new_tree = (Tree *)malloc(sizeof(Tree));
    new_tree->root = root;
    return new_tree;
}

// Destroy tree using BFS traversal
void DestroyTree(TreeNode *root)
{
    if (root->children == NULL)
    {
        free(root);
        return;
    }

    Queue *q = CreateQueue();
    Enqueue(q, root);

    while (q->head != NULL)
    {
        int level_len = Size(q);
        int i;
        for (i = 0; i < level_len; i++)
        {
            TreeNode *node = Dequeue(q);

            // Add current level to queue
            TreeNode *tmp;
            if (node->children != NULL)
            {
                tmp = node->children;
                Enqueue(q, tmp);
            }
            while (tmp->siblings != NULL)
            {
                Enqueue(q, tmp->siblings);
                tmp = tmp->siblings;
            }
            // Root node does not put path and name in heap
            if (node->level > 0)
            {
                free(node->path);
                free(node->name);
            }
            free(node);
        }
    }
    free(q);
}

/****** TreeNode Implementation ******/

// Create a TreeNode using specified path and name
TreeNode *CreateTreeNode(char *path, char *name)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->path = path;
    newNode->name = name;

    newNode->children = NULL;
    newNode->siblings = NULL;
    newNode->level = 0;
    return newNode;
}

// Add specified node as the root's child
void AddChild(TreeNode *root, TreeNode *nodeToAdd)
{
    int root_level = root->level;
    nodeToAdd->level = root_level + 1;

    if (root->children == NULL)
    {
        root->children = nodeToAdd;
        // root->children->level = root_level + 1;
    }
    else
    {
        TreeNode *temp = root->children;
        while (temp->siblings != NULL)
        {
            temp = temp->siblings;
        }
        temp->siblings = nodeToAdd;
    }
}

// Destroy specified TreeNode
void DestroyTreeNode(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    free(node->path);
    free(node->name);
    free(node);
}

// Color helper functions to print tree in colors
void pink()
{
    printf("\033[1;95m");
}

void green()
{
    printf("\033[1;32m");
}

void reset()
{
    printf("\033[0m");
}
/*
 * PrintTree function uses simple formatting
 * with indentations and colors
 * TODO: improve visuals using unicode printing
 */

void PrintTree(TreeNode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        exit(1);
    }

    Stack *tmp_stack = CreateStack();
    TreeNode *curr = root;

    while (tmp_stack->top != NULL || curr != NULL)
    {
        if (curr != NULL)
        {
            Push(tmp_stack, curr);
            int dash_ct = curr->level;
            if (curr->level == 0)
                printf(".\n");
            else
            {
                printf("|");
                while (dash_ct > 0)
                {
                    printf("--");
                    dash_ct--;
                }
                // Print with different colors according to file types
                // For folders, use green
                if (curr->children != NULL)
                {
                    green();
                    printf(" %s\n", curr->name);
                    reset();
                    // For files with no .c, use pink
                }
                else if (strchr(curr->name, '.') == NULL)
                {
                    pink();
                    printf(" %s\n", curr->name);
                    reset();
                }
                else
                {
                    printf(" %s\n", curr->name);
                }
            }
            curr = curr->children;
        }
        else
        {
            TreeNode *node = Pop(tmp_stack);
            curr = node->siblings;
        }
    }
    free(tmp_stack);
}

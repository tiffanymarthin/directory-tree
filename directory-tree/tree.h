/**
 * Tree data structure header file
 */
#ifndef TREE_H
#define TREE_H

#include<stdio.h>
#include<stdlib.h>


typedef struct treeNode TreeNode;

// Tree node struct
struct treeNode{
      char* path;
      char* name;
      TreeNode* children;
      TreeNode* siblings;
      int level;
};

typedef struct tree Tree;

// Tree struct
struct tree{
      TreeNode* root;
};

/****** Tree Implementation ******/

// Create a tree with specified tree node as root
Tree* CreateTree(TreeNode* root);

// Destroy specified tree
void DestroyTree(TreeNode* root);

/****** Tree node Implementation ******/
// Create a tree node, using specified path and name
TreeNode* CreateTreeNode(char* path, char* name);

// Add a child to the specified tree node
void AddChild(TreeNode* root, TreeNode* nodeToAdd);

// Destroy specified tree node
void DestroyTreeNode(TreeNode* root);

// Print the specified tree
void PrintTree(TreeNode* root);

#endif

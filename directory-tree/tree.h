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

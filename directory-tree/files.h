/**
 * Header file for files.c
 */

#ifndef FILES_H
#define FILES_H
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

// Helper function to print the directory file and folder counts
void PrintDirectoryCounts(int *directory_count, int *file_count);

void BuildDirectoryTree(TreeNode *rootNode, int *dir_ct, int *file_ct);

#endif
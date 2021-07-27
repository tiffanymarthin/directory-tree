/* 
 * Copyright (C) March 2020 Tiffany Marthin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 */

/*
 * Main program to build the directory file tree and print the directory files
 */

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>
#include "files.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"

int main()
{
    char *dir = ".";
    TreeNode *rootNode = CreateTreeNode(dir, "");
    int *dir_ct = (int *)malloc(sizeof(int));
    int *file_ct = (int *)malloc(sizeof(int));
    BuildDirectoryTree(rootNode, dir_ct, file_ct);

    // Print the tree and the stats
    setlocale(LC_ALL, "");
    PrintTree(rootNode);
    PrintDirectoryCounts(dir_ct, file_ct);

    DestroyTree(rootNode);
    free(dir_ct);
    free(file_ct);

    return 0;
}
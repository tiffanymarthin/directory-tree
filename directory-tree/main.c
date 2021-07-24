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
#include "queue.h"
#include "stack.h"
#include "tree.h"

// Helper function to print the directory file and folder counts
void PrintDirectoryCounts(int directory_count, int file_count)
{
    printf("\n%d ", directory_count);
    (directory_count > 1) ? printf("directories, ") : printf("directory, ");
    printf("%d ", file_count);
    (file_count > 1) ? printf("files\n") : printf("file\n");
}

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>
#include "queue.h"
#include "tree.h"
#include "files.h"

// Helper function to print the directory file and folder counts
void PrintDirectoryCounts(int *directory_count, int *file_count)
{
    int dir_ct = *directory_count;
    int file_ct = *file_count;
    printf("\n%d ", dir_ct);
    (dir_ct > 1) ? printf("directories, ") : printf("directory, ");
    printf("%d ", file_ct);
    (file_ct > 1) ? printf("files\n") : printf("file\n");
}

void BuildDirectoryTree(TreeNode *rootNode, int *dir_ct_var, int *file_ct_var)
{
    // Starts from the current directory
    char *dir;
    struct stat s;

    // Counter for directories and files
    int dir_ct = 0;
    int file_ct = 0;

    // Create a root node
    // TreeNode *rootNode = CreateTreeNode(dir, "");

    // Create a Queue with rootNode
    // This Queue will be used to build the tree
    Queue *q = CreateQueue();
    Enqueue(q, rootNode);

    // Building the tree using BFS
    while (q->head != NULL)
    {
        struct dirent **namelist;
        int num_files;

        TreeNode *currNode = Dequeue(q);
        // Concat the path with parent's folder path
        if (currNode->name != "")
        {
            char newdir[80];
            strcpy(newdir, currNode->path);
            strcat(newdir, "/");
            strcat(newdir, currNode->name);
            dir = newdir;
        }

        // Uses scandir to go through the files in the directory
        num_files = scandir(dir, &namelist, 0, alphasort);

        // Checks if there is any file
        if (num_files < 0)
        {
            perror("scandir");
            printf("dir: %s\n", dir);
            break;
        }

        // Adding each file/folder to the tree
        int i = 0;
        while (i < num_files)
        {
            // Ignore dotfiles
            if (namelist[i]->d_name[0] == '.')
            {
                free(namelist[i]);
                i++;
                continue;
            }

            char *directory;
            char *path;
            char *filename;

            int length = strlen(dir) + strlen(namelist[i]->d_name);
            int path_len = strlen(dir);
            int filename_len = strlen(namelist[i]->d_name);

            directory = (char *)malloc(((length + 3) * sizeof(char)));
            path = (char *)malloc(((path_len + 3) * sizeof(char)));
            filename = (char *)malloc(((filename_len + 3) * sizeof(char)));

            if (directory == NULL)
            {
                printf("Couldn't malloc for filecrawler.directory\n");
                return;
                exit(1);
            }

            // Copy path and filename into malloc'd strings
            snprintf(directory, length + 3, "%s/%s", dir, namelist[i]->d_name);
            snprintf(path, path_len + 3, "%s", dir);
            snprintf(filename, filename_len + 3, "%s", namelist[i]->d_name);

            // Create new node using the path and file name information
            TreeNode *newNode = CreateTreeNode(path, filename);

            // Add the node to the current rootnode
            AddChild(currNode, newNode);
            file_ct++;

            // Use stat() to get info about the given directory or file
            if (0 == stat(directory, &s))
            {
                // If it is a directory, then add to queue to be processed later
                // Update the file and folder counters
                if (S_ISDIR(s.st_mode))
                {
                    Enqueue(q, newNode);
                    dir_ct++;
                    file_ct--;
                }
            }
            // Free the followings as they are copied to malloc'd strings
            free(namelist[i]);
            free(directory);
            i++;
        }
        free(namelist);
    }
    free(q);
    *dir_ct_var = dir_ct;
    *file_ct_var = file_ct;
}